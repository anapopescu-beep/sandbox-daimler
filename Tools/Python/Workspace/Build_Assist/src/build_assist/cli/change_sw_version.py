"""change_sw_version.py: Used to change the SW version in given file"""

__author__ = 'Dan Dustinta'
__copyright__ = "Copyright 2019, Autoliv Electronic"
__version__ = "1.0.0"
__email__ = 'dan.dustinta@autoliv.com'
__status__ = 'Released'

import argparse
import sys
import os

currentDir = os.getcwd()
sys.path.append(currentDir)

SW_VERSION_PLACEHOLDER = "XXXXXXXX.XXX"

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-f', '--file-path', help="Path to file in which to change SW version", required=True)
    parser.add_argument('-s', '--new-swversion', help="New Software Version", required=True)
    parser.add_argument('-o', '--old-swversion', help="Old Software Version. Legacy option, should not be used", required=False, default=None)
    args = parser.parse_args()

    input_file_obj = open(args.file_path, 'r')
    input_file = input_file_obj.read()
    input_file = input_file.splitlines()
    input_file_obj.close()

    replacement_cnt = 0
    replacement_history = []

    if args.old_swversion is not None:
        replacement_var = args.old_swversion
    else:
        replacement_var = SW_VERSION_PLACEHOLDER

    for idx in range(0, len(input_file)):
        if replacement_var in input_file[idx]:
            replacement_history.append(input_file[idx])
            replacement_cnt += 1
            input_file[idx] = input_file[idx].replace(replacement_var, args.new_swversion)

    output_file = open(args.file_path, 'w+')
    output_file.write('\n'.join(input_file))
    output_file.close()

    if replacement_cnt == 0:
        print('Warning: SW Version not found, please check source files.')
    elif replacement_cnt > 1:
        print('Warning: SW Version found in multiple places, please check source files.')
        print("\n".join(replacement_history))

if __name__ == '__main__':
    main()
