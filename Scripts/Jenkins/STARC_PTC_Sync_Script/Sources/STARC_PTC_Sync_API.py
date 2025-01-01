# Imports
import requests
import json
import yaml
import os
import subprocess
import csv
import sys

def Connect_to_STARC_Database(STARC_Base_URL, STARC_App_ID, STARC_App_Token ):

    # ======= SET URL AND API KEYS TO CONNECT TO STARC =======
    auth_url = STARC_Base_URL + "/auth"

    payload = json.dumps({
      "application_id": STARC_App_ID,
      "application_token": STARC_App_Token
    })

    # Set Headers
    headers = {
      'Content-Type': 'application/json',
    }

    # Get a response from server
    response = requests.request("POST", auth_url, headers=headers, verify=False, data=payload).json()

    for key, value in response.items():
        if key == 'sessionID':
            print('Login Succesfully in STARC Database!')
            return value
        else:
            return 'Could not connect to STARC Database! No Session ID Generated!'

# ===============================================================
# FUNCTION USED TO LOGIN IN PTC
# INPUT ARGUMENT: STRING, STRING
# OUTPUT ARGUMENT: NONE
# ===============================================================
def login_in_PTC(path_to_si, username, password):

    # Define flag if conected in PTC
    PTCLogIn_flag = 0

    # If not conected
    if (PTCLogIn_flag == 0):

        # Define output conected variable
        output_conected = 1

        # While not conected
        while (output_conected == 1):

            # Command to connect
            # print(path_to_si + "connect --hostname='ALVA-MKS01.alv.autoliv.int' --port='7001' --user=" + username + " --password=" + password)

            # Connect
            output_conected = os.system(path_to_si + "connect --hostname='ALVA-MKS01.alv.autoliv.int' --port='7001' --user=" + username + " --password=" + password)

        # Change flag
        PTCLogIn_flag = 1
        print('Login Succesfully in PTC account!')

def Query_STARC_Database(session_ID, STARC_Querry, STARC_Base_URL):

    # Set query URL
    query_url = STARC_Base_URL + "/starc/v3/items/query"

    # Define an empty dictionary
    querry_dictionary = {}

    # Add querry in it
    querry_dictionary["queryString"] = STARC_Querry
    querry_dictionary["page"] = 1
    querry_dictionary["pageSize"] = 100

    # Create a payload in json format
    query_payload = json.dumps(querry_dictionary)

    # Set Query Headers
    query_headers = {
      'Content-Type': 'application/json'
    }

    # Set session ID Key
    query_headers['STARC_SESSION'] = session_ID

    # Request data from STARC in dictionary
    response_query_dictionary = requests.request("POST", query_url, headers=query_headers, data=query_payload, verify=False).json()

    # Return received dictionary
    return response_query_dictionary

def Query_PTC_Database(string_in_title, query, path_to_IM):

    # -------------- GET ALL ISSUE NUMBERS FROM GIVEN QUERY IN LIST  --------------
    # call function PTC to get member information
    batcmd = path_to_IM + " issues  --query='" + query + "'"

    # Run command
    subprocess_output = subprocess.run(batcmd, capture_output=True)

    # Check output
    if subprocess_output.returncode == 0:

        issue_list_unprocessed = subprocess_output.stdout.decode().splitlines()

        # Filter received issues into a list
        issue_list = []
        for issue in issue_list_unprocessed:
            try:
                issue_list.append(issue[ 0 : issue.index('\t')])
            except:
                print('Exception Occured while processing PTC Database:')
                print(subprocess_output)

        # ----------- GET ISSUES PROPERTIES FROM QUERRY -------------

        # Define a list of all issues properties from given querry
        list_of_all_issues_from_query = []

        for issue_number in issue_list:

            # ----------------------------- GET PTC ISSUE PROPERTIES ---------------------------------------------
            # call function PTC to get member information
            batcmd = path_to_IM + " viewissue --showTimeEntries --showAnnotations  " + issue_number

            # store in result output from cmd command executed
            subprocess_output = subprocess.check_output(batcmd)

            subprocess_output = subprocess_output.decode("utf-8",errors='ignore')

            # split all properties from one string into a list
            list_of_all_properties_per_issue = subprocess_output.splitlines()

            if ( any("Customer visible: Yes" in property for property in list_of_all_properties_per_issue) and any("State: (Analyzed)" in property for property in list_of_all_properties_per_issue) ) or any(('Issue Title:' in property and string_in_title in property) for property in list_of_all_properties_per_issue):
                if list_of_all_properties_per_issue not in list_of_all_issues_from_query:
                    list_of_all_issues_from_query.append(list_of_all_properties_per_issue)


        # Return big list with all issues from PTC
        return list_of_all_issues_from_query

    else:
        print('ERROR IN QUERRY PTC DATABASE:')
        print('EXIT CODE:', subprocess_output.returncode)
        print('COMMAND OUTPUT:', subprocess_output.stdout.decode())
        print('COMMAND ERROR:', subprocess_output.stderr.decode())
        sys.exit(1)

