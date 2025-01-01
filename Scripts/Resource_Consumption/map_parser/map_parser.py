"""map_parser.py: Used to parse S12Z map file and find ROM consumption per module"""

__author__ = 'Dan Dustinta'
__copyright__ = "Copyright 2018, Autoliv Electronic"
__version__ = "1.0.0"
__email__ = 'dan.dustinta@autoliv.com'
__status__ = 'Released'

import sys
import os
import re
import argparse
from pathlib import Path
from openpyxl import Workbook
import csv
from natsort import natsorted
import subprocess
import io

current_dir = os.getcwd()
sys.path.append(current_dir)

from config import *

const, flash, ram, section, total_consumption_flash, total_consumption_ram = ('const', 'flash', 'ram', 'section', 'total_consumption_flash', 'total_consumption_ram')
start_addr, end_addr, length = ('start_addr', 'end_addr', 'length')

ONE_LINE_OFFSET = 1
TWO_LINE_OFFSET = 2

RESULT_INDEX = 0

START_ADDRESS_INDEX = 0
END_ADDRESS_INDEX = 1
LENGTH_INDEX = 2
SECTION_INDEX = 3

MIN_ADDR = 0
MAX_ADDR = 1

def searchObject(inputLine):
    matchRet = re.match(".*(\.o|\.z12).*", inputLine)
    return matchRet;

def searchMapConsumption(inputLine):
    matchRet = re.findall("start\s+([a-fA-F0-9]*)\s+end\s+([a-fA-F0-9]*)\s+length\s+([0-9]*)\s+section\s+(.*)", inputLine)
    return matchRet;

def searchSegment(inputLine):
    matchRet = re.findall("start\s+([a-fA-F0-9]*)\s+end\s+([a-fA-F0-9]*)\s+length\s+([0-9]*)\s+segment\s+(.*)", inputLine)
    return matchRet;

def searchFlashConsumption(inputLine):
    matchRet = re.match("[0]+f.*", inputLine)
    return matchRet;

def searchConstConsumption(inputLine):
    matchRet = re.match(".*\.[^\s]*CONST.*|.*\.[^\s]*const.*", inputLine)
    return matchRet;

