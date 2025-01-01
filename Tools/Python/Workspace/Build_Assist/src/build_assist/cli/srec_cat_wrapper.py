"""srec_cat_wrapper.py: Used to filter srec_cat output"""

__author__ = 'Dan Dustinta'
__copyright__ = "Copyright 2018, Autoliv Electronic"
__version__ = "1.0.3"
__email__ = 'dan.dustinta@autoliv.com'
__status__ = 'Released'

import time
import argparse
import sys
import os
import io
import subprocess
import re

currentDir = os.getcwd()
sys.path.append(currentDir)

def parseWarning(inputLine):
    matchRet = re.search("(srec_cat:)(.*)(warning:)(.*)(no execution)(.*)(start)(.*)(address record)", inputLine, re.S)

    if matchRet is None:
        matchRet = re.search("(srec_cat:)(.*)(warning:)(.*)(no execution start)(.*)(address record)", inputLine, re.S)

    if matchRet is None:
        matchRet = re.search("(srec_cat:)(.*)(warning:)(.*)(no header)(.*)(record)", inputLine, re.S)

    return matchRet;

def run_command_str(commandStr):
    retStr = ''

    try:
        p = subprocess.Popen(commandStr, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    except FileNotFoundError as e:
        print(e)
        sys.exit(1)

    for line in io.TextIOWrapper(p.stderr, encoding="utf-8"):
        line = line.strip()
        if line:
            retStr += '{}\n'.format(line)

    return retStr, p.returncode

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-s', '--srec-path', help="Path to srec_cat.exe", required=True)
    parser.add_argument('-c', '--command-line', help="Command to be ran in srec_cat.exe", required=True)
    args = parser.parse_args()

    srec_command_str, return_code = run_command_str('{} {}'.format(args.srec_path, args.command_line))

    srec_command_list = srec_command_str.split('srec_cat:')

    for i in range(0, len(srec_command_list)):
        if srec_command_list[i]:
            srec_command_list[i] = 'srec_cat:' + srec_command_list[i]

    srec_command_list = list(filter(None, srec_command_list))

    for warning in srec_command_list:
        warning_obj = parseWarning(warning)
        if warning_obj is None:
            print(warning.replace('\n', ' '))

    sys.exit(return_code)

if __name__ == '__main__':
    main()