def Update_STARC_Issue_List_In_CSV(Path_to_csv, STARC_Database_Query_Dictionary, Allow_only_sync_allowed_items):

    # Define an empty item list
    item_list = []

    # extract all id trackers from STARC Database
    for key, value in STARC_Database_Query_Dictionary.items():

        # For debug purpose
        # print(key, ':', value)

        if key == 'items':

            # every item in value is a dictionary and value is a big list
            for item in value:

                # Check if items has Sync Allowed field set to YES or NO
                Sync_Allowed_var = False
                for prop in item['customFields']:
                    if prop['name'] == 'Sync Allowed':
                        if prop['values'][0]['name'] == 'Supplier External Tool':
                            Sync_Allowed_var = True

                if Allow_only_sync_allowed_items == True:
                    if Sync_Allowed_var == True:

                        # Define an empty item string
                        STARC_Item_List = ['', '', '', '']

                        # For every propery of an item
                        for item_key, item_value in item.items():

                            # For debug purposes
                            # print(item_key, ':', item_value)

                            # VALUES ARE ARRANGED AS FOLLOWS: [ STARC_Issue_ID, STARC_Issue_Status, STARC_Issue_Name ]
                            # add id and name into a string
                            if item_key == 'id':
                                STARC_Item_List[0] = item_value

                            if item_key == 'status':
                                for inner_key, inner_value in item_value.items():
                                    if inner_key == 'name':
                                        STARC_Item_List[1] = inner_value

                            if item_key == 'name':
                                STARC_Item_List[2] = item_value.replace(',',';')
                                STARC_Item_List[2] = STARC_Item_List[2].replace('"', '')

                            if item_key == 'description':
                                STARC_Item_List[3] = item_value.replace("\r\n", "")

                        # Append constructed string in list
                        item_list.append(STARC_Item_List)
                else:
                    # Define an empty item string
                    STARC_Item_List = ['', '', '', '']

                    # For every propery of an item
                    for item_key, item_value in item.items():

                        # For debug purposes
                        # print(item_key, ':', item_value)

                        # VALUES ARE ARRANGED AS FOLLOWS: [ STARC_Issue_ID, STARC_Issue_Status, STARC_Issue_Name ]
                        # add id and name into a string
                        if item_key == 'id':
                            STARC_Item_List[0] = item_value

                        if item_key == 'status':
                            for inner_key, inner_value in item_value.items():
                                if inner_key == 'name':
                                    STARC_Item_List[1] = inner_value

                        if item_key == 'name':
                            STARC_Item_List[2] = item_value.replace(',', ';')
                            STARC_Item_List[2] = STARC_Item_List[2].replace('"', '')

                        if item_key == 'description':
                            STARC_Item_List[3] = item_value.replace("\r\n", "")

                    # Append constructed string in list
                    item_list.append(STARC_Item_List)

    # print(item_list)

    # For debug purpose: MODIFY A STATE OF ITEM OR DELETE ITEM
    # print(item_list)
    # item_list[-1][1] = 'Another State'
    # del item_list[-1]
    # print(item_list)

    # A new issue has come
    # new_issue_arrived = [9999999, 'NEW', 'THIS ISSUE SHOULD UPDATE ANOTHER ISSUE','AUTOLIV ISSUE ID: 812241 Anotherbla bla bla ']
    # item_list.append(new_issue_arrived)

    # here, update description to check if arrived issue from STARC with a PTC id in it updates PTC issue from csv
    # item_list[1][3] = 'AUTOLIV ISSUE ID: 805443 Another issue to be created in STARC'

    # Open csv and extract it's contens into a list
    with open(Path_to_csv, 'r') as f:
        csv_file_lines = f.readlines()
    f.close()

    # Extract header row
    header_row = csv_file_lines[0].split(',')
    header_row = [header_title.replace('\n', '') for header_title in header_row]

    # Define a list to modify in csv
    new_csv_data_list = []

    # Add existing lines in new data list
    for line in csv_file_lines:
        list_from_line = line.split(",")
        list_from_line = [word.replace('\n', '') for word in list_from_line]
        new_csv_data_list.append(list_from_line)

    # Iterate in items
    for item in item_list:

        # Iterate in lines of csv file
        for line, line_index in zip(new_csv_data_list, range(0,len(new_csv_data_list))):

            # If item is found in list
            if  str(item[0]) in str(line[0]):

                # If item changed it's state
                if str(item[1]) != str(line[4]):

                    # Move state to last state
                    new_csv_data_list[line_index] = [line[0], line[1], line[4], line[3], str(item[1]), line[5], line[6], line[7],line[8] ]

        # If item has not been found in all csv list
        if not any(str(item[0]) in csv_line[0] and str(item[2]) in csv_line[7] for csv_line in new_csv_data_list):

            # Define a variable to check if issue has been updated
            updated_already = False

            # Iterate in all csv lines
            for line, line_index in zip(new_csv_data_list, range(0,len(new_csv_data_list))):

                # If a new starc issue has previously created by one of our PTC issues AND THERE IS NO ITEM ALREADY
                if '[AUTOLIV]' in item[2] and line[1] in item[2]:

                    # Then update in csv in PTC item
                    new_csv_data_list[line_index][0] = item[0]
                    new_csv_data_list[line_index][7] = item[2]

                    # And update variable
                    updated_already = True

            # If arrived issue has not created by one of our PTC issues
            if updated_already == False:

                # append this new issue in csv as a new issue

                # Construct a field to append
                field_to_append = [str(item[0]), '', '', '', str(item[1]), '', '', str(item[2]), '']

                # Add new field to list to write in csv
                new_csv_data_list.append(field_to_append)

    with open(Path_to_csv, 'w', newline='') as f:

        # Init object
        writer = csv.writer(f)

        # write the data
        writer.writerows(new_csv_data_list)

    # Close file
    f.close()


def Update_PTC_Issue_List_In_CSV(Path_to_csv, PTC_Database_Query_List, string_in_title):

    # Define a item list to fill in csv
    item_list = []

    # Extract from issue list only issue number, issue state and issue title
    for item in PTC_Database_Query_List:

        # Define a list where to store PTC item data per issue
        PTC_Item_List = ['', '', '', '']

        # Search Properties
        for property in item:

            # print(property)

            # Search Issue Number
            if 'ID:' in property[0:5]:
                PTC_Item_List[0] = property.replace('ID: ', '')

            # Search Issue State
            if 'State: ' in property[0:10]:
                PTC_Item_List[1] = property.replace('State: ', '')

            # Search Isssue Title
            if 'Issue Title:' in property:
                PTC_Item_List[2] = property.replace('Issue Title: ', '')

            if 'Customer Issue ID:' in property:
                PTC_Item_List[3] = property.replace('Customer Issue ID: ', '')

        # Add in global item list extracted issues and properties
        if PTC_Item_List not in item_list:
            item_list.append(PTC_Item_List)

    # For debug purpose: MODIFY A STATE OF ITEM OR DELETE ITEM
    # print(item_list)
    # item_list[-1][1] = 'Another State'
    # del item_list[-1]
    # print(item_list)

    # Open csv and extract it's contens into a list
    with open(Path_to_csv, 'r') as f:
        csv_file_lines = f.readlines()
    f.close()

    # Extract header row
    header_row = csv_file_lines[0].split(',')
    header_row = [header_title.replace('\n', '') for header_title in header_row]

    # Define a list to modify in csv
    new_csv_data_list = []

    # Add existing lines in new data list
    for line in csv_file_lines:
        list_from_line = line.split(",")
        list_from_line = [word.replace('\n', '') for word in list_from_line]
        new_csv_data_list.append(list_from_line)

    # Iterate in items
    for item in item_list:

        # Iterate in lines of csv file
        for line, line_index in zip(new_csv_data_list, range(0, len(new_csv_data_list))):

            # If Item is found in list from csv file
            if str(item[0]) in line[1]:

                # Check if state of PTC item has been changed
                if item[1] != line[5]:

                    # Move state to last state
                    new_csv_data_list[line_index] = [line[0], line[1], line[2], line[5], line[4], item[1], line[6], line[7],line[8] ]

        # If Item has not been found in all csv list of items
        if not any(item[0] in csv_line[1] for csv_line in new_csv_data_list):

            # Define a variable to check if issue has been updated
            updated_already = False

            # Iterate in all csv lines
            for line, line_index in zip(new_csv_data_list, range(0, len(new_csv_data_list))):

                # If a new PTC issue has previously created by one of STARC issues
                if line[0] in item[3] and string_in_title in item[2]:

                    # Then update in csv in STARC item
                    new_csv_data_list[line_index][1] = item[0]
                    new_csv_data_list[line_index][8] = item[2]

                    # And update variable
                    updated_already = True

            # If arrived issue has not created by one of our PTC issues
            if updated_already == False:

                # append this new issue in csv as a new issue

                # Construct a field to append
                field_to_append = ['', item[0], '', '', '', item[1], 'False', '', item[2]]

                # Add field in data list
                new_csv_data_list.append(field_to_append)


    with open(Path_to_csv, 'w', newline='') as f:

        # Init object
        writer = csv.writer(f)

        # write the data
        writer.writerows(new_csv_data_list)

    # close the file
    f.close()

