"""ptc_tracker.py: Gathers information regarding all work-products in PTC"""

__author__ = 'Dan Dustinta'
__copyright__ = "Copyright 2018, Autoliv Electronic"
__version__ = "1.0.0"
__email__ = 'dan.dustinta@autoliv.com'
__status__ = 'Draft'

# ----- Modified by Ardeleanu Lucian, 06.04.2021 ----------------
# Changed module names on Design Interface Description.docx files
# Added lines : 182-200
# ---------------------------------------------------------------

import glob
import os
import ntpath
import sys
import subprocess
import io
import re
import argparse
import csv
from xlsxwriter.workbook import Workbook
import yaml

config_file = yaml.safe_load(open('ptc_tracker_config.yaml', 'r'))

currentDir = os.getcwd()
sys.path.append(currentDir)

ptc_view_project_cmd = "si viewproject --hostname=ALVA-MKS01 --port=7001 --password=jnk01 --user=Jenkins01 {project_revision} --project={ptc_project} --fields=indent,name,memberrev,state --confirmrecurse --yes"

def splitPtcVersion(inputLine):
    matchRet = re.search("(.*\.c|.*\.h|.*\.s|.*\.cfg|.*\.xlsx|.*\.xls|.*\.doc|.*\.docx)( [0-9\.\s]+)(.*)", inputLine)
    return matchRet

