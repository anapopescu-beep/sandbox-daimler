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

    # Copy folder from view development to view test
    # In ALL COPIES, USE ROBOCOPY TO WAIT UNTIL COPY HAS BEEN FINISHED
    subprocess.call('ROBOCOPY /S /E ' + path_to_view_test + '\Tests\Tests_Verification_Qualification' + ' ' + path_to_view_development + '\Tests\Tests_Verification_Qualification', shell=True)

    # Copy folder in order to duplicate and chage name
    subprocess.call('ROBOCOPY /S /E ' + path_to_view_development + '\Tests\Tests_Verification_Qualification\Automatic_Tests' + ' ' + path_to_view_development + '\Tests\Tests_Verification_Qualification\Automatic_Tests_DES', shell=True)

    # Rename left folder in order to change it
    os.rename(path_to_view_development + '\Tests\Tests_Verification_Qualification\Automatic_Tests', path_to_view_development + '\Tests\Tests_Verification_Qualification\Automatic_Tests_SYS')

    # for debug purposes
    os.system('echo FOLDER HAS BEEN COPIED AND RENAMED SUCCESFULLY')

    # get a list of folders in automatic tests_des
    folders_in_automatic_tests_des = [f.path for f in os.scandir(path_to_view_development + '\Tests\Tests_Verification_Qualification\Automatic_Tests_DES') if f.is_dir()]

    # for every folder in automatic test
    for folder in folders_in_automatic_tests_des:

        current_folder = [ f.path for f in os.scandir(folder) if f.is_dir() ]

        # remove anything that not contains TF in folders
        for subfolder in current_folder:
            if 'TF' not in subfolder:
                shutil.rmtree(subfolder)
    # for debug purposes
    os.system('echo DES FOLDER HAS BEEN UUPDTED SUCCESFULLY')

    # get a list of folders in automatic tests_des
    folders_in_automatic_tests_sys = [f.path for f in os.scandir( path_to_view_development + '\Tests\Tests_Verification_Qualification\Automatic_Tests_SYS' ) if f.is_dir()]

    # # for every folder in automatic test
    for folder_sys in folders_in_automatic_tests_sys:
         current_folder_sys = [f.path for f in os.scandir( folder_sys ) if f.is_dir()]

         # remove anything that not contains TF in folders
         for subfolder_sys in current_folder_sys:
             if 'MF' not in subfolder_sys and 'SF' not in subfolder_sys :
                 shutil.rmtree(subfolder_sys)
    # for debug purposes
    os.system('echo SYS FOLDER HAS BEEN UUPDTED SUCCESFULLY')


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

if __name__ == '__main__':
    main()
