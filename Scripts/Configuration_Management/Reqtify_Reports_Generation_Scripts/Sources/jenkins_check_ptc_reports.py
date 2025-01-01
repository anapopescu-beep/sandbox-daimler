

# ================= IMPORTS =========================
import argparse
import os
import subprocess
from datetime import datetime
import sys

# call today date
today = datetime.now()

# Global path to si.exe ( if is not exist in bench )
path_to_si = '"C:/Program Files (x86)/Integrity/ILMClient11/bin/si.exe" '

def parse_path(string):
    count = 24
    while True:
        count += 1
        new_string = string.split(string[:count], 1)
        if os.path.exists(new_string[1]):
            return new_string
            break

def get_member_revision_number(path):
    # call function PTC to get member information
    batcmd = path_to_si + "memberinfo " + path

    # store in result output from cmd command executed
    result = subprocess.getoutput(batcmd)

    # search for member revision substring in all string
    substring = result.find('Member Revision:')

    # retain in variable member revision only member revision finded
    member_revision = result[substring + 17:substring + 25]

    return(member_revision)

def get_member_change(path_lists_from_directory):

    # Initialize list with last dates updates
    list_with_files_last_updates_from_directory = []

    # For every path in directory
    for path in path_lists_from_directory:
        # call function PTC to get member information
        batcmd = path_to_si + "viewhistory --yes " + path

        # store in result output from cmd command executed
        result = subprocess.getoutput(batcmd)

        # search for member revision substring in all string
        substring = result[result.find('Jenkins Server 01 (Jenkins01)'):result.find('[')]

        test_string = substring.split("\t")

        # retain in variable member revision only member revision finded
        #member_revision = result[substring + 17:substring + 25]

        if len(test_string) != 1 and test_string[1] != None:
            list_with_files_last_updates_from_directory.append( test_string[1] )

    return list_with_files_last_updates_from_directory


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-i', '--input-path', help="Path to folder to check", required=True)
    parser.add_argument('-u', '--input-username', help="Username for PTC Account", required=True)
    parser.add_argument('-p', '--input-passowrd', help="Passowrd for PTC Account", required=True)
    args = parser.parse_args()


    # Connect to PTC
    PTCLogIn_flag = 0
    if (PTCLogIn_flag == 0):
        s = 1
        while (s == 1):
            s = os.system(path_to_si + "connect --hostname='ALVA-MKS01.alv.autoliv.int' --port='7001' --user=" + args.input_username + " --password=" + args.input_passowrd)
        PTCLogIn_flag = 1


    # Resync files from that folder
    batcmd =  path_to_si + "resync --overwriteChanged --sandbox " + args.input_path + " --yes"
    result = subprocess.getoutput(batcmd)
    #print(result)

    # split paths from output from cmd command
    path_lists_from_directory = result[25:].split('\n')
    del path_lists_from_directory[0]

    # if you need sometime member revision list, here it is
    member_revision_list = []
    for path in path_lists_from_directory:
        member_revision_list.append(get_member_revision_number(path))


    # Call api for getting dates from that directory
    list_with_dates_from_directory = get_member_change(path_lists_from_directory=path_lists_from_directory)

    # Get now time date
    today_date_and_time = today.strftime("%b %d, %Y %I:%M:%S %p")
    now_date = today.strptime(today_date_and_time, "%b %d, %Y %I:%M:%S %p")
    # print("today_date_and_time =", today_date_and_time) # for debug purpouse

    array_with_boolean_results_per_files = []

    for file_date in list_with_dates_from_directory:

        # Convert date from list to a date-type object
        converted_file_date = today.strptime(file_date, "%b %d, %Y %I:%M:%S %p")

        # If files has been updated today ( in current date )
        if now_date.date() == converted_file_date.date():

            # Get elapsed time until it was generated
            elapsedTime_string = now_date - converted_file_date

            # Get hours until last update
            elapsedTime_float_value = elapsedTime_string.total_seconds()/60/60

            
            # Check if file has been updated last maximum 8 hours ago
            if ( elapsedTime_float_value < 8 ):

                array_with_boolean_results_per_files.append('TRUE')
            else:
                array_with_boolean_results_per_files.append('FALSE')
        else:
            array_with_boolean_results_per_files.append('FALSE')


    # Define a variable initial true used for checking all files
    check_for_element = True

    # Check if all files has been updated
    for file_result in array_with_boolean_results_per_files:
        if file_result != 'TRUE':
            check_for_element = False
            break

    # Exit python script with return code
    if check_for_element == True:
        os.system('echo ALL FILES HAS BEEN UPDATED SUCCESFULY, AN EMAIL WILL BE SENT WITH GENERATED REPORTS!')
        sys.exit(0)
    else:
        os.system('echo ONE OR MORE FILES HAS NOT BEEN UPDATED, AN EMAIL WITH REPORTS CANNOT BEEN SENT!')
        sys.exit(1)


if __name__ == '__main__':
    main()