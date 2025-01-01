"""zip.py: Used to unzip arhives"""

__author__ = 'Dan Dustinta'
__copyright__ = "Copyright 2018, Autoliv Electronic"
__version__ = "1.0.4"
__email__ = 'dan.dustinta@autoliv.com'
__status__ = 'Released'

import zipfile
import os, sys
import yaml
import shutil
import argparse

currentDir = os.getcwd()
sys.path.append(currentDir)

def winapi_path(dos_path, encoding=None):
    path = os.path.abspath(dos_path)

    if path.startswith("\\\\"):
        path = "\\\\?\\UNC\\" + path[2:]
    else:
        path = "\\\\?\\" + path

    return path

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-z', '--zip-file', help="Select one zip file from the yaml file")
    args = parser.parse_args()

    with open("zip_config.yaml", 'r') as stream:
        try:
            zipFiles = yaml.load(stream, Loader=yaml.FullLoader)
        except yaml.YAMLError as exc:
            print(exc)

    for arhive, path_info in zipFiles.items():
        if not args.zip_file or args.zip_file in arhive:
            arhiveTimestamp = os.stat(arhive).st_mtime

            zip_ref = zipfile.ZipFile(winapi_path(arhive), "r")
            zipTree = zip_ref.namelist()

            if os.path.isdir(
                    os.path.normpath(os.path.join(path_info['extract_path'], zipTree[0]))):
                extractContent = os.stat(os.path.abspath(os.path.normpath(
                    os.path.join(path_info['extract_path'], zipTree[0])))).st_mtime
            else:
                extractContent = 0

            if arhiveTimestamp > extractContent:
                print('Extracting {} to {}'.format(arhive, path_info['extract_path']))
                shutil.rmtree(os.path.normpath(
                    os.path.abspath(os.path.join(path_info['extract_path'], zipTree[0]))),
                              ignore_errors=True)
                zip_ref.extractall(winapi_path(path_info['extract_path']))
            else:
                print('{} is up to date'.format(arhive))
        else:
            continue

if __name__ == '__main__':
    main()
