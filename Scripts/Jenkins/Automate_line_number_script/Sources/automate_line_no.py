import glob
import re
import os
import difflib
import os.path
import argparse
import shutil
import math
import time

def get_function_name_line(function_name, list):
    return "".join(s for s in list if (function_name in s) and ( 'var ' + function_name + ' = ' in s) or ( function_name + ' = ' in s) or (function_name + ': String = ' in s ))

def get_offset_name_line(offset, list):
    return "".join(s for s in list if (offset in s) and ('var ' + offset + ' = ' in s) or ( offset + ' = ' in s) or ( offset + ': Number =' in s) )

def findLineMarker(inputLine):
    matchRet = re.match("(\*\*\* )([0-9]+),([0-9]+)( \*\*\*\*)", inputLine)
    if matchRet is None:
        matchRet = re.match("(--- )([0-9]+),([0-9]+)( ----)", inputLine)
    return matchRet

def chunk_based_on_number(lst, chunk_numbers):
    n = math.ceil(len(lst)/chunk_numbers)

    for x in range(0, len(lst), n):
        each_chunk = lst[x: n+x]

        if len(each_chunk) < n:
            each_chunk = each_chunk + [None for y in range(n-len(each_chunk))]
        yield each_chunk

def getOverlap(a, b):
    return max(0, min(a[1], b[1]) - max(a[0], b[0]))

def find(name, path):
    for root, dirs, files in os.walk(path):
        if name in files:
            return os.path.join(root, name)

def has_numbers(inputString):
    result = 0
    for char in inputString:
        if char.isdigit():
            result = inputString.find(char)
            break
    if result == 0:
        return False
    else:
        return result

# FUNCTION NOT USED ANYMORE, IT SHOULD BE USED TO DETERMINE IF OFFSET LINE IN CORECTLY
def find_offset_line_in_ts_script(content_of_ts_script):

    breakpoint_list_per_file = []
    for line in content_of_ts_script:
        if 'debugger_setRelativeFunctionBpAtLine' in line:
            # Extract line with breakpoint
            regex_result = re.search("[(](.*)[)]", line)

            # Extract function name from that line and offset number
            function_name, offset = regex_result.group(0).split(",")

            # Detele unnecesary characters from string
            function_name = function_name.replace('(', '')
            offset = offset.split(')')[0].replace(' ', '')

            # Get group of function name and offset from ts script
            breakpoint_temp_group = function_name, offset

            # append group in list
            if breakpoint_temp_group not in breakpoint_list_per_file:
                breakpoint_list_per_file.append(breakpoint_temp_group)

    list_with_lines_with_offset_from_source_code = []
    for breakpoint in breakpoint_list_per_file:
        for line in content_of_ts_script:
            if ( breakpoint[1] in line ) and ( has_numbers(line) != False ) and ( 'tRelativeBreakPointParam' not in line ):

                if 'line:' in line:
                    offset_line_from_ts_script = line[ line.find('line:')+len('line:') : ]
                    offset_line_from_ts_script = offset_line_from_ts_script.replace( '*/', '')

                    if offset_line_from_ts_script not in list_with_lines_with_offset_from_source_code:
                        list_with_lines_with_offset_from_source_code.append( offset_line_from_ts_script )
    print(list_with_lines_with_offset_from_source_code)



