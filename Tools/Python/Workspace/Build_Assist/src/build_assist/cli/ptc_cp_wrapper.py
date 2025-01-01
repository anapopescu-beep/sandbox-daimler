"""ptc_cp_wrapper.py: Used to launch PTC and check CP contents"""

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
from pathlib import Path

currentDir = os.getcwd()
sys.path.append(currentDir)

def matchFile(inputLine):
    matchRet = re.match("(.*\.c|.*\.h|.*\.ts|.*\.xml|.*\.xlsm)(.*)(#p=.*#)(.*)(#d=.*#)(.*)(\s+)(Drop|Update|Add.*)", inputLine)

    # if matchRet is not None:
    #     spaceRet = re.match(".*project.pj\s+Drop.*", inputLine)
    #
    #     if spaceRet is not None:
    #         matchRet = None

    return matchRet;

def matchFileDir(inputLine):
    matchRet = re.match("(.*)(project.pj\s*)(Drop|Update|Add.*)", inputLine)
    return matchRet;

def run_command_str(commandStr):
    printStr = []

    p = subprocess.Popen(commandStr, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

    for line in io.TextIOWrapper(p.stdout, encoding="utf-8"):
        line = line.strip()
        print_allowed = True
        if line:
            printStr.append(line)

    for line in io.TextIOWrapper(p.stderr, encoding="utf-8"):
        line = line.strip()
        print_allowed = True
        if line:
            printStr.append(line)

    return printStr

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-n', '--hostname', help="PTC Host Name", required=True)
    parser.add_argument('-u', '--username', help="PTC User Name", required=True)
    parser.add_argument('-p', '--password', help="PTC User Password", required=True)
    parser.add_argument('-c', '--change-package', help="Change Package ID", required=True)
    parser.add_argument('-o', '--output-dir', help="Output Dir for Listings", required=True)
    parser.add_argument('-w', '--workspace-dir', help="Workspace dir for subst", required=True)
    parser.add_argument('-s', '--sandbox-dir', help="Sandbox dir for subst", required=True)

    args = parser.parse_args()

    commandPrintRet = run_command_str('im viewcp --attributes=ID --entryAttributes=member,configpath,type --hostname={hostname} --port=7001 --password={password} --user={username} {cpId}'.format(
        hostname=args.hostname,
        password=args.password,
        username=args.username,
        cpId=args.change_package
    ))

    entry_list_source = []
    entry_list_modules = []
    entry_list_script = []
    entry_list_review = []

    for line in commandPrintRet:
        if line != 'Entries:':
            if matchFile(line) is not None:
                if matchFile(line).group(8) != 'Drop':
                    fileName = matchFile(line).group(4).strip() + '/' + matchFile(line).group(6).strip() + '/' + matchFile(line).group(1).strip()

                    fileName = fileName.replace(args.workspace_dir, args.sandbox_dir).replace('/', '\\')
                    fileNameTemp = fileName.split('\\')
                    if fileNameTemp[1] == 'Components' and \
                        fileNameTemp[2] == 'Application':
                        entry_list_modules.append(fileNameTemp[3])

                    if '.c' in fileName:
                        entry_list_source.append(fileName)
                    elif '.h' in fileName:
                        entry_list_source.append(fileName)
                    elif '.ts' in fileName:
                        entry_list_script.append(fileName)
                    elif '.xml' in fileName:
                        entry_list_review.append(fileName)
                    elif '.xlsm' in fileName:
                        entry_list_review.append(fileName)

    output_source_list_str = os.path.join(args.output_dir, 'SourceList.txt')
    output_modules_list_str = os.path.join(args.output_dir, 'ModuleList.txt')
    output_script_list_str = os.path.join(args.output_dir, 'ScriptList.txt')
    output_review_list_str = os.path.join(args.output_dir, 'ReviewList.txt')

    output_source_list = open(output_source_list_str, 'w+')
    output_modules_list = open(output_modules_list_str, 'w+')
    output_script_list = open(output_script_list_str, 'w+')
    output_review_list = open(output_review_list_str, 'w+')

    output_source_list.write('\n'.join(entry_list_source))
    output_modules_list.write('\n'.join(set(entry_list_modules)))
    output_script_list.write('\n'.join(entry_list_script))
    output_review_list.write('\n'.join(entry_list_review))

    output_source_list.close()
    output_modules_list.close()
    output_script_list.close()
    output_review_list.close()

if __name__ == '__main__':
    main()
