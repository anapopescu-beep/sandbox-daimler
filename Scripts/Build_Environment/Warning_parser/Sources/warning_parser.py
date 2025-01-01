"""warning_parser.py: Used to create statistics for Jenkins Integration"""

__author__ = 'Dan Dustinta'
__copyright__ = "Copyright 2018, Autoliv Electronic"
__version__ = "1.0.2"
__email__ = 'dan.dustinta@autoliv.com'
__status__ = 'Released'

#-----------------------------------------------------------------------
# Updated by Ardeleanu Lucian, 04.08.2020
# Added plots capability and function
#-----------------------------------------------------------------------

#-----------------------------------------------------------------------
# Updated by Ardeleanu Lucian, 05.10.2020
# Changed plots title
#-----------------------------------------------------------------------

#-----------------------------------------------------------------------
# Updated by Ardeleanu Lucian, 13.12.2021
# Added tasking functionality
#-----------------------------------------------------------------------

import argparse
import sys
import os
import glob
import re
from pathlib import Path

current_dir = os.getcwd()
sys.path.append(current_dir)


def plot_global_warning_stats(input_csv_path, output_plot_path, plot_title ):
    import csv
    from PIL import Image
    import matplotlib.pyplot as plt
    import numpy as np

#Initialise elements and lists used
    warning_value = []
    build_number = []
    date = []
    module_name = []
    build_number_and_date = []
    enumerate_rows = 0

    data_from_rows = []

#Open .csv file and append all data in a big list
    with open(input_csv_path, 'rt')as f:
        data = csv.reader(f)
        next(csv.reader(f))
        for row in data:
            enumerate_rows += 1
            data_from_rows.append(row)

#Replace empty elements with blank spaces
    for i in range(0, len(data_from_rows)):
        if len(data_from_rows[i]) == 1:
            data_from_rows[i].append(' ')
            data_from_rows[i].append(' ')

#Count in variable: enumerate_rows the last 100 elements used to plot ( we need to plot only last 100 elements from all global warning stats list )
    if len(data_from_rows) > 100:
        enumerate_rows = len(data_from_rows) - 100
    else:
        enumerate_rows = 0

    #List is sliced in multiple lists used to plot
    if (len(data_from_rows[0]) == 2):
        for i in range(0, len(data_from_rows)):
            module_name.append(data_from_rows[i][0])
            warning_value.append(data_from_rows[i][1])
    else:
        for i in range(enumerate_rows, len(data_from_rows)):
            warning_value.append(data_from_rows[i][0])
            build_number.append(data_from_rows[i][1])
            date.append(data_from_rows[i][2])
            build_number_and_date.append([])

    if (len(data_from_rows[0]) != 2):
        #Conversions are made for plotting
        for i in range(0, len(warning_value)):
            warning_value[i] = int(warning_value[i])

        for i in range(0, len(build_number)):
            build_number[i] = str(build_number[i])

        for i in range(0, len(date)):
            date[i] = str(date[i])

        for i in range(0, len(build_number)):
            build_number_and_date[i] = '#' + build_number[i] + ' ( ' + date[i] + ' ) '
    else:
        for i in range(0, len(module_name)):
            module_name[i] = str(module_name[i])

        for i in range(0, len(warning_value)):
            warning_value[i] = int(warning_value[i])

#Plot is created using data processed up
    bars = warning_value
    height = warning_value

    y_pos = np.arange(len(bars))
    plt.figure(figsize=(20, 10))
    plt.bar(y_pos, height)

    if (len(data_from_rows[0]) != 2):
        names = build_number_and_date
    else:
        names = module_name
    plt.xticks(y_pos, names, rotation=90)

    # Thus we have to give more margin:
    plt.subplots_adjust(bottom=0.4)

    # It's the same concept if you need more space for your titles
    plt.title(plot_title)
    plt.subplots_adjust(top=0.7)
    plt.savefig(output_plot_path)

    im = Image.open(output_plot_path)

    crop_rectangle = (200, 270, 1810, 800)  # left, top, right, bottom
    cropped_im = im.crop(crop_rectangle)

    newsize = (1450, 400)
    imresize = cropped_im.resize(newsize)

    im = imresize.save(output_plot_path)

