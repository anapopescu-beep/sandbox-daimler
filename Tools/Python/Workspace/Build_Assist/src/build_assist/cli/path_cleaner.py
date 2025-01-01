"""path_cleaner.py: Used to remove accidental usage of make/python"""

__author__ = 'Dan Dustinta'
__copyright__ = "Copyright 2018, Autoliv Electronic"
__version__ = "1.0.0"
__email__ = 'dan.dustinta@autoliv.com'
__status__ = 'Released'

import sys
import os
import subprocess
from subprocess import Popen
import io
import argparse

forbidden_prog_list = ['make', 'python', 'pip']

def filterList(fullList, excludes):
    s = set(excludes)
    return (x for x in fullList if x not in s)

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-p', '--path-var', help="echo the PATH variable")
    args = parser.parse_args()

    pathList = args.path_var.split(';')
    forbidden_paths = []
    stdoutCheck = False
    returnPathStr = ''

    for prog in forbidden_prog_list:
        x = Popen("where " + prog, stdout=subprocess.PIPE, cwd=os.path.dirname(os.path.realpath(__file__)), shell=True)

        for line in io.TextIOWrapper(x.stdout, encoding="utf-8"):
            stdoutCheck = True
            if os.path.dirname(line.strip()) not in forbidden_paths:
                forbidden_paths.append(os.path.dirname(line.strip()))

    if not stdoutCheck:
        returnPath = pathList
    else:
        returnPath = list(filterList(pathList, forbidden_paths))

    for path in returnPath:
        returnPathStr += path
        if returnPath.index(path) != len(returnPath) - 1:
            returnPathStr += ';'

    print(returnPathStr)

    return 0

if __name__ == "__main__":
    main()
