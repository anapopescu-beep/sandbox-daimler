"""aria_wrapper.py: Used to launch aria to compile and run automatic script"""

__author__ = 'Dan Dustinta'
__copyright__ = "Copyright 2018, Autoliv Electronic"
__version__ = "1.0.0"
__email__ = 'dan.dustinta@autoliv.com'
__status__ = 'Released'

import datetime
import argparse
import sys
import os
import io
import re
import subprocess
import time
from pathlib import Path
from PIL import ImageFont, ImageDraw, Image

currentDir = os.getcwd()
sys.path.append(currentDir)

xml_template = '''\
<?xml version='1.0' encoding='UTF-8'?>
<section name="{TestReportTitle}" fontcolor="#383838">
{fieldTemplate}
</section>'''

field_template = '''\
<field name="{TestName}: " titlecolor="{TestResultColour}" value="{TestResult}" detailcolor="#000000"  />'''

banned_words = [
    '''tcp://localhost:9998/CompilerSiteNo connection could be made because the target machine actively refused it [::1]:9998''',
    '''No connection could be made because the target machine actively refused it [::1]:9998''',
    '''Additional non-parsable characters are at the end of the string''',
    '''ARIA.exe>''',
    '''Empty path name is not legal.''',
    '''PP4G''',
    '''First request for security access failed - TIMEOUT received!''',
    '''The given path's format is not supported.''',
    '''SystemEvents_UserPreferenceChanged''',
    '''Retrieving the COM class factory for component with CLSID {DB8CBF1C-D6D3-11D4-AA51-00A024EE30BD} failed due to the following error: 80040154 Class not registered (Exception from HRESULT: 0x80040154 (REGDB_E_CLASSNOTREG)).''',
    '''Running tests from''',
    '''AriaConfigFiles2.27.1'''
]

strictly_banned_words = [
    '''Could not load file or assembly 'Configuration.XmlSerializers, Version=1.0.0.6, Culture=neutral, PublicKeyToken=null' or one of its dependencies. The system cannot find the file specified.''',
    '''Could not load file or assembly 'Configuration.XmlSerializers' or one of its dependencies. The system cannot find the file specified.''',
    '''The specified path, file name, or both are too long. The fully qualified file name must be less than 260 characters, and the directory name must be less than 248 characters.''',
    '''Send CAN message failed. Vector device returned: XL_ERR_NOT_IMPLEMENTED when calling XL_CanTransmit(...).''',
    '''No USB device found!''',
    '''Input string was not in a correct format.''',
    '''Start Request for Transfer''',
    '''The operation was canceled.'''
]

def parseTestResult(inputLine):
    matchRet = re.match(".*Test (.*) ended with status (.*).*", inputLine)

    if matchRet is None:
        matchRet = re.match(".*Test (.*) ended with compilation errors.*", inputLine)

    return matchRet;