def matchWarningForCosmic(inputLine):
    matchRet = re.match("(.*)(\s*[a-zA-Z]+:.*\.c|\.h)(\s*:[0-9]+:[0-9]+:\s*)(warning:.*)", inputLine)
    return matchRet

def matchWarningForIAR(inputLine):
    matchRet = re.match("(.*)(\s*[a-zA-Z]+:.*\.c|\.h)(..[0-9]*\s*)(Warning.*)", inputLine)
    return matchRet

def matchWarningForTASKING(inputLine):
    matchRet = re.search("\"(.*[ch])\"(\s\d*\W\d*\W\s)(.*)", inputLine)
    return matchRet

def get_base_path(path,folder):
    return path[0: path.find(folder)].replace('*','')

def get_wrong_part_of_path(path):

    # Split path in parts
    path_list = Path(path).parts

    # For every folder in given path
    path_to_extract = ''
    first_correct_folder = ''
    for folder in path_list:

        # If folder name containts only alphabetical letters
        if folder.isalpha():

            # Extract from path until that folder
            path_to_extract = path[0:path.find(folder)]

            # Extract first correct folder
            first_correct_folder = folder

            break


    # If extracted path is not empty
    if path_to_extract != '' and first_correct_folder != '' :

        # return it
        return path_to_extract, first_correct_folder

    # Otherwise, return a notification string
    else:
        print('No correct path found in ' + path)
        return path, first_correct_folder


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-w', '--warning-path', help="Path to the warning directory", required=True)
    parser.add_argument('-s', '--component-path', action='append', help="Path to the components directory", required=True)
    parser.add_argument('-l', '--component-level', action='append', help="Depth of the source file directory", type=int, required=True)
    parser.add_argument('-d', '--data', help="Data to fill in global_warning_stats.csv", required=False)
    parser.add_argument('-b', '--build-number', help="Build number to fill in global_warning_stats.csv", required=False)
    parser.add_argument('-o', '--output-path', help="Path to the output directory", required=True)


    args = parser.parse_args()

    components_to_ignore = ['NM_Dummy',
    'inc',
    'Quality_Assurance',
    'src',
    'Stub',
    'BswMAsExt_TS_TxDxM1I20R0',
    'BswMExt_TS_TxDxM1I15R0',
    'ComExt_TS_TxDxM6I3R0',
    'ComXfExt_TS_TxDxM1I0R0',
    'DiagApplTemplateExt_TS_TxDxM1I0R0',
    'DiagApplTemplate_TS_TxDxM1I0R0',
    'DiagDt_TS_TxDxM1I5R0',
    'DltExt_TS_TxDxM1I8R0',
    'dreisoft.tresos.fibeximporter',
    'dreisoft.tresos.generator.ng.api',
    'MemMapExt_TS_TxDxM1I3R0',
    'org.apache.ant_1.9.6.v201510161327',
    'org.eclipse.equinox.launcher.gtk.linux.x86_64_1.1.401.v20161122 - 1740',
    'org.eclipse.equinox.launcher.win32.win32.x86_64_1.1.401.v20161122 - 1740',
    'org.eclipse.platform_4.6.2.v20161124 - 1400',
    'org.eclipse.ui.themes_1.1.300.v20161107 - 1827',
    'PduRExt_TS_TxDxM5I3R0',
    'Scriptor_TS_TxDxM1I0R0',
    'SelectableWizardAsc_TS_TxDxM1I3R0',
    'ServiceApplTemplateExt',
    'ServiceApplTemplate_TS_TxDxM1I3R0',
    'SomeIpXfExt_TS_TxDxM1I0R0',
    'SomeIpXf_TS_TxDxM1I0R0',
    'Tools4VWAGPreConfigExt',
    'Tools4VWAG_TS_TxDxM1I1R0',
    'Tools4VWAG_TS_TxDxM1I2R0',
    'Workflows_ACGCanStack_TS_TxDxM2I3R0',
    'Workflows_ACGDefault',
    'Workflows_ACGFlexRayStack_TS_TxDxM2I3R0',
    'Workflows_ACGIPStack_TS_TxDxM2I3R0',
    'Workflows_ACGLinStack_TS_TxDxM2I3R0',
    'Workflows_ACGMemStack_TS_TxDxM2I3R0',
    'Workflows_ACGPostBuild_TS_TxDxM2I3R0',
    'Workflows_ACGRteMemProtSafety_TS_TxDxM2I3R0',
    'Workflows_ACGRteMemProt_TS_TxDxM2I3R0',
    'Workflows_ACGRte_TS_TxDxM2I3R0',
    'XfrmExt_TS_TxDxM1I0R0',
    'XGenerator_TS_TxDxM1I3R0',
    'doc',
    'include',
    'make',
    'orti',
    'output',
    'src_appl',
    'swcd',
    'swcd_calibration',
    'template',
    'templates',
    'xgen',
    'org.eclipse.equinox.launcher.gtk.linux.x86_64_1.1.401.v20161122-1740',
    'org.eclipse.equinox.launcher.win32.win32.x86_64_1.1.401.v20161122-1740',
    'org.eclipse.jdt.debug_3.10.1.v20160811-0441',
    'org.eclipse.pde.build_3.9.200.v20160204-0642',
    'org.eclipse.platform_4.6.2.v20161124-1400',
    'org.eclipse.ui.themes_1.1.300.v20161107-1827', ]

    # for path_idx in range(0, len(args.component_path)):
        # args.component_path[path_idx] = args.component_path[path_idx].lower()

    # Init a component list from given path
    component_list = []
    for path in args.component_path:
        component_list += glob.glob(path)

    # Init statistics dictionary
    statistics_dict = { 'global_statistics': { 'number_of_warnings': 0}, 'module_statistics': {} }

    # Add components in dictionary
    for component in component_list:
        statistics_dict['module_statistics'][os.path.basename(os.path.normpath(component))] = { 'number_of_warnings': 0 }

    # for every file in given path with warnings
    for file_name in glob.iglob(os.path.join(args.warning_path, '**', '*.warn'), recursive=True):

        # Open file
        file_obj = open(file_name, "r+")

        # Get all lines from warning file in a single string
        string_with_all_lines_from_file = file_obj.read()

        # If COSMIC compiler found in line
        if 'cxs12z.exe' in string_with_all_lines_from_file and 'cosmic' in string_with_all_lines_from_file.lower():

            # re-open file
            file_obj = open(file_name, "r+")

            for line in file_obj:

                # if warning found in line
                if 'warning:' in line:

                    # apply regex to extract source file path
                    warning_group = matchWarningForCosmic(line)

                    # if found source file
                    if warning_group is not None:

                        # Split it's path
                        path_to_source_file_listed = Path(warning_group.group(2)).parts

                        # Get component name
                        for path_idx in range(0, len(args.component_path)):
                            component_path_list = Path(args.component_path[path_idx]).parts

                            path_found = False
                            path_level = 0

                            for idx in range(0, len(component_path_list)):
                                if path_to_source_file_listed[idx].lower() != component_path_list[idx].lower():
                                    break

                                elif idx == len(component_path_list) - 2:
                                    path_found = True
                                    path_level = args.component_level[path_idx]

                            if path_found:
                                break

                        if not path_found:
                            print("Module not found: " + warning_group.group(2))

                        component_name_str = path_to_source_file_listed[len(component_path_list) - path_level - 2]

                        if component_name_str in statistics_dict['module_statistics']:
                            statistics_dict['module_statistics'][component_name_str]['number_of_warnings'] += 1
                            statistics_dict['global_statistics']['number_of_warnings'] += 1
                            if 'warnings' not in statistics_dict['module_statistics'][component_name_str]:
                                statistics_dict['module_statistics'][component_name_str]['warnings'] = set()
                                statistics_dict['module_statistics'][component_name_str]['warnings'].add(warning_group.group(4))
                            else:
                                statistics_dict['module_statistics'][component_name_str]['warnings'].add(warning_group.group(4))
                        else:
                            print(component_name_str + ' ' + warning_group.group(2))


        # If IAR compiler found in line
        elif 'iccarm.exe' in string_with_all_lines_from_file and 'iar' in string_with_all_lines_from_file.lower():

            # re-open file
            file_obj = open(file_name, "r+")

            for line in file_obj:

                # if Warning found in line
                if 'Warning' in line:

                    # apply regex to extract source file path
                    warning_group = matchWarningForIAR(line)

                    # if found source file
                    if warning_group is not None:

                        # Split it's path
                        path_to_source_file_listed = Path(warning_group.group(2)).parts

                        # Get component name of source file
                        # For every path in given path of component
                        for path_idx in range(0, len(args.component_path)):

                            # split component path into a list of paths
                            component_path_list = Path(args.component_path[path_idx]).parts

                            # Initialise indicators
                            path_found = False
                            path_level = 0

                            for idx in range(0, len(component_path_list)):

                                # If a first difference is found paths, then break
                                if path_to_source_file_listed[idx].lower() != component_path_list[idx].lower():
                                    break

                                elif idx == len(component_path_list) - 2:
                                    path_found = True
                                    path_level = args.component_level[path_idx]

                            if path_found:
                                break

                        if not path_found:
                            print("Module not found: " + warning_group.group(2))

                        try:
                            component_name_str = path_to_source_file_listed[len(component_path_list) - path_level - 2]
                        except:
                            component_name_str = warning_group.group(2)

                        if component_name_str in statistics_dict['module_statistics']:
                            statistics_dict['module_statistics'][component_name_str]['number_of_warnings'] += 1
                            statistics_dict['global_statistics']['number_of_warnings'] += 1
                            if 'warnings' not in statistics_dict['module_statistics'][component_name_str]:
                                statistics_dict['module_statistics'][component_name_str]['warnings'] = set()
                                statistics_dict['module_statistics'][component_name_str]['warnings'].add(warning_group.group(4))
                            else:
                                statistics_dict['module_statistics'][component_name_str]['warnings'].add(warning_group.group(4))
                        else:
                            print(component_name_str + ' ' + warning_group.group(2))

        # If TASKING compiler found in line
        elif 'cctc.exe' in string_with_all_lines_from_file and 'tasking' in string_with_all_lines_from_file.lower():

            # re-open file
            file_obj = open(file_name, "r+")

            # For every line in file_obj
            for line in file_obj:

                # if Warning found in line
                if 'ctc W' in line:

                    # # Extract path to source file from warning
                    # path_to_source_file = line [ line.index('["') + 2 : line.rindex('] ') ]
                    # path_to_source_file = path_to_source_file[0: path_to_source_file.find('"')]

                    # Get warning group from line
                    warning_group = matchWarningForTASKING(line)

                    # if found source file
                    if warning_group is not None:

                        # Get source file path from warning
                        path_to_source_file = warning_group.group(1)

                        # ------------- CORRECT PATH IF CONTAINS WRONG FOLDERS NAME, LIKE ../../ --------------------------

                        # if founded path contain wrong folder name in it
                        if '..' in path_to_source_file:

                            # Extrtact wrong part and first correct folder founded
                            wrong_part_of_path, first_correct_folder = get_wrong_part_of_path(path_to_source_file)

                            # Get basepath to first correct folder from components path
                            path_to_be_replaced = get_base_path(path=args.component_path[0], folder=first_correct_folder)

                            # Replace path in path of source file
                            path_to_source_file = path_to_source_file.replace(wrong_part_of_path, path_to_be_replaced )

                        # --------------------------------------------------------------------------------------------------

                        # Split it's path
                        path_to_source_file_listed = Path(path_to_source_file).parts

                        # Get component name of source file
                        # For every path in given path of component
                        for path_idx in range(0, len(args.component_path)):

                            # split component path into a list of paths
                            component_path_list = Path(args.component_path[path_idx]).parts

                            # Initialise indicators
                            path_found = False
                            path_level = 0

                            for idx in range(0, len(component_path_list)):

                                # If a first difference is found paths, then break
                                if path_to_source_file_listed[idx].lower() != component_path_list[idx].lower():
                                    break

                                elif idx == len(component_path_list) - 2:
                                    path_found = True
                                    path_level = args.component_level[path_idx]

                            if path_found:
                                break

                        if not path_found:
                            print("Module not found: " + path_to_source_file)

                        component_name_str = path_to_source_file_listed[len(component_path_list) - path_level - 2]

                        if component_name_str in statistics_dict['module_statistics']:
                            statistics_dict['module_statistics'][component_name_str]['number_of_warnings'] += 1
                            statistics_dict['global_statistics']['number_of_warnings'] += 1
                            if 'warnings' not in statistics_dict['module_statistics'][component_name_str]:
                                statistics_dict['module_statistics'][component_name_str]['warnings'] = set()
                                statistics_dict['module_statistics'][component_name_str]['warnings'].add(warning_group.group(3))
                            else:
                                statistics_dict['module_statistics'][component_name_str]['warnings'].add(warning_group.group(3))
                        else:
                            print(component_name_str + ' ' + path_to_source_file)


    # Open ( create module file )
    module_file_obj = open(os.path.normpath(os.path.join(args.output_path, 'module_warning_stats.csv')), "w+")
    module_file_obj.write('Module,No. Of Warnings\n')

    # Write data in module statistics
    for key, value in statistics_dict['module_statistics'].items():
        if key not in components_to_ignore and '_TS_' not in key:
            module_file_obj.write('{},{}\n'.format(key, statistics_dict['module_statistics'][key]['number_of_warnings']))

    # Create or open existing global file
    if not os.path.isfile(os.path.normpath(os.path.join(args.output_path, 'global_warning_stats.csv'))):
        global_file_obj = open(os.path.normpath(os.path.join(args.output_path, 'global_warning_stats.csv')), 'w+')
        global_file_obj.write('No. Of Warnings,Build Number,Data\n')
    else:
        global_file_obj = open(os.path.normpath(os.path.join(args.output_path, 'global_warning_stats.csv')), 'a+')

    # Write data in it
    if args.build_number is not None and args.data is not None:
        global_file_obj.write( '{},{},{}\n'.format(str(statistics_dict['global_statistics']['number_of_warnings']), args.build_number, args.data))
    else:
        global_file_obj.write('{}\n'.format(str(statistics_dict['global_statistics']['number_of_warnings'])))

    # Close both files
    global_file_obj.close()
    module_file_obj.close()

    # if arguments are given for date and build number
    if args.build_number is not None and args.data is not None:
        plot_global_warning_stats(input_csv_path=args.output_path + '\global_warning_stats.csv', output_plot_path= args.output_path + r'\Compiler_Warnings_per_Build_Number.png', plot_title='Compiler Warnings / Build Number' )
        plot_global_warning_stats(input_csv_path=args.output_path + '\module_warning_stats.csv', output_plot_path= args.output_path + r'\Compiler_Warnings_per_Module.png', plot_title='Compiler Warnings / Module')

if __name__ == '__main__':
    main()