def Create_PTC_Issue(path_to_IM, list_of_issue_properties, PTC_Project_Name):

    # Init var issue number
    issue_number = 'NO ISSUE CREATED'

    # Init variable starc item
    STARC_Item = ''

    # If list has properties
    if len(list_of_issue_properties) != 0:

        # Construct command
        batcmd = path_to_IM + 'createissue --type="ALE Issue Report  v1.1" --field="Issue Type=Working Issue" --field="Project=' + PTC_Project_Name + '" '

        for property in list_of_issue_properties:
            batcmd += '--field="' + property + '" '

            # Extract STARC Issue ID
            if 'Customer Issue ID=' in property:
                STARC_Item = property[property.find('Customer Issue ID=') + len('Customer Issue ID=') : ]

        # run constructed command
        subprocess_output = subprocess.getoutput(batcmd)

        if '*** Could not save item:' in subprocess_output or 'You may not supply operands (a selection) to' in subprocess_output:
            print('ERROR IN CREATING ISSUE:', list_of_issue_properties)
            print(subprocess_output)

        # split all properties from one string into a list
        created_issue = subprocess_output.splitlines()

        # Extract issue number
        for line in created_issue:
            if 'Created ALE Issue Report  v1.1' in line:
                issue_number = line[line.find('Created ALE Issue Report  v1.1 ') + len('Created ALE Issue Report  v1.1 '): ]
                print('PTC Issue created with number:', issue_number, 'from STARC item:', STARC_Item)

    # Return issue number
    return issue_number

