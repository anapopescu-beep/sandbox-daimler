__author__ = 'Dan Dustinta'
__copyright__ = "Copyright 2018, Autoliv Electronic"
__version__ = "1.0.1"
__email__ = 'dan.dustinta@autoliv.com'
__status__ = 'Draft'

import win32con, win32api,os
import sys
import glob
import re
from pathlib import Path

currentDir = os.getcwd()
sys.path.append(currentDir)

def searchTestLabel(inputLine):
    matchRet = re.search("(.*[ \s]*)(ARCH_SW_[a-zA-Z0-9_]+)([\s ]*.*)", inputLine)
    return matchRet;

def main():
    req_dict = {}
    filtered_req_dict = {}
    path_scenario = "s:\\Tests\\Tests_Integration\\Automatic_Tests\\Test_Scenarios\\"
    path_report = "s:\\Tests\\Tests_Integration\\Automatic_Tests\\Test_Reports\\"
    for file in glob.glob(path_scenario + '*.ts'):
        sourceFile = open(os.path.join(path_scenario, file), "r", errors='ignore')
        sourceFile = sourceFile.read()
        sourceFile = sourceFile.splitlines()
        for line in sourceFile:
            ret = searchTestLabel(line)
            if ret is not None:
                if file not in req_dict:
                    req_dict[Path(file).stem] = set()
                    req_dict[Path(file).stem].add(ret.group(2))
                else:
                    req_dict[Path(file).stem].add(ret.group(2))

    for file in glob.glob(path_report + '*.xml'):
        sourceFile = open(os.path.join(path_scenario, file), "r", errors='ignore')
        sourceFile = sourceFile.read()
        sourceFile = sourceFile.splitlines()
        for line in sourceFile:
            if "Result Test:PASSED" in line:
                for key, items in req_dict.items():
                    if key in Path(file).stem:
                        filtered_req_dict[key] = req_dict[key]

    for file, req_list in filtered_req_dict.items():
        print('{}\t{}'.format(file, " ".join(req_list)))

if __name__ == '__main__':
    main()
