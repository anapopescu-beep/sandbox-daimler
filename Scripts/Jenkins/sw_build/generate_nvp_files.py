"""generate_nvp_files.py: Used to generate NVP Binaries"""

__author__ = 'Dan Dustinta'
__copyright__ = "Copyright 2019, Autoliv Electronic"
__version__ = "1.0.0"
__email__ = 'dan.dustinta@autoliv.com'
__status__ = 'Released'

import argparse
import sys
import os
import win32com.client
from win32com.client import Dispatch

currentDir = os.getcwd()
sys.path.append(currentDir)

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-f', '--file-path', help="Path to SBE_4G_NVP_layout.xls", required=True)
    args = parser.parse_args()

    xls_location = args.file_path
    xl = win32com.client.Dispatch("Excel.Application")
    xl.Workbooks.Open(xls_location, ReadOnly=1)

    xl.Application.Run("CheckCheckBox1_Release")

    # generate NVP_Generated.h and NVP_Generated.c
    xl.Application.Run("Generate_NVP")
    # generate NVP Binaries
    xl.Application.Run("Generate_Binaries")
    xl.Application.Run("GeneratFabFile")

    xl.Workbooks(1).Close(SaveChanges=1)
    xl.Application.Quit()
    del xl

if __name__ == '__main__':
    main()