def remove_text_inside_brackets(text, brackets="()[]"):
    count = [0] * (len(brackets) // 2) # count open/close brackets
    saved_chars = []
    for character in text:
        for i, b in enumerate(brackets):
            if character == b: # found bracket
                kind, is_close = divmod(i, 2)
                count[kind] += (-1)**is_close # `+1`: open, `-1`: close
                if count[kind] < 0: # unbalanced bracket
                    count[kind] = 0  # keep it
                else:  # found bracket to remove
                    break
        else: # character is not a [balanced] bracket
            if not any(count): # outside brackets
                saved_chars.append(character)
    return ''.join(saved_chars)

def convert_list_to_dict(list):

    # Define output dictionary
    output_dict  = {}

    for elem in list:

        # Split after only first :
        new_elem = elem.split(':', 1)

        # If list has elements
        if len(new_elem) > 1:
            output_dict[new_elem[0]] = new_elem[1].lstrip()

    return output_dict

def Create_STARC_Issue(tracker_number, session_ID, STARC_Base_URL, PTC_Issue_list):

    # Set URL Request
    create_item_url = STARC_Base_URL + "/starc/v3/trackers/" + str(tracker_number) + "/items"

    # Set Header requests
    create_item_request_header = {
        'Content-Type': 'application/json'
    }

    # Set session ID Key
    create_item_request_header['STARC_SESSION'] = session_ID

    # Define issue properties dictionary
    issue_properties_dict = {}

    # Convert arrived list to a dictionary
    dictionary_with_properties_of_PTC_issue = convert_list_to_dict(PTC_Issue_list)

    # Init a Stac item title variable
    STARC_Item_title = ''

    if 'Issue Title' in dictionary_with_properties_of_PTC_issue:
        issue_properties_dict['name'] = '[AUTOLIV][' +  str(dictionary_with_properties_of_PTC_issue['ID']) + '] ' + remove_text_inside_brackets(text=dictionary_with_properties_of_PTC_issue['Issue Title']).lstrip()
        STARC_Item_title = '[AUTOLIV][' +  str(dictionary_with_properties_of_PTC_issue['ID']) + '] ' + remove_text_inside_brackets(text=dictionary_with_properties_of_PTC_issue['Issue Title']).lstrip()

    if 'Restraints_Description' in dictionary_with_properties_of_PTC_issue:
        issue_properties_dict['description'] = dictionary_with_properties_of_PTC_issue['Restraints_Description']

    # Create a severity dictionary
    severity_dictionary = {}

    if 'Restraints_Severity' in dictionary_with_properties_of_PTC_issue:
        # If severity has been found in PTC:
        if dictionary_with_properties_of_PTC_issue['Restraints_Severity'] == 'Major':
            severity_dictionary['id'] = 2
            severity_dictionary['name'] = 'VoCA 2 / IBN High'
            severity_dictionary['type'] = 'ChoiceOptionReference'

        if dictionary_with_properties_of_PTC_issue['Restraints_Severity'] == 'Minor':
            severity_dictionary['id'] = 4
            severity_dictionary['name'] = 'VoCA 4 / IBN Low'
            severity_dictionary['type'] = 'ChoiceOptionReference'

        if dictionary_with_properties_of_PTC_issue['Restraints_Severity'] == 'Change':
            severity_dictionary['id'] = 7
            severity_dictionary['name'] = 'Not Applicable'
            severity_dictionary['type'] = 'ChoiceOptionReference'
    else:
        severity_dictionary['id'] = 7
        severity_dictionary['name'] = 'Not Applicable'
        severity_dictionary['type'] = 'ChoiceOptionReference'

    # Add severities
    issue_properties_dict['severities'] = [severity_dictionary]

    # =============== ADD HERE CUSTOM FIELDS ====================

    # ----------- Create Assigned_To -----------
    Assigned_To_dict_values = {}
    Assigned_To_dict_values['id'] = 235
    Assigned_To_dict_values['name'] = 'ROKRULL'
    Assigned_To_dict_values['type'] = 'UserReference'

    Assigned_To_dict = {}
    Assigned_To_dict['fieldId'] = 5
    Assigned_To_dict['name'] = 'Assigned To'
    Assigned_To_dict['type'] = 'ChoiceFieldValue'
    Assigned_To_dict['values'] = [Assigned_To_dict_values]

    # ----------- Create Occurence -----------
    occurence_dict_values = {}
    occurence_dict_values['id'] = 3
    occurence_dict_values['name'] = 'Sometimes'
    occurence_dict_values['type'] = 'ChoiceOptionReference'

    occurence_dict = {}
    occurence_dict['fieldId'] = 1007
    occurence_dict['name'] = 'Occurrence'
    occurence_dict['type'] = 'ChoiceFieldValue'
    occurence_dict['values'] = [occurence_dict_values]

    # ----------- Create Verification By Test Group -----------
    verif_by_tst_group_values = {}
    verif_by_tst_group_values['id'] = 2
    verif_by_tst_group_values['name'] = 'No'
    verif_by_tst_group_values['type'] = 'ChoiceOptionReference'

    verif_by_tst_group = {}
    verif_by_tst_group['fieldId'] = 1005
    verif_by_tst_group['name'] = 'Verification By Test Group'
    verif_by_tst_group['type'] = 'ChoiceFieldValue'
    verif_by_tst_group['values'] = [verif_by_tst_group_values]

    #  ----------- Create Priority -----------
    priority_values = {}
    if 'Priority' in dictionary_with_properties_of_PTC_issue:
        if dictionary_with_properties_of_PTC_issue['Priority'] == '1' :
            priority_values['id'] = 4
            priority_values['name'] = 'Low'
            priority_values['type'] = 'ChoiceOptionReference'

        elif dictionary_with_properties_of_PTC_issue['Priority'] == '2' :
            priority_values['id'] = 3
            priority_values['name'] = 'Mid'
            priority_values['type'] = 'ChoiceOptionReference'

        elif dictionary_with_properties_of_PTC_issue['Priority'] == '3' :
            priority_values['id'] = 2
            priority_values['name'] = 'High'
            priority_values['type'] = 'ChoiceOptionReference'

        else:
            priority_values['id'] = 0
            priority_values['name'] = 'Unset'
            priority_values['type'] = 'ChoiceOptionReference'

    priority = {}
    priority['fieldId'] = 2
    priority['name'] = 'Priority'
    priority['type'] = 'ChoiceFieldValue'
    priority['values'] = [priority_values]

    # ----------- Create Test Envoirment Field -----------
    test_env = {}
    test_env['fieldId'] = 10025
    test_env['name'] = 'Test Environment'
    test_env['type'] = 'TextFieldValue'
    test_env['value'] = 'Supplier Environment'
    # =============================================================

    # Add Custom Fields
    issue_properties_dict['customFields'] = [occurence_dict, verif_by_tst_group, test_env, priority, Assigned_To_dict]

    # For debug purposes
    # for key, value in issue_properties_dict.items():
    #     print(key, ':', value)
    #     if key == 'customFields':
    #         for elem in value:
    #             print('---------------------------')
    #             for k, v in elem.items():
    #                 print('   ', k, ':', v)

    # Set Payload to be sent to STARC server
    payload = json.dumps(issue_properties_dict)

    # Request from starc to create upper defined item
    response_from_request = requests.request("POST", create_item_url, headers=create_item_request_header, data=payload, verify=False).json()
    print(response_from_request)

    # print(response_from_request)

    if 'message' in response_from_request:
        print('ERROR IN CREATING STARC ISSUE: ', response_from_request['message'] )
        return 'ERROR IN CREATING STARC ISSUE','ERROR IN CREATING STARC ISSUE'

    if 'id' in response_from_request:
        print('STARC item created with ID:', str(response_from_request['id']), 'from PTC item:', str(dictionary_with_properties_of_PTC_issue['ID']) )
        return response_from_request['id'], STARC_Item_title

def Edit_STARC_Item_Field(STARC_Base_URL, STARC_Session_ID, Item_ID, Field_Name, Field_Value ):

    # ===================== GET FIELDS OF A TRACKER ITEM =====================
    # Set querry URL
    get_fields_of_a_tracker_item_url  = STARC_Base_URL + "/starc/v3/items/" + str(Item_ID) + "/fields"

    # Initialise header and payload
    get_fields_of_a_tracker_item_payload = {}
    get_fields_of_a_tracker_item_headers = {}

    # Set session ID Key
    get_fields_of_a_tracker_item_headers['STARC_SESSION'] = STARC_Session_ID

    # Send request to STARC
    get_fields_of_a_tracker_item_response = requests.request("GET", get_fields_of_a_tracker_item_url, headers=get_fields_of_a_tracker_item_headers, data=get_fields_of_a_tracker_item_payload, verify=False).json()

    # Initialise a field to modify dictionary
    found_field_to_modify = {}

    # Check if are editable fields in given item
    if 'editableFields' in get_fields_of_a_tracker_item_response:
        for field in get_fields_of_a_tracker_item_response['editableFields']:

            # If given field is found in editable fields
            if field['name'] == Field_Name:
                found_field_to_modify = field

    else:
        print('No editable fields found in item:', str(Item_ID))
        return 'No editable fields found in item'

    if found_field_to_modify == {}:
        print('Given field', Field_Name, 'was not found in editable fields!')
        print('Editable fields for given item', str(Item_ID),'are:')
        for field in get_fields_of_a_tracker_item_response['editableFields']:
            print(field)
        return 'Given field not found!'

    # If field has multiple choice options to choose
    if found_field_to_modify['type'] == 'ChoiceFieldValue':

        # ===================== Get the options of a choice field of tracker =====================
        # Set querry URL
        get_options_of_choice_field_url  = STARC_Base_URL + "/starc/v3/items/" + str(Item_ID) + "/fields/" + str(found_field_to_modify['fieldId']) + "/options?page=1&pageSize=500"

        # Initialise header and payload
        get_options_of_choice_field_payload = {}
        get_options_of_choice_field_headers = {}

        # Set session ID Key
        get_options_of_choice_field_headers['STARC_SESSION'] = STARC_Session_ID

        # Send request to STARC
        get_options_of_choice_field_response = requests.request("GET", get_options_of_choice_field_url, headers=get_options_of_choice_field_headers, data=get_options_of_choice_field_payload, verify=False).json()

        found_referece = False

        # if found value is found in choice options, then update in get_options_of_choice_field_response
        for referece in get_options_of_choice_field_response['references']:
            if referece['name'] == Field_Value:
                if len(found_field_to_modify['values']) != 0:
                    found_field_to_modify['values'][0] = referece
                    found_referece = True
                    break
                else:
                    found_field_to_modify['values'].append(referece)
                    found_referece = True
                    break

        if found_referece == False:
            print('Given field:',Field_Value, 'to be modified in STARC has not been found!')
            print('Available Options:')
            for option in get_options_of_choice_field_response['references']:
                print(option)
            return 'Given field not found'

    # If field is a text-based field
    if found_field_to_modify['type'] == 'TextFieldValue':

        # Then update it's value
        found_field_to_modify['value'] = str(Field_Value)

    # ============== Update fields of a tracker item =====================
    # Set update url
    update_fields_of_a_tracker_item_url = STARC_Base_URL + "/starc/v3/items/" + str(Item_ID) + "/fields?quietMode=false"

    # Initialise header
    update_fields_of_a_tracker_item_headers = {
        'Content-Type': 'application/json'
    }

    # Set session ID Key
    update_fields_of_a_tracker_item_headers['STARC_SESSION'] = STARC_Session_ID

    # Initialise payload dictionary
    payload_dictionary = {}

    # add data in payload dictionary
    payload_dictionary['fieldValues'] = [found_field_to_modify]

    # Set payload for request
    update_fields_of_a_tracker_item_payload = json.dumps(payload_dictionary)

    # print(update_fields_of_a_tracker_item_payload)

    # Send request to STARC
    response_from_edit_request = requests.request("PUT", update_fields_of_a_tracker_item_url, headers=update_fields_of_a_tracker_item_headers, data=update_fields_of_a_tracker_item_payload, verify=False).json()

    if 'id' in response_from_edit_request:
        print('STARC Item:', str(Item_ID), 'has field:',Field_Name, 'updated with value:',Field_Value, 'successfully!'  )
        return 'STARC Item Updated Succesfully'
    else:
        print('STARC Item could not be updated!')
        print(response_from_edit_request)

        # Check if are editable fields in given item
        if 'editableFields' in get_fields_of_a_tracker_item_response:
            print('Maybe you forget to edit some fields. All editable fields found for this item are:')
            for field in get_fields_of_a_tracker_item_response['editableFields']:
                print(field)

        return 'STARC Item could not be updated!'


def Edit_PTC_Issue_Item(PTC_Issue_ID, path_to_IM, Field_Name, Field_Value ):

    # construct batch file command line
    batcmd = path_to_IM + 'editissue --field=' + '"' + Field_Name + '=' + Field_Value + '" ' + PTC_Issue_ID

    # Run command
    subprocess_output = subprocess.run(batcmd, capture_output=True)

    # Check output
    if subprocess_output.returncode == 0:
        print('PTC Item updated successfully!')
    else:
        print('PTC Item could not been updated! Encounted Error:')
        print('EXIT CODE:', subprocess_output.returncode)
        print('COMMAND OUTPUT:', subprocess_output.stdout.decode())
        print('COMMAND ERROR:', subprocess_output.stderr.decode())

def Add_PTC_Attachement(PTC_Issue_ID, path_to_IM, attachement_path):

    # construct batch file command line
    batcmd = path_to_IM + 'editissue --addAttachment=' + str(attachement_path) + ' ' + str(PTC_Issue_ID)

    # Run command
    subprocess_output = subprocess.run(batcmd, capture_output=True)

    # Check output
    if subprocess_output.returncode == 0:
        print('PTC Item',str(PTC_Issue_ID), 'has now attachements!' )
    else:
        print('PTC Item', str(PTC_Issue_ID),'have not added attachements!')
        print('EXIT CODE:', subprocess_output.returncode)
        print('COMMAND OUTPUT:', subprocess_output.stdout.decode())
        print('COMMAND ERROR:', subprocess_output.stderr.decode())


def Get_field_from_PTC_item(PTC_Database, field_name, item_ID):

    # Init a new variable
    found_PTC_issue = []

    # If issue found in database is current issue from csv
    for PTC_Issue in PTC_Database:
        for issue_property in PTC_Issue:
            if 'ID:' in issue_property[0:5] and str(item_ID) in issue_property:
                found_PTC_issue = PTC_Issue

    # init variable to avoid exception
    found_field = 'Field Not Found!'


    for field in found_PTC_issue:
        if field_name in field[0:len(field_name) + 2]:

            # Extract only field value without field name
            found_field = field[field.find(field_name)+len(field_name)+2 : ]

    return found_field

def Get_comments_of_STARC_item(STARC_Base_URL, STARC_Session_ID, Item_ID ):

    # Construct URL request
    url = STARC_Base_URL + "/starc/v3/items/" + str(Item_ID) +"/comments"

    # Construct headers and payload
    payload = {}
    headers = {
        'STARC_SESSION': STARC_Session_ID,
    }

    # Send request
    response = requests.request("GET", url, headers=headers, data=payload, verify=False).json()

    # Init a var with comments
    comment_string = ''

    # If there are comments
    if len(response) != 0:

        # For every comment added
        for comment in response:
            comment_string += 'User: ' + comment['createdBy']['email'] + ' on date: ' + comment['createdAt'] + ' wrote: ' + comment['comment'] + ' '

        # Return comment
        return comment_string

    else:
        # Do not return comment
        return 'No comments retrived from STARC Database!'


def Get_attachements_of_STARC_item(STARC_Base_URL, STARC_Session_ID, Item_ID, Path_to_attachements ):

    # Construct URL request
    url = STARC_Base_URL + "/starc/v3/items/" + str(Item_ID) +"/attachments/content"

    # Construct headers and payload
    payload = {}
    headers = {
        'STARC_SESSION': STARC_Session_ID,
    }

    # Send request
    response = requests.request("GET", url, headers=headers, data=payload, verify=False)

    # Define file name
    file_name = 'attachements_from_item_' + str(Item_ID) + '.zip'

    # Construct path to file
    path_to_output_file = os.path.join(Path_to_attachements, file_name)

    # Save attachement from STARC Item
    with open(path_to_output_file, 'wb') as fd:
        for chunk in response.iter_content(chunk_size=128):
            fd.write(chunk)

    # If file exists, return it's path
    if os.path.exists(path_to_output_file):

        # Return attachement path
        return path_to_output_file

    else:
        return ''


def Update_PTC_Issue_Avability(path_to_csv, path_to_IM ):

    # --------------- READ CSV FILE LIST ----------------------
    # Define an empty list
    csv_list_of_data = []

    # Open csv and extract it's contens into a list
    with open(path_to_csv, 'r') as f:
        csv_file_lines = f.readlines()
    f.close()

    # Add existing lines in new data list
    for line in csv_file_lines:
        list_from_line = line.split(",")
        list_from_line = [word.replace('\n', '') for word in list_from_line]
        csv_list_of_data.append(list_from_line)

    # Extract Header Row
    header_row = csv_list_of_data[0]

    # Delete header row from list
    del csv_list_of_data[0]

    for issue, issue_index in zip(csv_list_of_data, range(0, len(csv_list_of_data))):

        # If there is a issue
        if len(issue[1]) > 0:

            # ----------------------------- GET PTC ISSUE PROPERTIES ---------------------------------------------
            # call function PTC to get member information
            batcmd = path_to_IM + " viewissue --showTimeEntries --showAnnotations  " + issue[1]

            # store in result output from cmd command executed
            subprocess_output = subprocess.check_output(batcmd)

            subprocess_output = subprocess_output.decode("utf-8", errors='ignore')

            # split all properties from one string into a list
            list_of_all_properties_per_issue = subprocess_output.splitlines()

            # Check if customer visible is set to Yes or No.
            if any("Customer visible: Yes" in property for property in list_of_all_properties_per_issue):
                csv_list_of_data[issue_index][6] = 'False'

            if any("Customer visible: No" in property for property in list_of_all_properties_per_issue):
                csv_list_of_data[issue_index][6] = 'True'

    with open(path_to_csv, 'w', newline='') as f:

        # Init object
        writer = csv.writer(f)

        # write the header
        writer.writerow(header_row)

        # write the data
        writer.writerows(csv_list_of_data)

        # close the file
        f.close()

def Sync_PTC_issue_with_STARC_issue(path_to_csv, STARC_Database, PTC_Database, path_to_IM, STARC_Session_ID, STARC_Base_URL, PTC_Project_Name, STARC_tracker_number, Path_to_attachements, path_to_txt_file, list_of_people ):

    # --------------- READ CSV FILE LIST ----------------------
    # Define an empty list
    csv_list_of_data = []

    # Open csv and extract it's contens into a list
    with open(path_to_csv, 'r') as f:
        csv_file_lines = f.readlines()
    f.close()

    # Add existing lines in new data list
    for line in csv_file_lines:
        list_from_line = line.split(",")
        list_from_line = [word.replace('\n', '') for word in list_from_line]
        csv_list_of_data.append(list_from_line)

    # Extract Header Row
    header_row = csv_list_of_data[0]

    # Delete header row from list
    del csv_list_of_data[0]

    # Define a string to send in email if encounter a state that could not be handled
    string_to_send_in_email = ''

    # --------------- PROCESS FILES ----------------------
    # List goes from 1 because we don't need to process header
    for issue, issue_index in zip( csv_list_of_data, range(0, len(csv_list_of_data))):

        # FIRST CASE: NEW ISSUE ARRIVED FROM STARC AND HAS NOT A PTC ISSUE ASSIGNED
        if issue[0] != '' and issue[1] == '':

            # Define an emtpy list of properties per isssue
            PTC_issue_properties_list = []
            issue_title = ''
            string_with_PTC_property_description = ''

            # extract all id trackers from STARC Database
            for key, value in STARC_Database.items():

                if key == 'items':

                    # every item in value is a dictionary and value is a big list
                    for item in value:

                        # If issue from csv is current issue from database
                        if issue[0] in str(item['id']):

                            # For every propery of an item
                            # for item_key, item_value in item.items():

                                # print(item_key, ':', item_value)

                            # ================== ISSUE TITLE ======================
                            # If name was found
                            if 'name' in item:

                                # Construct PTC issue property string
                                if len(item['name']) > 80:
                                    string_with_PTC_property = 'Issue Title=[CST][DAI_MMA] ' + item['name'][0:80].replace(',',';')
                                    string_with_PTC_property = string_with_PTC_property.replace('"', '')
                                else:
                                    string_with_PTC_property = 'Issue Title=[CST][DAI_MMA] ' + item['name'].replace(',',';')
                                    string_with_PTC_property = string_with_PTC_property.replace('"', '')

                                # Retain title
                                issue_title = '[CST][DAI_MMA] ' +  item['name'].replace(',',';')
                                issue_title = issue_title.replace('"', '')

                                # Append property in list
                                if string_with_PTC_property not in PTC_issue_properties_list:
                                    PTC_issue_properties_list.append(string_with_PTC_property)

                            # ================== ISSUE DESCRIPTION ======================

                            # If description was found
                            if 'description' in item and len(item['description']) != 0:

                                # Construct PTC issue property string
                                string_with_PTC_property_description = 'Restraints_Description=' + item['description'].replace("\r\n", "  ")
                                string_with_PTC_property_description = string_with_PTC_property_description.replace('“', '')
                                string_with_PTC_property_description = string_with_PTC_property_description.replace('”','')
                                string_with_PTC_property_description = string_with_PTC_property_description.strip()
                                string_with_PTC_property_description = string_with_PTC_property_description.replace('"', '')

                                # Append property in list
                                if string_with_PTC_property_description not in PTC_issue_properties_list:
                                    PTC_issue_properties_list.append(string_with_PTC_property_description)
                            else:

                                # Construct PTC issue property string
                                string_with_PTC_property_description = 'Restraints_Description=No Description Found in STARC Issue!'

                                # Append property in list
                                if string_with_PTC_property_description not in PTC_issue_properties_list:
                                    PTC_issue_properties_list.append(string_with_PTC_property_description)

                            # ================== ISSUE ID ======================
                            # If description was found
                            if 'id' in item:

                                # Construct PTC issue property string
                                string_with_PTC_property = 'Customer Issue ID=' + str(item['id'])

                                # Append property in list
                                if string_with_PTC_property not in PTC_issue_properties_list:
                                    PTC_issue_properties_list.append(string_with_PTC_property)

                            # ================== ISSUE Priority ======================
                            # If description was found
                            if 'priority' in item:

                                # Construct PTC issue property string
                                if item['priority']['id'] == 0:
                                    string_with_PTC_property = 'Restraints_Workload_Priority=' + str(1)
                                else:
                                    string_with_PTC_property = 'Restraints_Workload_Priority=' + str(item['priority']['id'])

                                # Append property in list
                                if string_with_PTC_property not in PTC_issue_properties_list:
                                    PTC_issue_properties_list.append(string_with_PTC_property)

                            # ================== ISSUE Severity ======================
                            # If description was found
                            if 'severities' in item:

                                # Init variable with severity
                                string_with_PTC_property = ''

                                # If there is severity
                                if len(item['severities']) > 0:

                                    if item['severities'][0]['name'] == 'VoCA 1 / IBN Ultra High' or item['severities'][0]['name'] == 'VoCA 2 / IBN High':
                                        string_with_PTC_property = 'Restraints_Severity=Major'

                                    if item['severities'][0]['name'] == 'VoCA 3 / IBN Medium' or item['severities'][0]['name'] == 'VoCA 4 / IBN Low':
                                        string_with_PTC_property = 'Restraints_Severity=Minor'

                                    if item['severities'][0]['name'] == 'Not Applicable' or item['severities'][0]['name'] == 'Unset':
                                        string_with_PTC_property = 'Restraints_Severity=Change'
                                else:
                                    string_with_PTC_property = 'Restraints_Severity=Change'

                                if string_with_PTC_property != '' and string_with_PTC_property not in PTC_issue_properties_list:
                                    PTC_issue_properties_list.append(string_with_PTC_property)

                            # ================== ISSUE OBSERVED DURING ======================
                            # If description was found
                            if 'customFields' in item:

                                # Search in witch release issue has been detected
                                for field in item['customFields']:
                                    if 'name' in field and field['name'] == 'Detected In EE Release':

                                        # Construct PTC issue property string
                                        string_with_PTC_property = 'Keywords=' + field['name'] + ':' + field['values'][0]['name']

                                        # Append property in list
                                        if string_with_PTC_property not in PTC_issue_properties_list:
                                            PTC_issue_properties_list.append(string_with_PTC_property)

                            # ================== ISSUE CUSTOMER VISIBLE ======================
                            # Construct PTC issue property string
                            string_with_PTC_property = 'Customer visible=Yes'

                            # Append property in list
                            if string_with_PTC_property not in PTC_issue_properties_list:
                                PTC_issue_properties_list.append(string_with_PTC_property)

            # Create PTC Issue
            created_issue_number = Create_PTC_Issue(path_to_IM=path_to_IM, list_of_issue_properties=PTC_issue_properties_list, PTC_Project_Name=PTC_Project_Name)

            # ================== ISSUE COMMENTS ======================
            # Retrive comments from STARC Item
            issue_comments = Get_comments_of_STARC_item(STARC_Base_URL=STARC_Base_URL,STARC_Session_ID=STARC_Session_ID, Item_ID=issue[0])

            # Construct PTC issue property string
            string_with_PTC_property = issue_comments.replace("\r\n", "").strip().replace('"', '')
            string_with_PTC_property = string_with_PTC_property.replace('“', '')
            string_with_PTC_property = string_with_PTC_property.replace('”', '')
            string_with_PTC_property = string_with_PTC_property.strip()
            string_with_PTC_property = string_with_PTC_property.replace('"', '')

            # Get actual description of item from PTC
            found_description = string_with_PTC_property_description.replace('Restraints_Description=', '')

            # Add comments
            found_description += "STARC Comments:"
            found_description += string_with_PTC_property

            # Add description back
            Edit_PTC_Issue_Item(PTC_Issue_ID=created_issue_number, path_to_IM=path_to_IM, Field_Name='Restraints_Description',Field_Value=found_description)

            # ================== ISSUE ATTACHEMENTS ======================
            # Retrive file from STARC Item
            retrived_file_path = Get_attachements_of_STARC_item(STARC_Base_URL=STARC_Base_URL,STARC_Session_ID=STARC_Session_ID, Item_ID=issue[0],Path_to_attachements=Path_to_attachements)

            # Add file in PTC
            Add_PTC_Attachement(PTC_Issue_ID=str(created_issue_number), path_to_IM=path_to_IM, attachement_path=retrived_file_path)
            # ==============================================================

            # Add created PTC issue number in csv
            csv_list_of_data[issue_index][1] = str(created_issue_number)

            # add created PTC issue title in csv
            csv_list_of_data[issue_index][8] = issue_title

        # SECOND CASE: NEW ISSUE ARRIVED FROM PTC AND HAS NOT A STARC ISSUE ASSIGNED, THEN CREATE A STARC ITEM
        if issue[0] == '' and issue[1] != '':

            # If issue found in database is current issue from csv
            for PTC_Issue in PTC_Database:
                for issue_property in PTC_Issue:

                    if 'ID:' in issue_property[0:5] and issue[1] in issue_property:

                        # Call api to create starc item
                        Starc_Item_ID, STARC_Item_title = Create_STARC_Issue(session_ID=STARC_Session_ID, STARC_Base_URL=STARC_Base_URL, PTC_Issue_list=PTC_Issue, tracker_number=STARC_tracker_number)

                        # Update csv with STARC number
                        csv_list_of_data[issue_index][0] = str(Starc_Item_ID)
                        csv_list_of_data[issue_index][7] = STARC_Item_title

                        # Add in PTC also Customer issue ID
                        Edit_PTC_Issue_Item(PTC_Issue_ID=issue[1], path_to_IM=path_to_IM, Field_Name='Customer Issue ID',Field_Value=str(Starc_Item_ID))

        # THIRD CASE: UPDATE ISSUE STATES IF THERE ARE CHANGES IN STATES
        if issue[0] != '' and issue[1] != '':

            # Check if issues are in sync mode
            if issue[6] == 'False':

                # ISSUE FIELDS FROM CSV ARE:
                # issue[0] -> STARC Issue Number,
                # issue[1] -> PTC Issue Number,
                # issue[2] -> Last STARC Issue State,
                # issue[3] -> Last PTC Issue State,
                # issue[4] -> Current STARC Issue State,
                # issue[5] -> Current PTC Issue State,
                # issue[6] -> STARC New Issue number assigned to PTC issue,
                # issue[7] -> STARC_Issue_Title,
                # issue[8] -> PTC_Issue_Title

                # if STARC CURRENT STATE IS IN PROGRESS, LAST STARC STATE IS NOT FIXED AND CURRENT PTC STATE IS CLOSED:
                if issue[4] == 'In Progress' and issue[2] != 'Fixed' and issue[5] == '(Closed)':

                    print('SETTING STARC ITEM',issue[0],'TO FIXED STATUS!' )
                    # Get properties from PTC
                    release_issue_found = Get_field_from_PTC_item(PTC_Database = PTC_Database, field_name = 'Target Release Container', item_ID=issue[1])
                    release_issue_found = release_issue_found.replace('DAIMLER_MMA_', '')
                    release_issue_found = release_issue_found.replace('.0', '')

                    Edit_STARC_Item_Field(STARC_Base_URL=STARC_Base_URL, STARC_Session_ID=STARC_Session_ID,Item_ID=issue[0], Field_Name='Supplier Status', Field_Value='Supplier Fixed')
                    Edit_STARC_Item_Field(STARC_Base_URL=STARC_Base_URL, STARC_Session_ID=STARC_Session_ID,Item_ID=issue[0], Field_Name='Fixed In E-Stand', Field_Value='Supplier Setup')
                    Edit_STARC_Item_Field(STARC_Base_URL=STARC_Base_URL, STARC_Session_ID=STARC_Session_ID,Item_ID=issue[0], Field_Name='Fixed In EE Release', Field_Value=release_issue_found)
                    Edit_STARC_Item_Field(STARC_Base_URL=STARC_Base_URL, STARC_Session_ID=STARC_Session_ID,Item_ID=issue[0], Field_Name='Fixed In Release', Field_Value=release_issue_found)
                    Edit_STARC_Item_Field(STARC_Base_URL=STARC_Base_URL, STARC_Session_ID=STARC_Session_ID, Item_ID=issue[0], Field_Name='Status', Field_Value='Fixed')
                    print('STARC Item:', str(issue[0]),'has now Status set to Fixed!')

                # if STARC CURRENT STATE IS IN PROGRESS AND PTC CURRENT STATE IS REJECTED:
                elif issue[4] == 'In Progress' and issue[5] == '(Rejected)':

                    print('SETTING STARC ITEM', issue[0], 'TO OPEN STATUS!')
                    Edit_STARC_Item_Field(STARC_Base_URL=STARC_Base_URL, STARC_Session_ID=STARC_Session_ID, Item_ID=issue[0], Field_Name='Reject Reason', Field_Value='Configuration Error')
                    Edit_STARC_Item_Field(STARC_Base_URL=STARC_Base_URL, STARC_Session_ID=STARC_Session_ID, Item_ID=issue[0], Field_Name='Reject Argument', Field_Value='Configuration Error')
                    Edit_STARC_Item_Field(STARC_Base_URL=STARC_Base_URL, STARC_Session_ID=STARC_Session_ID, Item_ID=issue[0], Field_Name='Supplier Status', Field_Value='Supplier Rejected')
                    Edit_STARC_Item_Field(STARC_Base_URL=STARC_Base_URL, STARC_Session_ID=STARC_Session_ID, Item_ID=issue[0], Field_Name='Status', Field_Value='Open')
                    print('STARC Item:', str(issue[0]),'has now Status set to Open!')

                # if STARC CURRENT STATE IS IN PROGRESS AND STARC LAST STATE IS FIXED, THEN SEND EMAIL:
                elif (issue[4] == 'In Progress' and issue[2] == 'Fixed'):

                    # Edit_PTC_Issue_Item(PTC_Issue_ID=issue[1], path_to_IM=path_to_IM, Field_Name='State',Field_Value='(To Be Analyzed)')
                    # print('PTC Item:', str(issue[1]),'has now State set to (To Be Analyzed)!')
                    # Construct a string to be writed in email

                    # Send email with founded sittuation
                    string_to_send_in_email += "<p>" + "Item from PTC with ID: " + str(issue[1]) + " linked on STARC Item with ID: " + str(issue[0]) + " has the following states: " +  "<br>" +  \
                                                "Last PTC State is: " + str(issue[3]) + ", current PTC issue State is: " + str(issue[5]) + ", last STARC item State is: " + str(issue[2]) + " and current STARC state is: " + str(issue[4]) + "</p>"
                else:
                    pass

            else:
                print('PTC item', str(issue[1]), 'will be ignored from syncronization because Customer Visible field is set to No !')

    # If there is sittuations that could not be handled, then send email throu jenkins.
    if len(string_to_send_in_email) > 0:

        # Write that string in email notification file.
        Write_In_Notification_File(path_to_txt_file=path_to_txt_file, list_of_people=list_of_people, email_content=string_to_send_in_email)

    # Update csv file
    with open(path_to_csv, 'w', newline='') as f:

        # Init object
        writer = csv.writer(f)

        # write the header
        writer.writerow(header_row)

        # write the data
        writer.writerows(csv_list_of_data)

        # close the file
        f.close()

def Create_csv_history_file(path_to_file):

    # Define here header row
    header_row = ['STARC Issue Number', 'PTC Issue Number', 'Last STARC Issue State', 'Last PTC Issue State', 'Current STARC Issue State', 'Current PTC Issue State', 'Ignore Issue', 'STARC_Issue_Title', 'PTC_Issue_Title']

    # Check if file exists first
    if not os.path.isfile(path_to_file):

        # open the file in the write mode
        f = open(path_to_file, 'w', newline='')

        # create the csv writer
        writer = csv.writer(f)

        # write a row to the csv file
        writer.writerow(header_row)

        # close the file
        f.close()

    # else:
    #
    #     fields = ['Test', '', 'Test2']
    #
    #     # open the file in the write mode
    #     f = open(path_to_file, 'a', newline='')
    #
    #     # create the csv writer
    #     writer = csv.writer(f)
    #
    #     # write a row to the csv file
    #     writer.writerow(fields)
    #
    #     # close the file
    #     f.close()

def Write_In_Notification_File(path_to_txt_file, list_of_people, email_content ):

    # Define strings of contents
    line_1 = "EMAIL_LIST=" + list_of_people
    line_2 = "EMAIL_CONTENT=" + email_content

    # Write strings in file
    with open(path_to_txt_file, 'w') as out:
        out.write('{}\n{}\n'.format(line_1,line_2))

# ===========================
# MAIN FUNCTION OF SCRIPT
# INPUT ARGUMENT: NONE
# OUTPUT ARGUMENT: NONE
# ===========================
def main():

    print("============================================")
    print("             STARC PTC SYNC API")
    print("Copyright Autoliv, 2022, RBE")
    print("Do not forget to configure .yaml config file")
    print("============================================")

    path_to_YAML_file = 'STARC_PTC_Sync_API_Config.yaml'

    # Read yaml config file
    with open(path_to_YAML_file, 'r') as stream:
        try:
            yaml_config_file = yaml.load(stream, Loader=yaml.FullLoader)
        except Exception as exception:
            print('YAML Config file could not been loaded. Exception Occured:', exception)
            print('This API will exit now!')
            return -1

    # Clear notification file
    Write_In_Notification_File(path_to_txt_file=yaml_config_file['Path to notification file'], list_of_people='', email_content='')

    # Log in PTC Account
    login_in_PTC(path_to_si=yaml_config_file['Path to si.exe'], username=yaml_config_file['PTC Username'], password=yaml_config_file['PTC Password'])

    # Connect to STARC Database
    session_id = Connect_to_STARC_Database(STARC_Base_URL=yaml_config_file['STARC Base URL'], STARC_App_ID=yaml_config_file['STARC Application ID'], STARC_App_Token=yaml_config_file['STARC Application Token'] )

    # Querry STARC Database
    STARC_Database_Query_Dictionary = Query_STARC_Database(session_ID=session_id, STARC_Querry=yaml_config_file['STARC cbQL Querry'], STARC_Base_URL=yaml_config_file['STARC Base URL'])

    # Querry PTC Database
    PTC_Database_Query_List = Query_PTC_Database(query=yaml_config_file['PTC Querry'], path_to_IM=yaml_config_file['Path to im.exe'], string_in_title=yaml_config_file['PTC Issues Title String'])

    # Create file ( if it's not exists already )
    Create_csv_history_file(path_to_file=yaml_config_file['Path to csv history file'])

    # Update CSV File with issues from STARC
    Update_STARC_Issue_List_In_CSV(Path_to_csv= yaml_config_file['Path to csv history file'], STARC_Database_Query_Dictionary = STARC_Database_Query_Dictionary, Allow_only_sync_allowed_items=yaml_config_file['Sync Allowed Status'] )

    # Update CSV File with issues from PTC
    Update_PTC_Issue_List_In_CSV(Path_to_csv=yaml_config_file['Path to csv history file'], PTC_Database_Query_List=PTC_Database_Query_List, string_in_title=yaml_config_file['PTC Issues Title String'] )

    # Check if PTC Issues has still Customer Visible set to Yes or No.
    Update_PTC_Issue_Avability(path_to_csv=yaml_config_file['Path to csv history file'], path_to_IM=yaml_config_file['Path to im.exe'])

    # Sync issues according to csv file
    Sync_PTC_issue_with_STARC_issue(path_to_csv=yaml_config_file['Path to csv history file'],  STARC_Database=STARC_Database_Query_Dictionary, PTC_Database=PTC_Database_Query_List, path_to_IM=yaml_config_file['Path to im.exe'], STARC_Session_ID=session_id, STARC_Base_URL=yaml_config_file['STARC Base URL'], PTC_Project_Name=yaml_config_file['PTC Project Name'], STARC_tracker_number=yaml_config_file['STARC Tracker Number'], Path_to_attachements=yaml_config_file['Path to attachements folder'], path_to_txt_file=yaml_config_file['Path to notification file'], list_of_people=yaml_config_file['List of people'] )

if __name__ == '__main__':
    main()