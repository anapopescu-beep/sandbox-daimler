#Lucian Ardeleanu
#Autoliv 2020

import argparse
import re
# /**************************************************************************************/
# FUNCTION NAME: READ FROM C FILE FUNCTIONS FROM ONE TASK
# ARGUMENTS: STRING: FILE_TO_READ
# RETURN: ARRAY: output_list
# DESCRIPTION: FUNCTION THAT EXTRACT FROM C FILE THE FUNCTIONS NAME, PERIOD AND OFFSET AND PARSE TO INT OFFSET AND PERIOD, IGNORING THE LINES THAT CAN'T BE PARSED TO INT
# /**************************************************************************************/

def read_from_c_file_functions_from_one_task(file_to_read):

    output_list = []
    temp_output_list = []

    with open(file_to_read, "r") as f:   # open file to read as read only "r" and assignate it to data
        data = f.readlines() #read in variable data line by line

    enableParsing = False

    for line in data:
        if ('SCH_ast_Run_Schedule_Table[]' in line):
            enableParsing = True
            continue

        if ('};' in line and enableParsing):
            break

        if enableParsing:
            ret_match = re.match(r'.*{&(.*),\s+SCH_MS\(([0-9]+)\).*},', line) #extract from whole line important function name

            if ret_match is not None:
                temp_output_list.append([ret_match.group(2), ret_match.group(1)])


            ret_match = re.match(r'.*{SCH_END_OF_LIST,\s+SCH_MS\(([0-9]+).*\).*}.*', line) #extract from whole line important function name

            if ret_match is not None:
                for index in range(0, len(temp_output_list)):
                    temp_output_list[index].insert(0, ret_match.group(1))
                    temp_output_list[index][0] = int(temp_output_list[index][0])
                    temp_output_list[index][1] = int(temp_output_list[index][1])
                    output_list.append(temp_output_list[index])
                temp_output_list = []

    return output_list
    f.close()

def write_in_ts(list_of_file_names, file_to_overwrite):

    list_with_numbers_from_aria = []
    list_of_functions_name = []
    cumulated_list_of_names_and_numbers = []
    global_list = []

    list_of_phases_to_write_in_ts = []

    list_of_antet_data = []

    number = 0

    list_with_numbers_from_aria.append(0)
    for i in range(0, len(list_of_file_names) - 1):
        if i != len(list_of_file_names) - 1:
            if (list_of_file_names[i][0] != list_of_file_names[i + 1][0]):
                number += 2
            else:
                number += 1
        else:
            if (list_of_file_names[len(list_of_file_names) - 1][0] != list_of_file_names[len(list_of_file_names) - 2][0]):
                number += 2
            else:
                number += 1
        list_with_numbers_from_aria.append(number)

    for i in range(0, len(list_of_file_names)):
        list_of_functions_name.append(list_of_file_names[i][2])

    for i in range(0, len(list_of_file_names)):
        cumulated_list_of_names_and_numbers.append(list_with_numbers_from_aria[i])
        cumulated_list_of_names_and_numbers.append(list_of_functions_name[i])
    for i in range(0, len(cumulated_list_of_names_and_numbers), 2):
        global_list.append(cumulated_list_of_names_and_numbers[i:i + 2])

    for i in range(0,len(global_list)):
        phrase_to_write_in_ts = str(global_list[i][0]) + ', "'+str(global_list[i][1]) + '",' +'\n'
        list_of_phases_to_write_in_ts.append(phrase_to_write_in_ts)
    list_of_phases_to_write_in_ts.append('];')

    with open(file_to_overwrite, "rb") as inputf:
        data = inputf.readlines()
    inputf.close()

    for line in data:
        list_of_antet_data.append(str(line)[2:len(line)] + '\n')
        if 'const aSCH_Configuration = [' in str(line):
            break

    with open(file_to_overwrite, "w+") as outputf:
        outputf.writelines(list_of_antet_data)
        outputf.writelines(list_of_phases_to_write_in_ts)
    outputf.close()
def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-i', '--input-scheduler', help="Path to .c file that contains scheduler E.G. C:\Schedule_Table_Cfg.c", required=True)
    parser.add_argument('-l', '--input-ts', help="Path to .ts file ( ARIA Script to update )  E.G. C:\CPU_Load_Test_Cases.ts", required=True)


    args = parser.parse_args()

    list_of_file_names = read_from_c_file_functions_from_one_task(file_to_read=args.input_scheduler)
    write_in_ts(list_of_file_names=list_of_file_names, file_to_overwrite = args.input_ts)

if __name__ == "__main__":
    main()






