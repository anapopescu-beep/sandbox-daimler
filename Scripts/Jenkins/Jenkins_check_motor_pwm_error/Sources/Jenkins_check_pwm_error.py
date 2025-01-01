"""Jenkins_check_pwm_error.py: Used to extract failed steps from ARIA xml results
Parameters has been given from argparse command line interface.
As input, it is needed an xml file to be parsed
As output, it is needed a path to generate an txt file
"""

__author__ = 'Ardeleanu Lucian'
__copyright__ = "Copyright 2021, Autoliv Electronic"
__version__ = "1.0"
__email__ = 'lucian.ardeleanu@autoliv.com'
__status__ = 'Released'

import re
import argparse

# ===============================================================
# FUNCTION USED TO PARSE A GIVEN LINE AND EXTRACT SPECIFIC STRING
# INPUT ARGUMENT: STRING
# OUTPUT ARGUMENT: STRING
# ===============================================================
def get_error_value(input_line):
    regex_result = re.search("<Action Name=.(.*).>", str(input_line))
    if regex_result != None:
        return(regex_result.group(1))

# ===============================================================
# FUNCTION USED TO PARSE A GIVEN LINE AND EXTRACT SPECIFIC STRING
# INPUT ARGUMENT: STRING
# OUTPUT ARGUMENT: STRING
# ===============================================================
def get_expected_value(input_line):
    regex_result = re.search("<Expected>(.*)</Expected>", str(input_line))
    if regex_result != None:
        return(regex_result.group(1))

# ===============================================================
# FUNCTION USED TO PARSE A GIVEN LINE AND EXTRACT SPECIFIC STRING
# INPUT ARGUMENT: STRING
# OUTPUT ARGUMENT: STRING
# ===============================================================
def get_obtained_value(input_line):
    regex_result = re.search("<Obtained>(.*)</Obtained>", str(input_line))
    if regex_result != None:
        return(regex_result.group(1))


# ===============================================================
# MAIN FUNCTION OF SCRIPT
# INPUT ARGUMENT: NONE
# OUTPUT ARGUMENT: NONE
# ===============================================================
def main():

    parser = argparse.ArgumentParser()
    parser.add_argument('-i', '--input-path', help="Path to ARIA xml result file", required=True)
    parser.add_argument('-o', '--output-path', help="Path where to generate .txt file with error. Write it with filename and extension!", required=True)
    args = parser.parse_args()

    # PARSE XML AND EXTRACT DATA ==========================================

    # Get input path to variable to open file
    path_to_file_to_process = args.input_path

    # Define a list that contains all failed steps from an xml file
    list_with_error_strings_per_file = []

    # if given file is an xml result-type file
    if (path_to_file_to_process.endswith(".xml")):

        # Open file as read only
        with open(path_to_file_to_process, 'r', encoding="utf8", errors='ignore') as file:
            xml_content = file.readlines()

        # For every line of opened file
        for line_counter in range(0, len(xml_content)):

            # If failed step was found in parsing xml content
            if "<Result>Failed</Result>" in xml_content[line_counter]:

                # Extract needed information from xml result step
                error_name = get_error_value(xml_content[line_counter - 4])
                expected_value = get_expected_value(xml_content[line_counter - 2])
                obtained_value = get_obtained_value(xml_content[line_counter - 1])

                # Create a string with complete error message
                string_with_failed_result = "Error Name: " + error_name + "; Expected value: " + expected_value + "; Obtained value: " + obtained_value

                # append created string in list of strings
                if string_with_failed_result not in list_with_error_strings_per_file:
                    list_with_error_strings_per_file.append(string_with_failed_result)

        if list_with_error_strings_per_file == []:
            string_with_no_errors = "No failed step found in test result!"
            list_with_error_strings_per_file.append(string_with_no_errors)

    # END OF PARSE XML AND EXTRACT DATA ==========================================

    # WRITE IN TXT FILE GIVEN RESULT ===================================

    # Initiate a variable with path where to generate txt file
    path_to_generated_txt_file = args.output_path

    # Open a new file in write mode
    file = open(path_to_generated_txt_file, "w")

    # construct string to be written in txt file, ONLY FIRST FAILED RESULT FROM ENTIRE XML FILE
    string_to_be_written_in_file = "PWM_ERROR=" + list_with_error_strings_per_file[0]

    # Write constructed string in txt file
    file.write(string_to_be_written_in_file)

    # Close it
    file.close()

    # END OF WRITE IN TXT FILE GIVEN RESULT ===================================

if __name__ == '__main__':
    main()