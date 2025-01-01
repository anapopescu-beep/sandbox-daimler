__author__ = "Ardeleanu Lucian"
__copyright__ = "Autoliv, 2021"
__version__ = "???"
__maintainer__ = "Ardeleanu Lucian"
__email__ = "lucian.ardeleanu@autoliv.com"
__status__ = "Released"

# Imports
from distutils.dir_util import copy_tree
import glob
import shutil
from shutil import copyfile
import argparse
import os
import time
import subprocess
from natsort import natsorted, ns


# Function to delete intermediare files
def delete_files__with_exceptions(file_path):
    # Set path to clean files ( set corect folder )
    file_path = file_path + '\intermediate'

    # File to except from being deleted
    file_to_except = 'System Architecture EA.xml'

    # Get a list of all files in that folder
    file_list = glob.glob(file_path + '/*.*')

    # Remove from list file you want to except
    for f in file_list:
        if file_to_except in f:
            file_list.remove(f)
    # Delete files from list

    for element in file_list:
        os.remove(element)

    # Remove all folders from specific folder
    folders = [f for f in glob.glob(file_path + "/**/", recursive=False)]
    for folder in folders:
        shutil.rmtree(folder)


def copy_folders_from_view_test_to_view_development(path_to_view_test, path_to_view_development):

    # Get a list of all folders in path
    folders = [ f.path for f in os.scandir(path_to_view_development + '\Tests') if f.is_dir() ]

    # If folder found, delete it because it will be updated
    for folder in folders:
        if 'Tests_Verification_Qualification' in folder:
            shutil.rmtree(folder)
        if 'Test_System_Integration' in folder:
            shutil.rmtree(folder)
        if 'Test_System_Qualification' in folder:
            shutil.rmtree(folder)

    # Copy folder from view development to view test
    # In ALL COPIES, USE ROBOCOPY TO WAIT UNTIL COPY HAS BEEN FINISHED
    subprocess.call('ROBOCOPY /S /E ' + path_to_view_test + '\Tests\Tests_Verification_Qualification' + ' ' + path_to_view_development + '\Tests\Tests_Verification_Qualification', shell=True)

    subprocess.call('ROBOCOPY /S /E ' + path_to_view_test + '\Tests\Test_System_Integration' + ' ' + path_to_view_development + '\Tests\Test_System_Integration',shell=True)

    subprocess.call('ROBOCOPY /S /E ' + path_to_view_test + '\Tests\Test_System_Qualification' + ' ' + path_to_view_development + '\Tests\Test_System_Qualification',shell=True)


    print('Folders updated successfully!')


def keep_only_last_release_of_summary_report(path_to_summary_report_folder):

    # Extract all folder contents into a list
    list_with_content = os.listdir(path_to_summary_report_folder)

    # Here are keeped only docx files in directory
    summary_report_files = []
    for file in list_with_content:
        if os.path.isfile(os.path.join(path_to_summary_report_folder, file)) and file.endswith('.docx') and 'Summary_Report' in file:
            summary_report_files.append(file)

    # Sort list
    sorted_list = natsorted(summary_report_files)

    # Remove all files unless last item
    for file_index in range(0, len(sorted_list) - 1):
        os.remove(os.path.join(path_to_summary_report_folder, sorted_list[file_index]))


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-p', '--project-path', help="Reqtify Project Path", required=True)
    parser.add_argument('-d', '--development-path', help="Path to view development path", required=True)
    parser.add_argument('-t', '--test-path', help="Path to view test path", required=True)

    args = parser.parse_args()

    reqtify_project_path = args.project_path
    path_to_view_development = args.development_path
    path_to_view_test = args.test_path

    # Detele intermediare files
    delete_files__with_exceptions(reqtify_project_path)
    os.system('echo ALL FILES AND FOLDERS EXCEPT SYSTEM ARCHITECTURE.xml ARE DELETED FROM INTERMEDIATE FOLDER PATH')

    # Delete Reqtify image file
    if os.path.exists(reqtify_project_path + '\PP4G_E_Ph2.rqtfimage'):
        os.remove(reqtify_project_path + '\PP4G_E_Ph2.rqtfimage')
        os.system('echo FILE PP4G_E_Ph2.rqtfimage HAS BEEN DELETED SUCCESFULLY ')

    os.system('echo UPDATE VIEW TEST AND VIEW DEVELOPMENT TEST QUALIFICATION INTEGRATION FOLDER ')
    copy_folders_from_view_test_to_view_development(path_to_view_test= path_to_view_test, path_to_view_development= path_to_view_development)

    keep_only_last_release_of_summary_report(path_to_summary_report_folder=os.path.join(path_to_view_development, "Tests\Test_System_Integration\Automatic_Tests"))
    keep_only_last_release_of_summary_report(path_to_summary_report_folder=os.path.join(path_to_view_development, "Tests\Tests_Verification_Qualification\Automatic_Tests"))
    keep_only_last_release_of_summary_report(path_to_summary_report_folder=os.path.join(path_to_view_development, "Tests\Test_System_Qualification\Automatic_Tests"))

if __name__ == '__main__':
    main()