def run_command_str(commandStr):
    retStr = ''
    p = subprocess.Popen(commandStr, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

    for line in io.TextIOWrapper(p.stdout, encoding="utf-8"):
        line = line.strip()
        if line:
            retStr += '{}\n'.format(line)

    for line in io.TextIOWrapper(p.stderr, encoding="utf-8"):
        line = line.strip()
        if line:
            retStr += '{}\n'.format(line)

    return retStr

def path_leaf(path):
    head, tail = ntpath.split(path)
    return tail or ntpath.basename(head)

def main():

    parser = argparse.ArgumentParser()
    parser.add_argument('-m', '--module', help="pass the module that will be analyzed")
    args = parser.parse_args()

    project_statistics = {}

    for path in config_file['application_path']:
        if args.module is not None:
            component_list = os.listdir(path)
            if args.module in component_list:
                component_list = [args.module]
                csv_output_str = os.path.normpath(os.path.join(currentDir, "{}.csv".format(args.module)))
            else:
                raise Exception("{} was not found".format(args.module))
        else:
            component_list = os.listdir(path)
            csv_output_str = os.path.normpath(os.path.join(currentDir, "{}.csv".format(config_file['document_name'])))

        for component in component_list:

            # Initialize dictionary that holds all statistics
            if component not in project_statistics:
                project_statistics[component] = {}

            # Parse all source files
            search_lists = []
            search_lists.append(glob.iglob('{}/{}/Implementation/**/*.*'.format(path, component), recursive=True))
            search_lists.append(glob.iglob('{}/{}/Design/*DetailedDesign.docx'.format(path, component), recursive=True))
            search_lists.append(glob.iglob('{}/{}/Design/*Detailed Design Document.docx'.format(path, component), recursive=True))
            search_lists.append(glob.iglob('{}/{}/Quality_Assurance/Peer_Review/*Peer Review Workbook.xls'.format(path, component), recursive=True))
            search_lists.append(glob.iglob('{}/{}/Quality_Assurance/Static_Analysis/*.c_WarningReport.xlsx'.format(path, component), recursive=True))
            search_lists.append(glob.iglob('{}/{}/Quality_Assurance/Static_Analysis/*_Metrics.xlsx'.format(path, component), recursive=True))
            search_lists.append(glob.iglob('{}/{}/Tests/*_UnitTestReport.xlsx'.format(path, component), recursive=True))
            search_lists.append(glob.iglob('{}/{}/Tests/*_Software_Integration_Test_Specification_Report.xlsx'.format(path, component), recursive=True))

            for search_list in search_lists:
                for src_file in search_list:

                    if path_leaf(src_file) not in project_statistics[component]:
                        project_statistics[component][path_leaf(src_file)] = [
                            '',  # Version
                            '',  # State
                            '',  # Category
                        ]

            for ptc_project_stem in config_file['ptc_project_stems']:

                ret_str = run_command_str(ptc_view_project_cmd.format(ptc_project=os.path.normpath(os.path.join(ptc_project_stem.format(component))),
                                                                      project_revision=config_file['ptc_label']))

                ptc_statistics = []

                for line in ret_str.split("\n"):
                    ptc_statistics.append(line.strip())

                for ptc_stat in ptc_statistics:

                    file_stem_group = splitPtcVersion(ptc_stat)
                    if file_stem_group is not None:

                        ptc_found_file = os.path.split(file_stem_group.group(1))[1].strip()
                        ptc_found_file_version = file_stem_group.group(2).strip()
                        ptc_found_file_state = file_stem_group.group(3).strip()

                        if ptc_found_file in project_statistics[component]:
                            project_statistics[component][ptc_found_file][0] = ptc_found_file_version
                            project_statistics[component][ptc_found_file][1] = ptc_found_file_state
                            if 'WarningReport.xls' in ptc_found_file or \
                               'Metrics.xls' in ptc_found_file:
                                project_statistics[component][ptc_found_file][2] = "Static Analysis"
                            elif 'Integration_Test_Specification_Report.xls' in ptc_found_file:
                                project_statistics[component][ptc_found_file][2] = "Integration Test Report"
                            elif 'UnitTestReport.xls' in ptc_found_file:
                                project_statistics[component][ptc_found_file][2] = "Unit Test Report"
                            elif 'Peer Review Workbook.xls' in ptc_found_file:
                                project_statistics[component][ptc_found_file][2] = "Peer Review Workbook"
                            elif 'Detailed Design Document.doc' in ptc_found_file or 'DetailedDesign.doc' in ptc_found_file or 'Detailed Design Document.docx' in ptc_found_file:
                                project_statistics[component][ptc_found_file][2] = "Detailed Design"
                            elif '.c' or '.h' in ptc_found_file:
                                project_statistics[component][ptc_found_file][2] = "Source Code"
    # Parse all source files
    search_lists = []
    search_lists.append(glob.iglob('{}/*Design Interface Description.docx'.format(config_file['arch_application_paths'][0]), recursive=True))
    search_lists.append(glob.iglob(('{}/' + config_file['main_document_architecture']).format(config_file['arch_application_paths'][1]), recursive=True))

    for search_list in search_lists:
        for src_file in search_list:
            if path_leaf(src_file) not in project_statistics[component]:
                project_statistics[component][path_leaf(src_file)] = [
                    '',  # Version
                    '',  # State
                    '',  # Category
                ]

    for ptc_project_stem in config_file['arch_project_stems']:
        ret_str = run_command_str(ptc_view_project_cmd.format(ptc_project=os.path.normpath(os.path.join(ptc_project_stem)),
                                                              project_revision=config_file['ptc_label']))

        ptc_statistics = []

        for line in ret_str.split("\n"):
            ptc_statistics.append(line.strip())

        for ptc_stat in ptc_statistics:
            file_stem_group = splitPtcVersion(ptc_stat)
            if file_stem_group is not None:

                ptc_found_file = os.path.split(file_stem_group.group(1))[1].strip()
                ptc_found_file_version = file_stem_group.group(2).strip()
                ptc_found_file_state = file_stem_group.group(3).strip()

                if ptc_found_file in project_statistics[component]:
                    project_statistics[component][ptc_found_file][0] = ptc_found_file_version
                    project_statistics[component][ptc_found_file][1] = ptc_found_file_state
                    project_statistics[component][ptc_found_file][2] = "Architecture"

    # Interpret results
    csv_output_list = [[
        'Module',
        'File',
        'Revision',
        'State',
        'Category'
    ]]

    for module, all_stats in project_statistics.items():
        for file, stats in all_stats.items():
            if( 'Design Interface Description.docx' in file):
                module_name = file[0:file.index('-')]
                csv_output_list.append([
                    module_name,
                    file,
                    stats[0],
                    stats[1],
                    stats[2]
                ])
            elif ( 'SWarchitectureDesignInterfaceDescription.docx' in file):
                module_name = 'Main Document Architecture'
                csv_output_list.append([
                    module_name,
                    file,
                    stats[0],
                    stats[1],
                    stats[2]
                ])
            else:
                csv_output_list.append([
                    module,
                    file,
                    stats[0],
                    stats[1],
                    stats[2]
                ])


    with open(csv_output_str, 'w+', newline='') as f:
        writer = csv.writer(f)
        writer.writerows(csv_output_list)

    workbook = Workbook(csv_output_str[:-4] + '.xlsx')
    worksheet = workbook.add_worksheet()

    with open(csv_output_str, 'rt', encoding='utf8') as f:
        reader = csv.reader(f)
        for r, row in enumerate(reader):
            for c, col in enumerate(row):
                worksheet.write(r, c, col)

    print('Output Document: ' + csv_output_str)

    workbook.close()

if __name__ == '__main__':
    main()
