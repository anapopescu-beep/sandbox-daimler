import docx2txt
import glob
import re
import os
import difflib
import os.path
import argparse


def main():

    parser = argparse.ArgumentParser()
    parser.add_argument('-i', '--input-path', help="Path to Associated_Documents Folder", required=True)
    parser.add_argument('-o', '--output-path', help="Path to output generated file", required=True)
    args = parser.parse_args()

    path_to_components = 'S:'

    path_to_docx_files = args.input_path
    output_path_generated = args.output_path

    if(path_to_docx_files[-1] != '/' or path_to_docx_files[-1] != r'"\"' ):
            path_to_docx_files += '/'

    # =========== PROCESSING CONFIGURATION FILE ===========
    config_file_structure = ('--- LIST OF MODULES_TO IGNORE ---\n'
                             'END OF LIST OF MODULES TO IGNORE\n'
                             '\n'
                             '--- LIST OF FUNCTIONS TO IGNORE ---\n'
                             'END OF LIST OF FUNCTIONS TO IGNORE\n'
                             '\n'
                             '--- LIST OF FUNCTIONS WITH DIFFERENT NAME FROM ARCHITECTRUE DOCUMENT ---\n'
                             'END OF LIST WITH DIFFERENT FUNCTIONS FROM ARCHITECTURE DOCUMENT\n'
                             '\n'
                             '--- LIST OF FUNCTIONS TO ADD IN GENERATED SCRIPT ---\n'
                             'END OF LIST OF FUNCTIONS TO ADD IN GENERATED SCRIPT\n')

    # Initialize lists
    modules_to_ignore_list = []
    functions_to_ignore_list = []
    functions_with_different_name = []
    functions_to_add = []

    # if config file exist
    if os.path.exists('configuration_file.txt'):

        # Get data from it
        with open("configuration_file.txt", "r+") as config_file_txt:
            list_of_data_config_file = config_file_txt.readlines()

        # Separate data intro lists
        for index in range(0, len(list_of_data_config_file)):

            # EXTRACT MODULE NAMES TO IGNORE FROM CONFIG FILE
            modules_to_ignore_list = list_of_data_config_file[list_of_data_config_file.index('--- LIST OF MODULES_TO IGNORE ---\n')+1:list_of_data_config_file.index('END OF LIST OF MODULES TO IGNORE\n')]
            # delete all new lines and blank elements
            modules_to_ignore_list =  list(map(lambda s: s.strip(), modules_to_ignore_list))
            modules_to_ignore_list = [x for x in modules_to_ignore_list if x != '']

            # EXTRACT FUNCTIONS NAMES TO IGNORE FROM CONFIG FILE
            functions_to_ignore_list = list_of_data_config_file[list_of_data_config_file.index('--- LIST OF FUNCTIONS TO IGNORE ---\n')+1:list_of_data_config_file.index('END OF LIST OF FUNCTIONS TO IGNORE\n')]
            # delete all new lines and blank elements
            functions_to_ignore_list =  list(map(lambda s: s.strip(), functions_to_ignore_list))
            functions_to_ignore_list = [x for x in functions_to_ignore_list if x != '']

            # EXTRACT DIFFERENT NAME FROM CONFIG FILE
            functions_with_different_name = list_of_data_config_file[list_of_data_config_file.index('--- LIST OF FUNCTIONS WITH DIFFERENT NAME FROM ARCHITECTRUE DOCUMENT ---\n')+1:list_of_data_config_file.index('END OF LIST WITH DIFFERENT FUNCTIONS FROM ARCHITECTURE DOCUMENT\n')]
            # delete all new lines and blank elements
            functions_with_different_name =  list(map(lambda s: s.strip(), functions_with_different_name))
            functions_with_different_name = [x for x in functions_with_different_name if x != '']

            # EXTRACT FUNCTION TO ADD FROM CONFIG FILE
            functions_to_add = list_of_data_config_file[list_of_data_config_file.index('--- LIST OF FUNCTIONS TO ADD IN GENERATED SCRIPT ---\n')+1:list_of_data_config_file.index('END OF LIST OF FUNCTIONS TO ADD IN GENERATED SCRIPT\n')]
            # delete all new lines and blank elements
            functions_to_add =  list(map(lambda s: s.strip(), functions_to_add))
            functions_to_add = [x for x in functions_to_add if x != '']


    else:
        os.system('echo configuration_file.txt does NOT exist! It will be created, please fill it with restrictions.')
        textfile = open("configuration_file.txt", "w")
        for element in config_file_structure:
           textfile.write(element)
        textfile.close()

    # ===========END OF PROCESSING CONFIGURATION FILE ===========


    # =========== PROCESSING ALL DOCX FILES IN LIST ===========

    # Search in path all docx files and append their name and path intro a list
    list_with_docx_files = glob.glob(path_to_docx_files + "*.docx")

    # Initialize list used to append all modules with functions to it
    list_with_modules = []

    # For every file in that list
    for file in list_with_docx_files:

        # Process the file as text input
        all_text_from_docx_file = docx2txt.process(file)

        # Initialize list where functions from a single file will fill it
        list_with_functions_from_a_single_file = []

        # Module name extracted from file
        module_name_from_file = file[len(path_to_docx_files):file.find('-')-1]

        # Exctract from entire file path and name only module name and append it into initialised list
        list_with_functions_from_a_single_file.append(module_name_from_file)

        content = []
        for line in all_text_from_docx_file.splitlines():
            # This will ignore empty/blank lines.
            if line != '':
                # Append to list
                content.append(line)

        # For a line in all text extracted from a docx file
        for line in content:
            # Check if module name is in function name
            if '(' in line and ')' in line and '_' in line :

                # apply a regex search on all lines
                regex_result = re.search("(\w+ )(\w+)(\s*\(.*\).*)", line)

                # if found something
                if regex_result != None:
                    if module_name_from_file.lower()[0:-1] in str(regex_result.group(2)).lower() or 'com' in str(regex_result.group(2)).lower() or 'nm' in str(regex_result.group(2)).lower() and '_' in str(regex_result.group(2)):
                        # exctract and convert to string
                        extracted_function_name = str(regex_result.group(2))

                        # append in list for a single file functions
                        list_with_functions_from_a_single_file.append(extracted_function_name)

        # Append module with it's functions to big list
        list_with_modules.append(list_with_functions_from_a_single_file)

    # =========== END OF PROCESSING ALL DOCX FILES IN LIST ===========

    # MATCH FUNCTION
    # ENTER IN EVERY SOURCE FILE AND SEARCH FUNCTION NAME
    # =========== PROCESSING ALL SOURCE FILES IN LIST ===========

    # this list will contain every line from every .c and .h file from entire project
    sources_file = []

    # define search in path
    search_path = path_to_components
    # search_path = path_to_components + '/'  + module[0][0:-1] # Here is defined to search for a function name only in specific module

    for root, dirs, files in os.walk(search_path):
        for file in files:
            # If found a source file
            if (file.endswith(".c") or file.endswith(".h")):
                # Opens it and read lines from it
                with open(os.path.join(root, file), 'r+') as file:
                    sources_file += file.readlines()

    # for debugging porpuses, if it's needed to generate a txt file that contains all code extracted from all .c and .h files from entire project
    
    # textfile = open("debug_file.txt", "w")
    # for element in sources_file:
    #    textfile.write(element)
    # textfile.close()

    # define list with searched in source code functions name
    improved_list_with_modules = []

    # Search in that big list
    for module in list_with_modules:

        # Ignore module if is in list to ignore
        if module[0] not in modules_to_ignore_list:

            # define new list with matched functions names from code
            improved_list_of_functions = []

            # append in list on first position module name
            improved_list_of_functions.append(module[0])

            # for every function in list
            for function in module[1:]:

                # If function is not in list to ignore
                if function not in functions_to_ignore_list:

                    # Search if function is not in list of functions with another name
                    if any(function in s for s in functions_with_different_name):
                        # if it has a different name, then extract it
                        overwrite_function = [s for s in functions_with_different_name if function in s]

                        # extract new name from entire line from configuration file
                        overwrite_function = overwrite_function[0][overwrite_function[0].index(':')+1:]

                        # append new name in list
                        improved_list_of_functions.append(overwrite_function)
                    else:
                        matched = []
                        # search a match function in every line of source file
                        # matched = difflib.get_close_matches(function, sources_file, cutoff=0.3)

                        for line in sources_file:
                            if function in line:
                                matched.append(re.search(function, line).group(0))

                        # if a matched function has been found and it hasn't been appended already in list
                        if ( len(matched) != 0 and matched[0] not in improved_list_of_functions):
                            improved_list_of_functions.append(matched[0])
                        else:
                            # not found any function in source code, print message
                            os.system('echo Function ' + function + ' from module ' + module[0] + ' has not been found in source code!')

            # construct improved list
            improved_list_with_modules.append(improved_list_of_functions)

    # =========== END OF PROCESSING ALL SOURCE FILES IN LIST ===========

    # =========== Construct function to test list ===========

    function_to_test_list = ('/* Function name used to place a breakpoint */ \n'
                             'var CFGc_CallingFunctionToTest_Array = [ \n')

    counter_for_function_names = 0

    # Write an enter after every module
    function_to_test_list += '\n'

    # Write functions in script from config file list
    if len(functions_to_add) != 0:

        # Write Antet to script
        string_to_append = '/* Functions to add from configuration file module */ \n'
        function_to_test_list += string_to_append

        for function in functions_to_add:
            string_function_to_append = '"' + function + '", \n'
            function_to_test_list += string_function_to_append
            counter_for_function_names += 1

        # Write an enter after every module
        function_to_test_list += '\n'

    # Write functions in script from architecture generated list
    for module in improved_list_with_modules:

        # Write module name
        string_to_append = '/* Functions from ' + module[0] + ' module */ \n'
        function_to_test_list += string_to_append

        # Write function name
        for function in module[1:]:
            string_function_to_append = '"' + function + '", \n'
            function_to_test_list += string_function_to_append
            counter_for_function_names += 1
        # Write an enter after every module
        function_to_test_list += '\n'

    # Replace last ',' with ']'
    last_char_index = function_to_test_list.rfind(",")
    function_to_test_list = function_to_test_list[:last_char_index] + "]" + function_to_test_list[last_char_index + 1:]

    # add final variable that contains number of all functions
    add_number_of_all_functions = ("/* Number of all functions to iterate */ \n"
                                   "var number_of_all_functions = " + str(counter_for_function_names) + "; \n")
    function_to_test_list += add_number_of_all_functions
    function_to_test_list += '\n'

    # =========== END OF Construct function to test list ===========

    # =========== Construct preconditions to test list ===========
    # define preconditions enviorement
    preconditions_call_ts = ('/* CALL PRECONDITIONS CONFIG SCRIPT ( if exist ) */ \n')

    preconditions_function_name = 'Preconditions_Check_If_Function_Is_Called_In_Config_File'

    preconditions_function_construct = ('/* DEFINE FUNCTION TO CHECK IF PRECODINTIONS EXIST */ \n')

    preconditions_function_call = ('         /* CALL PRECONDITIONS Function ( if preconditions ts config exist ) */ \n')


    # Check file exist
    if os.path.exists(os.path.join(output_path_generated + '/Config', "ARCH_TEST_OS_Application_Call_Coverage_Preconditions.ts")) != 0:

        # -------------- HERE IS CALLED ID SCRIPT PRECONDITIONS CONFIG ------------
        # Call in generated ts at beginning coverage script preconditions, if exist
        preconditions_call_ts += 'CALL(Config/ARCH_TEST_OS_Application_Call_Coverage_Preconditions.ts); \n'

        # ------------ HERE A GENERIC FUNCTION TO CALL PRECONDITIONS IS CREATED ----
        # Open it and append it's contains in a big list
        with open(os.path.join(output_path_generated + '/Config', "ARCH_TEST_OS_Application_Call_Coverage_Preconditions.ts"), "r+") as config_file:
            coverage_script_preconditions_config_list = config_file.readlines()

        # If there are some preconditions writed in config file
        if len(coverage_script_preconditions_config_list) != 0:
            # define function
            preconditions_function_construct += ('/*------------------------------------------------------------------------------ \n'
                                                 '                              LOCAL FUNCTIONS \n'
                                                 '------------------------------------------------------------------------------*/ \n')

            preconditions_function_construct += "function " + preconditions_function_name + '(strFunctionFromIteration:String) \n'
            preconditions_function_construct += '{ \n'


        # For every line in list
        for line in coverage_script_preconditions_config_list:
            # if a function definition is detected
            if 'function' in line:
                # extract it's name
                extract_function_name_from_function_definition = line[ line.index('Preconditions_')+len('Preconditions_') : line.index('(')]
                # construct precondition call
                called_precondition = line[ line.index('function ')+len('function ') : line.index('(') ] + '();\n'

                # Construct a mechanism to check if a function is called in iteration
                preconditions_function_construct += '   ' + 'if ( "' + extract_function_name_from_function_definition + '" == strFunctionFromIteration ) \n'
                preconditions_function_construct += '   {\n'
                preconditions_function_construct += '      ' + called_precondition
                preconditions_function_construct += '   }\n'

        # End of preconditions function definition
        preconditions_function_construct += '} \n'

        # ------ HERE, GENERIC FUNCTION CREATED IN UP-LINES IS CALLED ------
        # If a precondition function is constructed
        if len(preconditions_function_construct) > 2:
            # Then call it
            preconditions_function_call += '         '  + preconditions_function_name + '(CFGc_CallingFunctionToTest_Array[iterating_functions_counter]); \n'

    else:
        os.system("echo Preconditions config file: coverage_script_preconditions_config.ts does NOT exist! No preconditions added in generated script! ")

    # =========== END OF Construct DID to test list ===========

    # WRITE IN FILE PART

    file_antet = ("/***********************************AUTOLIV ELECTRONICS document******************************** \n"
                  "Test case ID: PYTHON GENERATED COVERAGE SCRIPT \n"
                  "Result Test: \n"
                  "************************************************************************************************ \n"
                  "Requirement under test: NONE \n"
                  "Description of the requirement: NONE \n"
                  "************************************************************************************************ \n"
                  "Equipment: PowerSupply, CanCaseXL, MockUp, IC5000 debugger \n"
                  "Test Notes:  \n"
                  "Full Automation: Yes \n"
                  "Global Result Assignment: Neeva \n"
                  "************************************************************************************************/ \n"
                  "/********************************************************************************/ \n" 
                  "/*                             Format test script                               */ \n" 
                  "/********************************************************************************/ \n"
                  "/*------------------------------------------------------------------------------ \n"
                  "                               IMPORT LIBRARY \n"
                  "------------------------------------------------------------------------------*/ \n"
                  "CALL(/../../ProjectLib_Development/SBE_Configuration.ts); \n" + preconditions_call_ts +
                  "\n" )


    file_constats = ("/*------------------------------------------------------------------------------ \n"
                  "                                CONSTANTS \n"
                  "------------------------------------------------------------------------------*/ \n"
                  "\n" 
                  '/* Constant for the tests */ \n'
                  "const cTEST_OK = true; \n"
                  "const cTEST_NOK = false; \n"
                  "\n"   
                  "/* Mandatory constants */ \n"
                  'const cENV_NON_INITIALIZED = "NO_INIT";  \n'
                  "const cENV_NOK = false; \n"
                  "const cException_Catched = true; \n"
                  "const NO_CYCLE = 255; \n"
                  "\n"    
                  "/* Power supply configuration for this test */ \n" 
                  "/* 5 means that a logical power supply is OK */ \n" 
                  "/* 50 means that a power supply which can support 40A shall be used */ \n"
                  'const CFGc_MinCurrentToRunTest: String = "50";  \n'
                  "\n"   
                  "/* WinIDEA intialization options */ \n"
                   'const CFGc_FlashMode: String  = "FlashOn"; /* [FlashOn, FlashOff] */ \n'
                   'const CFGc_ResetMode: String  = "ResetOn"; /* [ResetOn, ResetOff] */ \n'
                   'const CFGc_RunMode: String    = "RunOn"; /* [RunOn, RunOff] */ \n' 
                   "\n" )

    file_variables = ("/*------------------------------------------------------------------------------ \n"
                      "                                VARIABLES \n"
                      "------------------------------------------------------------------------------*/ \n"
                      "/* Variable used to check the test initialization phase */ \n"
                      "var vRetFunction = null; \n"
                      "/* Boolean used to check if the test is successful */ \n"
                      "var bRetFunction: Boolean = false; \n"
                      "/* Variable for breakpoint result*/ \n"
                      "var tRelativeBreakPointParam; \n"
                      "/* Variable for offset of all functions */ \n"
                      "var CFGc_FunctionOffsetToTest = 0; \n"
                      "/* Variable for iterating in array list */ \n"
                      "var iterating_functions_counter = 0 \n" )



    core_test_envoiment = ('/*------------------------------------------------------------------------------ \n'
                           '                                    Core Test \n'
                           '------------------------------------------------------------------------------*/\n'
                           'try \n'
                           '{ \n'
                           '   /*------------------------------------------------------------------------------\n'
                           '                           INITIALIZATION ENVIRONMENT \n'
                           '   ------------------------------------------------------------------------------*/ \n'
                           '   /**** This function is parameterizable see PP4G LIBRARY (ISYSTEMAPI.ts) *********/ \n'
                           '   /****** WARNING : check optional parameter of the next function :its very IMPORTANT ***********/ \n'
                           '   CommentStep("Initialize environment"); \n'
                           '   vRetFunction = SwDevLib_InitBenchEnvironmentAndPowerSupply(CFGc_FlashMode, CFGc_ResetMode, CFGc_RunMode, CFGc_MinCurrentToRunTest); \n'
                           '   if(vRetFunction != cENV_NON_INITIALIZED && vRetFunction != cENV_NOK) \n'
                           '   { \n'
                           '\n '
                           '      /*------------------------------------------------------------------------------ \n'
                           '                              EXECUTION TEST \n'
                           '      ------------------------------------------------------------------------------*/ \n'
                           '\n'
                           '      /* Clear all breakpoints */ \n'
                           '      CommentStep("Clear all breakpoints"); \n'
                           '      RESULT.ExpectTestResult("Delete all breakpoints",debugger_deleteAllBreakpoints(),true); \n'
                           '\n'
                           '      debugger_run(); \n'
                           '      CommentStep("Wait ECU to wake up"); \n'
                           '      Wait(5000); \n'
                           '\n'
                           '      RESULT.ExpectTestResult("Run application", debugger_run(), true); \n'
                           '      sendCANDiagRequest("SOFT RESET", "0x11 0x03", "0x51 0x03"); \n'
                           '      CommentStep("Wait ECU to wake up"); \n'
                           '      waitFrameReception(); \n'
                           '\n'
                           '      /* CALL LIST OF FUNCTION TO TEST */ \n'
                           '      for ( iterating_functions_counter = 0; iterating_functions_counter < number_of_all_functions; iterating_functions_counter++ ) \n'
                           '      { \n'
                           '\n'
                           '         CommentStep("Place a breakpoint in the tested function: " + CFGc_CallingFunctionToTest_Array[iterating_functions_counter] );  \n'
                           '         tRelativeBreakPointParam = debugger_setRelativeFunctionBpAtLine(CFGc_CallingFunctionToTest_Array[iterating_functions_counter], CFGc_FunctionOffsetToTest);  \n'
                           '\n' + preconditions_function_call +
                           '\n'
                           '         RESULT.InsertComment("Check if the debugger is stopped on the correct function"); \n'
                           '         RESULT.ExpectTestResult("Wait until return is reached", debugger_waitWhileRunning(4000), true);  \n'
                           '         RESULT.ExpectTestResult(CFGc_CallingFunctionToTest_Array[iterating_functions_counter] + " is reached", debugger_isCPUStoppedAtAddress(tRelativeBreakPointParam[3]), true); \n'
                           '\n'
                           '         RESULT.ExpectTestResult("Remove all breakpoint ", debugger_deleteAllBreakpoints(), true); \n'
                           '         RESULT.ExpectTestResult("Reset the debugger", debugger_reset(), cTEST_OK ); \n'
                           '         RESULT.ExpectTestResult("Run application", debugger_run(), true); \n'
                           '         Wait(1000); \n'
                           '       } \n' )

    deinitialiszation_envoiment = ('\n'
                           '      RESULT.InsertComment("100% call coverage achieved for configured scope!"); \n'
                           '      /* Clear all breakpoints */ \n'
                           '      CommentStep("Clear all breakpoints"); \n'
                           '      RESULT.ExpectTestResult("Delete all breakpoints",debugger_deleteAllBreakpoints(),true); \n'
                           '      /*------------------------------------------------------------------------------ \n'
                           '                              DEINITIALIZATION ENVIRONMENT \n'
                           '      ------------------------------------------------------------------------------*/ \n'
                           '      RESULT.ExpectTestResult("Reset the debugger", debugger_reset(), cTEST_OK ); \n'
                           '\n'
                           '      RESULT.ExpectTestResult("Close environment test", winIDEAWorkspace_closeDiscard(), cTEST_OK ); \n'
                           '   } \n'
                           '   else \n'
                           '   { \n'
                           '      winIDEAWorkspace_closeDiscard(); \n'
                           '   } \n'
                           '} \n'
                           'catch(exError) \n'
                           '{ \n'
                           '   RESULT.ExpectTestResult("Test failed about exception occurs :"+exError, \n'
                           '      cException_Catched, \n'
                           '      false \n'
                           '   ); \n'
                           '   CommentStep("Close test environment"); \n'
                           '   RESULT.ExpectTestResult("Close environment test", \n'
                           '      winIDEAWorkspace_closeDiscard(), \n'
                           '      cTEST_OK \n'
                           '   ); \n'
                           '} \n')

    # Create a file to write
    generated_ts_engine = open(  os.path.join(output_path_generated, "ARCH_TEST_OS_Application_Call_Coverage.ts") , "w")

    # Write antet into it
    generated_ts_engine.writelines(file_antet)

    # Write constants into it
    generated_ts_engine.writelines(file_constats)

    # Write variables into it
    generated_ts_engine.writelines(file_variables)

    # Write functions into it
    generated_ts_engine.writelines(function_to_test_list)

    # Write Function Definition Into It
    generated_ts_engine.writelines(preconditions_function_construct)

    # Write core test part
    generated_ts_engine.writelines(core_test_envoiment)

    # Write core test part
    generated_ts_engine.writelines(deinitialiszation_envoiment)

if __name__ == '__main__':
    main()