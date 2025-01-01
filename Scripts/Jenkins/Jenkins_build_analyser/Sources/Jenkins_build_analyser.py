import argparse
import os
import subprocess
import re

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

            # Connect
            output_conected = os.system(path_to_si + "connect --hostname='ALVA-MKS01.alv.autoliv.int' --port='7001' --user=" + username + " --password=" + password)

        # Change flag
        PTCLogIn_flag = 1
        print('Login Succesfully in PTC account!')

def changelog_xml_parser(path_to_changelog_xml):

    # Open file in order to be readed
    with open(path_to_changelog_xml) as file:
        lines = file.readlines()

    list_with_files_path_and_revision_number = []

    # extract from file only needed data
    for index in range(0,len(lines)):

        # Define a temp list
        temp_list_with_path_and_revision = ['','']

        # If path to file has been found
        if '<context>' in lines[index] and '</context>' in lines[index]:

            # Filter founded path
            path_to_file = lines[index]
            path_to_file = path_to_file.replace('<context>', '')
            path_to_file = path_to_file.replace('</context>', '')
            path_to_file = path_to_file.lstrip()
            path_to_file = path_to_file.strip()

            # Filter file name
            file_name = lines[index-2]
            file_name = file_name.replace('<file>', '')
            file_name = file_name.replace('</file>', '')
            file_name = file_name.lstrip()
            file_name = file_name.strip()

            # Filter file revision number
            file_revision_number = lines[index-1]
            file_revision_number = file_revision_number.replace('<msg>', '')
            file_revision_number = file_revision_number.replace('</msg>', '')
            file_revision_number = file_revision_number.lstrip()
            file_revision_number = file_revision_number.strip()
            file_revision_number = file_revision_number.replace('checked out revision ', '')

            # Replace project.pj with file name
            path_to_file = path_to_file.replace('project.pj', file_name)

            # First position: file path, second position: revision
            temp_list_with_path_and_revision[0] = path_to_file
            temp_list_with_path_and_revision[1] = file_revision_number

            # Add created list in global used list
            if temp_list_with_path_and_revision not in list_with_files_path_and_revision_number:
                list_with_files_path_and_revision_number.append(temp_list_with_path_and_revision)

    return list_with_files_path_and_revision_number

def get_list_of_emails_from_PTC(path_to_si, list_of_files_changed, path_to_local_project):

    # Define a list of people's mails
    list_of_people_mails = []

    for file in list_of_files_changed:

        # Get file path into a variable
        file_path = file[0]

        # Get file revision number from Jenkins in a variable
        file_revision_number = file[1]

        # Extract only server path from entire string ( Only to Phase_01 folder )
        server_file_path = file_path[0: file_path.find('View_') + len('View_') ]

        # Extract View_ type folder from string
        string_to_check = ''
        path_to_be_replaced = ''
        for letter in file_path:

            # Append every iteration a letter to string
            string_to_check += letter

            # if we had path until to Phase_01 folder and a View_ string with / as last character
            if server_file_path in string_to_check and string_to_check[-1] == '/':

                # Then we found entire View_ type folder
                path_to_be_replaced = string_to_check
                break

        # Replace in file path local path
        file_path ='"' +  os.path.join(path_to_local_project, file_path.replace(path_to_be_replaced, '')).replace("'",'') + '"'

        # call function PTC to get member information
        batcmd = path_to_si + "memberinfo  " + file_path

        # store in result output from cmd command executed
        result = subprocess.getoutput(batcmd)
        output_from_ptc_in_lines = result.splitlines()

        # Get member last revision number
        member_revision_number = result[ result.find('Member Revision: '): result.find('    ')].rstrip()

        # Check if member last revision number from PTC is identical to Changes in Jenkins
        # if file_revision_number in member_revision_number:

        # for every line in output from ptc
        for line in output_from_ptc_in_lines:

            # If Created By in line, then let's extract username
            if 'Created By:' in line:

                # apply a regex search to extract everything between ( )
                regex_result = re.search("[(](.*)[)]", line)

                # If found a user name, then extract it
                if regex_result != None:
                    user_name = regex_result.group(1)
                    user_mail = user_name + "@autoliv.com"

                    # if user mail not already in list of all people's mails, then append it
                    if user_mail not in list_of_people_mails and user_mail != 'Jenkins01@autoliv.com':
                        list_of_people_mails.append(user_mail)
        # else:
            # print('File', os.path.basename(file_path).replace('"',''), 'has other revision in PTC than revision found in Jenkins!')

    # Return list of people mails
    return list_of_people_mails


def main():

    # Add argparse arguments
    parser = argparse.ArgumentParser()
    parser.add_argument('-i', '--input-path-builds', help="Path to builds folder from Jenkins. Ex: ART-OF-WD3173\jenkins\Jenkins\jobs\Build_Manager\jobs\AUDI_TR6_Release\builds", required=True)
    parser.add_argument('-u', '--input-username', help="Username for PTC Account", required=True)
    parser.add_argument('-p', '--input-password', help="Passowrd for PTC Account", required=True)
    parser.add_argument('-l', '--input-local-project-path', help="Path to local project path. NOT S: DRIVE PATH! C: or D: drive path! Ex: C:\Projects\AUDI_TR6\Phase_1\View_Development", required=True)
    parser.add_argument('-o', '--output-path', help="Path to output generated txt with people's email list who make changes", required=True)
    args = parser.parse_args()

    print('---------------------------------------')
    print('    Jenkins changelog analysis tool')
    print('     Copyright Autoliv RBE, 2021')
    print('---------------------------------------')

    # Define global path to si file
    path_to_si = '"C:/Program Files (x86)/Integrity/ILMClient11/bin/si.exe" '

    # Delete txt file if exists
    if os.path.exists(args.output_path):
        os.remove(args.output_path)

    # Get input dir into a variable
    input_directory = args.input_path_builds

    # Extract a list of directories in that file
    dir_list = [int(d) for d in os.listdir(input_directory) if os.path.isdir(os.path.join(input_directory, d))]

    # Sort list to get last build folder
    sorted_dir_list = sorted(dir_list, reverse=True)

    # Check if changelog file is in last build
    for folder in sorted_dir_list:
        path_to_be_checked = os.path.join( *[input_directory, str(folder), 'changelog.xml'] )

        if os.path.exists(path_to_be_checked):
            changelog_file_path = path_to_be_checked
            print('Found changelog.xml file in build:', str(folder))
            break
        else:
            print('changelog.xml file has not been found in build:', str(folder),'- No email list will be created!' )
            return 0

    # Call function to parse xml file
    list_of_files_changed = changelog_xml_parser(path_to_changelog_xml=changelog_file_path)

    # Call function to login in ptc
    login_in_PTC(path_to_si=path_to_si, password=args.input_password, username=args.input_username)

    # Call function to get list of emails
    list_of_people_mail = get_list_of_emails_from_PTC(path_to_si=path_to_si, list_of_files_changed=list_of_files_changed, path_to_local_project=args.input_local_project_path)

    # Construct string to be writed in txt file
    string_to_be_writed_in_txt_file = 'EMAILS='
    for mail in list_of_people_mail:
        string_to_be_writed_in_txt_file += mail  + ' '

    # Write in txt file
    f = open(args.output_path, "w")
    f.write(string_to_be_writed_in_txt_file)
    f.close()

    if os.path.exists(args.output_path):
        print('TXT File has been generated succesfully!')


if __name__ == '__main__':
    main()