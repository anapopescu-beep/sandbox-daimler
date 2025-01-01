__author__ = 'David Puscasu'
__copyright__ = "Copyright 2022, Autoliv Electronic"
__version__ = "1.0"
__email__ = 'david.puscasu@autoliv.com'
__status__ = 'Released'

import csv
import yaml

def parse_map_file(file_path):
    sw_components_dict = {}

    lines = open(file_path).readlines()

    start_parsing_flag = False
    for line in lines:
        if not start_parsing_flag:
            if 'Combined sections' in line:
                start_parsing_flag = True
        elif 'Processor and Memory' in line:
            start_parsing_flag = False
            break
        else:
            if line.startswith('| .'):
                memory_type = line.split('.')[1]
                sw_component = line.split('.')[2].split(' ')[0]
                size_str = line.split('|')[2].replace(' ', '')
                size = int(size_str, 16)
                if memory_type in sw_components_dict.keys():
                    if sw_component in sw_components_dict[memory_type].keys():
                        sw_components_dict[memory_type][sw_component] += size
                    else:
                        sw_components_dict[memory_type][sw_component] = size
                else:
                    memory_type_dict = {}
                    memory_type_dict[sw_component] = size
                    sw_components_dict[memory_type] = memory_type_dict
    return sw_components_dict

def write_csv_file(sw_components_dict, csv_file_path):
    csv_header = ['Memory Type', 'SW Component', 'Size']
    csv_data = []

    for memory_type in sw_components_dict.keys():
        for sw_component in sw_components_dict[memory_type].keys():
            size = sw_components_dict[memory_type][sw_component]

            csv_data_line = []
            csv_data_line.append(memory_type)
            csv_data_line.append(sw_component)
            csv_data_line.append(size)

            csv_data.append(csv_data_line)

    with open(csv_file_path, 'w', encoding='UTF8', newline='') as f:
        writer = csv.writer(f)

        # write the header
        writer.writerow(csv_header)

        # write multiple rows
        writer.writerows(csv_data)


def main():
    yaml_file = yaml.safe_load(open('file_path.yaml'))
    map_file_path = yaml_file['map_in_file_path']
    csv_file_path = yaml_file['csv_out_file_path']

    sw_components_dict = parse_map_file(map_file_path)
    write_csv_file(sw_components_dict, csv_file_path)

main()