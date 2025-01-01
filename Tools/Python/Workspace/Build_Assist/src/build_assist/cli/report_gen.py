"""report_gen.py: Used to generate a pdf file containing relevant information about the most recent software build"""

__author__ = 'Dan Dustinta'
__copyright__ = "Copyright 2018, Autoliv Electronic"
__version__ = "2.0.3"
__email__ = 'dan.dustinta@autoliv.com'
__status__ = 'Released'

import os
import sys
from datetime import datetime
import yaml
import fpdf
import argparse
import re

currentDir = os.getcwd()
sys.path.append(currentDir)

def splitPtcVersion(inputLine):
    matchRet = re.search("(.*\.c|.*\.h|.*\.s)( [0-9\.\s]+.*)", inputLine)
    return matchRet

def formatPrintable(inputVar, indentLevel, recursive=False):
    retStr = ''
    indent = '   '
    if isinstance(inputVar, str) or isinstance(inputVar, int):
        retStr += '{}\n'.format(inputVar)
    elif isinstance(inputVar, list):
        if not recursive:
            retStr += '\n'
        for inst in inputVar:
            indentLevel += 1
            if isinstance(inst, list):
                retStr += '{}'.format(formatPrintable(inst, indentLevel, recursive=True))
            else:
                retStr += '{}{}\n'.format(indent*indentLevel, inst)
            indentLevel -= 1
    elif isinstance(inputVar, dict):
        retStr += '\n'
        for key, value in inputVar.items():
            indentLevel += 1
            if value:
                retStr += '{}{} = '.format(indent*indentLevel, key)
                if isinstance(value, dict):
                    retStr += '{}{}'.format(indent*indentLevel, formatPrintable(value, indentLevel))
                elif isinstance(value, list):
                    retStr += '{}{}'.format(indent*indentLevel, formatPrintable(value, indentLevel))
                else:
                    retStr += '{}\n'.format(value)
            else:
                retStr += '{}{}\n'.format(indent*indentLevel, key)
            indentLevel -= 1
    else:
        retStr += '\n'
        indentLevel += 1
        for x in vars(inputVar):
            retStr += '{}{}: {}'.format(indent*indentLevel, x, formatPrintable(getattr(inputVar, x), indentLevel=indentLevel))
        indentLevel -= 1
    return retStr

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-o', '--output-path', help="Pass the path of the output file", required=True)
    parser.add_argument('-p', '--ptc-project', help="Parse PTC Statistics file", type=bool, default=False, required=False)
    parser.add_argument('-s', '--ptc-sandbox', help="Parse PTC Statistics file", default=False, required=False)
    args = parser.parse_args()

    with open("report_config.yaml", 'r') as stream:
        try:
            report_config = yaml.load(stream, Loader=yaml.FullLoader)
        except yaml.YAMLError as exc:
            print(exc)

    pdfObj = fpdf.FPDF()

    pdfObj.add_page()
    pdfObj.set_font('Arial', style='B', size=14)
    try:
        pdfObj.write(5, 'Build Environment Report for {}.\n'.format(report_config['project_name']))
    except KeyError:
        pdfObj.write(5, 'Build Environment Report for .\n')

    pdfObj.set_font('Arial', size=13)
    pdfObj.write(5, 'Generated at {}\n\n'.format(datetime.now().strftime('%d.%m.%Y - %H:%M:%S')))


    pdfObj.set_font('Arial', size=12)

    if args.ptc_project or args.ptc_sandbox:
        print("Parsing PTC Statistics")
        ptc_statistics_file_str = os.path.normpath(os.path.join(currentDir, 'PTCStatistics.txt'))
        ptc_statistics_file = open(ptc_statistics_file_str, 'r')
        ptc_statistics_file = ptc_statistics_file.read()
        ptc_statistics_file = ptc_statistics_file.splitlines()

        for line in ptc_statistics_file:
            line = line.strip()

        if args.ptc_sandbox:
            ptc_statistics_file_parsed = []
            last_idx = 0
            for idx in range(0, len(ptc_statistics_file)):

                if args.ptc_sandbox not in ptc_statistics_file[idx]:
                    ptc_statistics_file_parsed[last_idx - 1] = ptc_statistics_file_parsed[last_idx - 1] + '\n' + ptc_statistics_file[idx].strip()
                else:
                    ptc_statistics_file_parsed.append(ptc_statistics_file[idx].strip())
                    last_idx += 1
        else:
            ptc_statistics_file_parsed = ptc_statistics_file

        for key, value in report_config.items():
            if isinstance(value, dict):
                if 'module_list' == key or 'module_header_list' == key:
                    for component, module_list in value['values'].items():
                        for module in module_list:
                            for ptc_stat in ptc_statistics_file_parsed:
                                fileStemGroup = splitPtcVersion(ptc_stat)
                                if fileStemGroup is not None:
                                    if os.path.split(fileStemGroup.group(1))[1].strip() in module.strip():
                                        value['values'][component][value['values'][component].index(module)] = module + ' ' + fileStemGroup.group(2)
                                        break

    for key, value in report_config.items():
        if isinstance(value, dict):
            pdfObj.set_font('Arial', style='B', size=13)
            pdfObj.write(5, '\n{}\n'.format(value['heading']))

            pdfObj.set_font('Arial', style='I', size=13)
            pdfObj.write(5, '{}'.format(value['description']))

            pdfObj.set_font('Arial', size=12)

            formatted_text = '{}'.format(formatPrintable(value['values'], indentLevel=0))

            pdfObj.write(5, formatted_text)

            pdfObj.write(5, '\n')

    if not os.path.isdir(os.path.dirname(args.output_path)):
        os.makedirs(os.path.dirname(args.output_path), exist_ok=True)

    pdfObj.output(os.path.normpath(args.output_path), 'F')

if __name__ == '__main__':
    main()