def main():

    # define paths
    path_to_integration_test_files = "S:\Tests\Tests_Integration\Automatic_Tests"

    print('Please make sure to have S: drive mapped!')

    # PARSE XML AND EXTRACT DATA ==========================================

    # DEFINE DELIMITERS USED IN TEST REPORTS
    file_name_delimiter = 'File Name = '
    function_delimiter = ', Function = '
    function_line_number = ', Line Number = '
    end_of_function_line_number = ', @ = '
    function_line_offset = '; Function Line offset ='
    end_of_line = '</comment>'

    path_to_test_reports = path_to_integration_test_files + "\Test_Reports"
    exclude_directories = []
    data_from_all_xml_files = []

    for root, dirs, files in os.walk(path_to_test_reports):
        # exclude directories here
        dirs[:] = [d for d in dirs if d not in exclude_directories]

        for file in files:
            entire_data_from_one_xml_file = []

            # If found a source file
            if ( file.endswith(".xml") ):
                test_name = file

                # Open file as read only
                with open(os.path.join(root, file), 'r', encoding="utf8", errors='ignore') as file:
                    xml_content = file.readlines()

                # For every line of opened file
                for line in xml_content:
                    # Initialise a temp list with data from xml
                    breakpoint_line_found_in_xml = ['', '', '', '', '']

                    # extract if breakpoint found in line
                    if  '<comment>Action: BP:' in line:
                        # Extract data from every line
                        breakpoint_line_found_in_xml[0] = test_name # XLSX Test report name
                        temp_path_to_source_file = line[line.find(file_name_delimiter)+ len(file_name_delimiter) : line.find(function_delimiter)] # Source File Name
                        breakpoint_line_found_in_xml[2] = line[line.find(function_delimiter) + len(function_delimiter): line.find(function_line_number)] # Function NAME
                        breakpoint_line_found_in_xml[3] = int ( line[line.find(function_line_number) + len(function_line_number): line.find(end_of_function_line_number)] )# Function Line Number
                        breakpoint_line_found_in_xml[4] = int ( line[line.find(function_line_offset) + len(function_line_offset): line.find(end_of_line)] ) # Function Line OFfset

                        # If view development found in path, then replace that part with path from S drive
                        if ('View_Development' in temp_path_to_source_file):
                            path_to_be_replaced = temp_path_to_source_file[0 : temp_path_to_source_file.find('View_Development')+ len('View_Development')]
                            breakpoint_line_found_in_xml[1] = temp_path_to_source_file.replace(path_to_be_replaced, 'S:')
                        else:
                            # Else keep it as it is
                            breakpoint_line_found_in_xml[1] = temp_path_to_source_file

                    # If Breakpoint not already in list with all data per xml file, then append it
                    if ( breakpoint_line_found_in_xml not in entire_data_from_one_xml_file )  and ( len(breakpoint_line_found_in_xml[1]) != 0 ):
                        entire_data_from_one_xml_file.append(breakpoint_line_found_in_xml)

            # Append extracted data per file into a global list with all data per all xml files
            if (entire_data_from_one_xml_file not in data_from_all_xml_files) and ( len(entire_data_from_one_xml_file) != 0 ):
                data_from_all_xml_files.append(entire_data_from_one_xml_file)

    # END OF PARSE XML AND EXTRACT DATA ==========================================

    # SOURCE FILE ANALISYS ===============================================
    # define list with new breakpoints
    new_list_with_breakpoints_per_all_files = []

    check_if_files_updated = False

    for file in data_from_all_xml_files:

        # define a new list for updated breakpoints per file
        new_breakpoints_list_per_file = []

        for found_breakpoint in file:

            # Define path to source file folder history
            path_to_source_file_history_folder = os.getcwd() + '/source_files/' + os.path.basename(found_breakpoint[1])

            # if source file not in history folder, then copy it
            if not os.path.isfile( path_to_source_file_history_folder ):

                os.system('echo Source file ' + os.path.basename(found_breakpoint[1]) + ' not in history folder. It will be copied and analysed on next run!')
                if not os.path.exists(os.getcwd() + '/source_files'):
                    os.makedirs(os.getcwd() + '/source_files')
                shutil.copyfile(found_breakpoint[1], os.getcwd() + '/source_files/' + os.path.basename(found_breakpoint[1]))


            # Else, compare it with actual from path
            else:

                # Open both files
                with open(found_breakpoint[1]) as file_1:
                    new_source_file = file_1.readlines()

                with open(path_to_source_file_history_folder) as file_2:
                    old_source_file = file_2.readlines()

                # GET DIFFERENCE BETWEEN SOURCE FILES ( SAVED ONE VS. NEW ONE )
                # =============================================================
                diff = difflib.context_diff(old_source_file, new_source_file)

                # Append results in lists
                diff_list = []
                for l in diff:
                    tempResult = findLineMarker(l)
                    if tempResult is not None:
                        diff_list.append( [ int(tempResult.group(2)), int(tempResult.group(3)) ] )


                if len(diff_list) > 2:

                    # Separate into another list 2 by 2 chunks from original diff list
                    n = 2
                    seaparated_list = [diff_list[i:i + n] for i in range(0, len(diff_list), n)]
                else:
                    # if there is only one difference, then append it into a list
                    seaparated_list = []
                    seaparated_list.append(diff_list)

                # END OF DIFFERENCE BETWEEN SOURCE FILES =======================

                # ANALYZE OLD SOURCE FILE VS NEW SOURCE FILE AND CREATE A NEW LIST WITH BREAKPOINTS
                # ==============================================================

                new_list_with_new_breakpoints = ['','','','','','']


                # if any difference has been found
                if len(diff_list) != 0:
                    # Copy information about test name, source file path and function name
                    new_list_with_new_breakpoints[0:3] = found_breakpoint[0:3]

                    check_if_files_updated = True


                    #print(found_breakpoint) # FOR DEBUG PURPOSE
                    #print(seaparated_list) # FOR DEBUG PURPOSE

                    # calculate line number of function definition
                    calculated_line_number_of_function_definition = 1

                    for line in new_source_file:
                        if 'Current revision:' in line:
                            new_list_with_new_breakpoints[5] = line.replace('Current revision:', 'Source file revision number:' )


                        calculated_line_number_of_function_definition += 1
                        # if function definition has been found, then exit and retain number of lines
                        if ( (found_breakpoint[2] + '(' in line ) or (found_breakpoint[2] + ' (' in line )  ) and ';' not in line:
                            break

                    # Calculate breakpoint
                    calculated_breakpoint  = calculated_line_number_of_function_definition + found_breakpoint[4]

                    # for every difference found in code
                    for group in seaparated_list:

                        # BREAKPOINT LINE NUMBER CHECK
                        if calculated_breakpoint >= group[0][0] and calculated_breakpoint <= group[1][1]:
                            # Replace offset and breakpoint line with error messages
                            new_list_with_new_breakpoints[3] = 'ERROR:LINE BKP MODIFIED IN SOURCE CODE'

                        else:
                            # Write in list breakpoint line
                            new_list_with_new_breakpoints[3] = calculated_breakpoint

                        # OFFSET NUMBER CHECK

                        # Calculate if interval between function definition and breakpoint is in difference list
                        overlap_result = getOverlap( [ min(min(group)), max(max(group)) ], [calculated_line_number_of_function_definition, calculated_breakpoint])

                        if overlap_result == 0:
                            # if no overlap between intervals found, then keep old offset
                            new_list_with_new_breakpoints[4] = found_breakpoint[4]
                        else:
                            new_list_with_new_breakpoints[4] = found_breakpoint[4] + ( group[1][1] - group[0][1] )
                            new_list_with_new_breakpoints[3] = calculated_breakpoint + ( group[1][1] - group[0][1] )

                        print('Source file ' + new_list_with_new_breakpoints[1] + ' has been modified between lines: ' + str(group[1]) )
                        #print(new_list_with_new_breakpoints) # FOR DEBUG PURPOSE

                        new_breakpoints_list_per_file.append(new_list_with_new_breakpoints)

                else:
                    # if there are no difference between new source code and old one, then copy breakpoints
                    new_list_with_new_breakpoints = found_breakpoint
                    new_breakpoints_list_per_file.append(new_list_with_new_breakpoints)

        new_list_with_breakpoints_per_all_files.append(new_breakpoints_list_per_file)

    # ================ END OF ANALYZE SOURCE FILES AND COSTRUCT LIST WITH MODIFICATIONS

    # ================ MODIFY TS SCRIPTS PART ============================

    # Check if updates has been made on source code
    if check_if_files_updated != False:

        # ================SEARCH ALL BREAKPOINTS AND CONSTRUCT A LIST ========
        for test_result_file in new_list_with_breakpoints_per_all_files:

            # FIND TS SCRIPT BY REPLACING EXTENSION OF TEST RESULT WITH TS EXTENSION AND SEARCH TS SCRIPT
            # Replace .xml extension with .ts to find script source code
            ts_script_name = test_result_file[0][0].replace('.xml', '.ts')

            # find path of script
            path_to_ts_script = find(ts_script_name, path_to_integration_test_files )

            # open script for read it
            with open(path_to_ts_script, 'r', encoding="utf8", errors='ignore') as file:
                temp_content_from_ts = file.readlines()

            # GET ALL PAIRS WITH FUNCTION AND OFFSET FROM TS SCRIPT
            breakpoint_list_per_file = []
            # search in script where function is called with breakpoints
            for line in temp_content_from_ts:
                breakpoint_temp_group = ['','']

                if 'debugger_setRelativeFunctionBpAtLine' in line:
                    # Extract line with breakpoint
                    regex_result = re.search("[(](.*)[)]", line)

                    # Extract function name from that line and offset number
                    function_name, offset = regex_result.group(0).split(",")

                    # Detele unnecesary characters from string
                    function_name = function_name.replace('(','')
                    offset = offset.split(')')[0].replace(' ','')

                    # Get group of function name and offset from ts script
                    breakpoint_temp_group = function_name, offset

                    # append group in list
                    if breakpoint_temp_group not in breakpoint_list_per_file:
                        breakpoint_list_per_file.append(breakpoint_temp_group)



            # FROM ALL PAIRS FOUND IN UPPER FOR, FIND THEM DEFINION IN UPPER PART OF TS SCRIPT
            # define list for geeting lines where offset is defined

            # counter used to iterate throu list of breakpoints
            test_result_breakpoint_counter = 0

            # define variables to search in lines
            breakpoint_counter = 0

            # iterate throu all file
            for line in temp_content_from_ts:

                # OFFSET WRITE PART
                # if line where offset is defined has been found
                if ( breakpoint_list_per_file[breakpoint_counter][1] in line ) and ( has_numbers(line) != False ) and ( 'tRelativeBreakPointParam' not in line ):

                    # HERE THE NEW OFFSET IS WRITTEN IN FILE
                    new_string_line = line[0: line.find('=') + 1] + str( test_result_file[test_result_breakpoint_counter][4]) + line[line.find(';'):]
                    temp_content_from_ts[temp_content_from_ts.index(line) ] = new_string_line


                    # Increment counter throu breakpoints
                    if test_result_breakpoint_counter + 1 < len(test_result_file):
                        test_result_breakpoint_counter += 1

                    # increment counter throu breakpoints group
                    if breakpoint_counter + 1 < len(breakpoint_list_per_file):
                        breakpoint_counter += 1


                if 'Test Notes: ' in line and len(test_result_file[test_result_breakpoint_counter]) == 6:
                    temp_content_from_ts[temp_content_from_ts.index(line)] = 'Test Notes: ' + test_result_file[test_result_breakpoint_counter][5]

            # WRITE MODIFICATIONS IN SCRIPT
            # Modify entire ts script file
            f = open(ts_script_name, "w", encoding="utf8", errors='ignore') # for getting ts scripts here: ts_script_name
            f.writelines(temp_content_from_ts)
            f.close()

        # print(find_offset_line_in_ts_script( content_of_ts_script=
    else:
        os.system("echo Updates has not been made in source code, nothing to modify! ")



    # ================ END OF SEARCH ALL BREAKPOINTS AND CONSTRUCT A LIST ========

    time.sleep(5)



if __name__ == '__main__':
    main()