def run_command_rt(commandStr, strictLog):
    printStr = []

    p = subprocess.Popen(commandStr, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

    for line in io.TextIOWrapper(p.stdout, encoding="utf-8"):
        line = line.strip()
        print_allowed = True
        if line:
            for word in banned_words:
                if word in line:
                    print_allowed = False
                    break

            if strictLog:
                for word in strictly_banned_words:
                    if word in line:
                        print_allowed = False
                        break

            if print_allowed:
                if line != 'test':
                    printStr.append(line)
                    print(line)

    for line in io.TextIOWrapper(p.stderr, encoding="utf-8"):
        line = line.strip()
        print_allowed = True
        if line:
            for word in banned_words:
                if word in line:
                    print_allowed = False
                    break

            if strictLog:
                for word in strictly_banned_words:
                    if word in line:
                        print_allowed = False
                        break

            if print_allowed:
                if line != 'test':
                    printStr.append(line)
                    print(line)
    return printStr

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-a', '--aria-path', help="Path to aria.exe", required=True)
    parser.add_argument('-c', '--command-line', help="Command to be ran in aria.exe", required=True)
    parser.add_argument('-x', '--xml-path', help="Path to summary report dir", required=True)
    parser.add_argument('-s', '--strict-log', help="Switch to trigger strict parsing", required=False, type=bool, default=False)
    parser.add_argument('-p', '--print-xml', help="Print XML log file for Jenkins", required=False, type=bool, default=False)
    parser.add_argument('-n', '--hack-list', help="Switch to hack list", required=False, type=bool, default=False)
    parser.add_argument('-i', '--statistics-path', help="Path to statistics", required=False)
    args = parser.parse_args()

    commandPrintRet = []
    fileList = []

    if args.hack_list:
        if '.txt' in args.command_line:
            testFile = open(args.command_line, "r")
            testFile = testFile.read()
            testFile = testFile.splitlines()
            for line in testFile:
                fileList.append(line)
        aria_command_option = '-run'
    else:
        if '.txt' in args.command_line:
            aria_command_option = '-runlist'
        elif '.ts' in args.command_line:
            aria_command_option = '-run'

    if not args.hack_list:
        fileList.append(aria_command_option)

    for file in fileList:
        commandPrintRet += run_command_rt('{} {} {}'.format(args.aria_path, aria_command_option ,file), args.strict_log)
        # Pause between two consecutively tests
        time.sleep(20)

        # commandPrintRet = run_command_rt('{} {} {}'.format(args.aria_path, file, args.command_line), args.strict_log)

    if args.print_xml:
        print_field_template = ''

        if not os.path.isdir(args.xml_path):
            os.makedirs(args.xml_path, exist_ok=True)

        for line in commandPrintRet:
            if parseTestResult(line) is not None:

                if 'compilation errors' in line:
                    testResColour = '#4306D8'

                    print_field_template += field_template.format(
                        TestName=parseTestResult(line).group(1),
                        TestResultColour=testResColour,
                        TestResult='Compilation Error'
                    ) + '\n'

                else:
                    if parseTestResult(line).group(2) == 'Passed':
                        testResColour = '#00CC00'
                    elif parseTestResult(line).group(2) == 'Failed':
                        testResColour = '#B22222'
                    else:
                        testResColour = '#4306D8'

                    print_field_template += field_template.format(
                        TestName=parseTestResult(line).group(1),
                        TestResultColour=testResColour,
                        TestResult=parseTestResult(line).group(2)
                    ) + '\n'

        summaryReportStr = 'SummaryReport_{}_{}.xml'.format(Path(args.command_line).stem.split('.')[0],
                                                            datetime.datetime.now().strftime("%H_%M"))

        summaryReport = open(os.path.join(args.xml_path, summaryReportStr), "w+")

        summaryReport.write(
            xml_template.format(
                TestReportTitle='Test Report {}'.format(datetime.datetime.now().strftime("%y-%m-%d %H:%M")),
                fieldTemplate=print_field_template
            )
        )

        summaryReport.close()

        # Process xml data
        # with open("S:\Tools\ARIA\Config\ARIA_Configuration\TestEnvironment_Automation\ARIA_config\Results\LastOutput\SummaryReport_TestList_02_42.xml", 'r+') as file:
        with open(os.path.join(args.xml_path, summaryReportStr), 'r+') as file:
            source_file = file.readlines()

        list_with_test_files = []
        for line in source_file:
            # regex_result = re.search("<field name=.(\w+.ts): . titlecolor=.#....... value=.(\w+).", str(line))
            regex_result = re.search("<field name=.(\w+.ts): . titlecolor=.#....... value=.(.+?)\".", str(line))
            if regex_result != None:
                list_with_test_files.append(regex_result.group(1))
                list_with_test_files.append(regex_result.group(2))
        list_with_test_files = [list_with_test_files[i:i + 2] for i in range(0, len(list_with_test_files), 2)]

        # Draw a blank image on screen
        blank_image = Image.new('RGB', (800, 1000), 'white')
        img_draw = ImageDraw.Draw(blank_image)

        # Initial positions to write text in png
        write_text_from_x_pos = 5
        write_text_from_y_pos = 5

        # Define font parameter
        font_parameter = ImageFont.truetype("arial.ttf", 16)

        # Draw efectevly in image
        for element in list_with_test_files:
            if element[1] == 'Passed':
                img_draw.text((write_text_from_x_pos, write_text_from_y_pos), element[0] + '   ' + element[1],
                              fill='green', font=font_parameter)
            else:
                img_draw.text((write_text_from_x_pos, write_text_from_y_pos), element[0] + '   ' + element[1],
                              fill='red', font=font_parameter)
            write_text_from_y_pos += 20

        blank_image.save(os.path.join(args.statistics_path, 'SummaryReport_png.png'))

    # os.system("start " + os.path.join(args.xml_path, os.path.splitext(os.path.basename(args.command_line))[0] + '.xml'))

if __name__ == '__main__':
    main()