def run_command_str(commandStr):
    retStr = ''
    p = subprocess.Popen(commandStr, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

    for line in io.TextIOWrapper(p.stdout, encoding="utf-8"):
        line = line.strip()
        if line:
            retStr += '{}\n'.format(line)

    return retStr, p.returncode

parser = argparse.ArgumentParser()
parser.add_argument('-m', '--map-path', help="pass the map file path", required=True)
parser.add_argument('-s', '--srec-path', help="Path to srec_info.exe", required=True)
parser.add_argument('-f', '--file-path', help="pass the map file path", required=True)
args = parser.parse_args()
print(args)
print('.')
def main1():
    map_file = open(args.map_path, 'r')
    map_file = map_file.read()
    map_file = map_file.splitlines()

    module_dict = {}
    section_dict = {
        flash: {},
        ram: {},
        total_consumption_flash: 0,
        total_consumption_ram: 0
    }

    for line in map_file:
        if '-------' in line:
            if '-------' in map_file[map_file.index(line) + TWO_LINE_OFFSET]:
                if 'Modules' in map_file[map_file.index(line) + ONE_LINE_OFFSET]:
                    del map_file[0:map_file.index(line)]
                    break

    for line in map_file:
        if '-------' in line:
            if '-------' in map_file[map_file.index(line) + TWO_LINE_OFFSET]:
                if 'Modules' not in map_file[map_file.index(line) + ONE_LINE_OFFSET]:
                    del map_file[map_file.index(line):]
                    break

    current_module = None

    for line in map_file:
        if searchObject(line) is not None:
            current_module = Path(line).stem.split('.')[0]
            module_dict[current_module] = {
                flash: 0,
                const: 0,
                ram: 0,
            }
        elif current_module in module_dict:
            map_consumption = searchMapConsumption(line)
            if map_consumption:
                if '.debug' not in map_consumption[RESULT_INDEX][SECTION_INDEX]:
                    if '.info' not in map_consumption[RESULT_INDEX][SECTION_INDEX]:

                        if  int(map_consumption[RESULT_INDEX][START_ADDRESS_INDEX], 16) >= flash_addr_range[MIN_ADDR] and \
                            int(map_consumption[RESULT_INDEX][START_ADDRESS_INDEX], 16) <= flash_addr_range[MAX_ADDR]:

                            if map_consumption[RESULT_INDEX][SECTION_INDEX] not in section_dict[flash]:
                                section_dict[flash][map_consumption[RESULT_INDEX][SECTION_INDEX]] = int(map_consumption[RESULT_INDEX][LENGTH_INDEX])
                            else:
                                section_dict[flash][map_consumption[RESULT_INDEX][SECTION_INDEX]] += int(map_consumption[RESULT_INDEX][LENGTH_INDEX])

                            section_dict[total_consumption_flash] += int(map_consumption[RESULT_INDEX][LENGTH_INDEX])

                        elif int(map_consumption[RESULT_INDEX][START_ADDRESS_INDEX], 16) >= ram_addr_range[MIN_ADDR] and \
                             int(map_consumption[RESULT_INDEX][START_ADDRESS_INDEX], 16) <= ram_addr_range[MAX_ADDR]:

                            if map_consumption[RESULT_INDEX][SECTION_INDEX] not in section_dict[ram]:
                                section_dict[ram][map_consumption[RESULT_INDEX][SECTION_INDEX]] = int(map_consumption[RESULT_INDEX][LENGTH_INDEX])
                            else:
                                section_dict[ram][map_consumption[RESULT_INDEX][SECTION_INDEX]] += int(map_consumption[RESULT_INDEX][LENGTH_INDEX])

                            section_dict[total_consumption_ram] += int(map_consumption[RESULT_INDEX][LENGTH_INDEX])

                        flash_consumption = searchFlashConsumption(map_consumption[RESULT_INDEX][START_ADDRESS_INDEX])

                        if flash_consumption:
                            const_consumption = searchConstConsumption(map_consumption[RESULT_INDEX][SECTION_INDEX])
                            if const_consumption:
                                module_dict[current_module][const] += int(map_consumption[RESULT_INDEX][LENGTH_INDEX])
                            else:
                                module_dict[current_module][flash] += int(map_consumption[RESULT_INDEX][LENGTH_INDEX])
                        else:
                            module_dict[current_module][ram] += int(map_consumption[RESULT_INDEX][LENGTH_INDEX])
    #output reports
    output_list = []
    output_list.append('{},{},{},{},{},{},{}'.format('Module', 'Code consumption', 'Const consumption', 'Total flash consumption <int>', 'Total flash consumption <hex>', 'RAM consumption <int>', 'RAM consumption <hex>').split(','))

    for module_name, consumption_info in module_dict.items():
        output_list.append('{},{},{},{},{},{},{}'.format(module_name, consumption_info[flash],
                                                         consumption_info[const],
                                                         consumption_info[flash] + consumption_info[const],
                                                         hex(consumption_info[flash] + consumption_info[const]),
                                                         consumption_info[ram],
                                                         hex(consumption_info[ram])).split(','))

    with open('map_report.csv', 'w', newline='') as f:
        writer = csv.writer(f)
        writer.writerows(output_list)

    f.close()

    wb = Workbook()
    ws = wb.active
    with open('map_report.csv', 'r') as f:
        for row in csv.reader(f):
            ws.append(row)
    wb.save('map_report.xlsx')

    f.close()

def main2():
    map_file = open(args.map_path, 'r')
    map_file = map_file.read()
    map_file = map_file.splitlines()

    section_dict = {
        flash: {},
        ram: {},
        total_consumption_flash: 0,
        total_consumption_ram: 0,
    }

    for line in map_file:
        if '-------' in line:
            if '-------' in map_file[map_file.index(line) + TWO_LINE_OFFSET]:
                if 'Segments' in map_file[map_file.index(line) + ONE_LINE_OFFSET]:
                    del map_file[0:map_file.index(line)]
                    break

    for line in map_file:
        if '-------' in line:
            if '-------' in map_file[map_file.index(line) + TWO_LINE_OFFSET]:
                if 'Segments' not in map_file[map_file.index(line) + ONE_LINE_OFFSET]:
                    del map_file[map_file.index(line):]
                    break

    current_section = None

    for line in map_file:
        current_section = searchSegment(line)
        if current_section:
            if int(current_section[RESULT_INDEX][START_ADDRESS_INDEX], 16) >= flash_addr_range[MIN_ADDR] and \
               int(current_section[RESULT_INDEX][START_ADDRESS_INDEX], 16) <= flash_addr_range[MAX_ADDR]:

                section_dict[flash][current_section[RESULT_INDEX][SECTION_INDEX].replace(', initialized', '').replace(', from', '')] = {
                    start_addr: current_section[RESULT_INDEX][START_ADDRESS_INDEX],
                    end_addr: current_section[RESULT_INDEX][END_ADDRESS_INDEX],
                    length: current_section[RESULT_INDEX][LENGTH_INDEX]
                }
                section_dict[total_consumption_flash] += int(current_section[RESULT_INDEX][LENGTH_INDEX])
            elif int(current_section[RESULT_INDEX][START_ADDRESS_INDEX], 16) >= ram_addr_range[MIN_ADDR] and \
                 int(current_section[RESULT_INDEX][START_ADDRESS_INDEX], 16) <= ram_addr_range[MAX_ADDR]:

                section_dict[ram][current_section[RESULT_INDEX][SECTION_INDEX].replace(', initialized', '').replace(', from', '')] = {
                    start_addr: current_section[RESULT_INDEX][START_ADDRESS_INDEX],
                    end_addr: current_section[RESULT_INDEX][END_ADDRESS_INDEX],
                    length: current_section[RESULT_INDEX][LENGTH_INDEX]
                }
                section_dict[total_consumption_ram] += int(current_section[RESULT_INDEX][LENGTH_INDEX])

    # output reports
    output_list = []
    output_list.append('{},{},{},{},{},{},{}'.format('Section', 'Flash consumption <int>', 'Ram consumption <int>', 'Total flash consumption <int>', 'Total flash consumption <hex>', 'RAM consumption <int>', 'RAM consumption <hex>').split(','))

    for key, value in section_dict[flash].items():
        output_list.append('{},{},{},{},{},{},{}'.format(key, value[length], '', '', '', '', '').split(','))

    for key, value in section_dict[ram].items():
        output_list.append('{},{},{},{},{},{},{}'.format(key, '', value[length], '', '', '', '').split(','))

    output_list.append('{},{},{},{},{},{},{}'.format('', '', '', section_dict[total_consumption_flash], hex(section_dict[total_consumption_flash]), '', '').split(','))
    output_list.append('{},{},{},{},{},{},{}'.format('', '', '', '', '', section_dict[total_consumption_ram], hex(section_dict[total_consumption_ram])).split(','))

    with open('map_section_report.csv', 'w', newline='') as f:
        writer = csv.writer(f)
        writer.writerows(output_list)

    f.close()

    wb = Workbook()
    ws = wb.active
    with open('map_section_report.csv', 'r') as f:
        for row in csv.reader(f):
            ws.append(row)
    wb.save('map_section_report.xlsx')

    f.close()

def main3():
    srec_command_str, return_code = run_command_str('{} {}'.format(args.srec_path, args.file_path))

    flash_data = srec_command_str.split('Data:')

    flash_data = flash_data[1].strip().split('\n')

    flash_consumption = 0

    for flash_range in flash_data:
        flash_range = flash_range.split(' - ')

        if int(flash_range[0], 16) >= flash_addr_range[MIN_ADDR] and \
           int(flash_range[1], 16) <= flash_addr_range[MAX_ADDR]:

            flash_consumption += (int(flash_range[1], 16) - int(flash_range[0], 16))

    print('Total flash consumption in FullFlash binary: {}k out of {}k'.format(
        int(flash_consumption/1024),
        int((flash_addr_range[MAX_ADDR] - flash_addr_range[MIN_ADDR]) / 1024))
    )

    print('Flash consumption percentage in FullFlash binary: {}%'.format(int((int(flash_consumption / 1024) * 100) / int((flash_addr_range[MAX_ADDR] - flash_addr_range[MIN_ADDR])/1024))))

if __name__ == "__main__":
    main1()
    main2()
    main3()