__author__ = "Ardeleanu Lucian"
__copyright__ = "Autoliv, 2021"
__version__ = "1.14"
__maintainer__ = "Ardeleanu Lucian"
__email__ = "lucian.ardeleanu@autoliv.com"
__status__ = "Released"

# This script will clean env. of Reqtify, open Reqtify and generate reports.

# =================== IMPORTS =======================================

import pyautogui
import time
import subprocess
import os
import glob
import shutil
import argparse

# ======= API DEFINITION ============================================

def keep_computer_active():
    wh = pyautogui.size()  # Obtain the screen resolution.
    center_w = wh.width / 2
    center_h = wh.height / 2
    pyautogui.moveTo(center_w, center_h, duration=0.25)
    pyautogui.moveTo(center_w + 100, center_h, duration=0.25)
    pyautogui.moveTo(center_w + 100, center_h + 100, duration=0.25)
    pyautogui.moveTo(center_w, center_h + 100, duration=0.25)

# Function to check if process exist and work in background
def process_exists(process_name):
    call = 'TASKLIST', '/FI', 'imagename eq %s' % process_name
    # use buildin check_output right away
    output = subprocess.check_output(call).decode()
    # check in last line for process name
    last_line = output.strip().split('\r\n')[-1]
    # because Fail message could be translated
    return last_line.lower().startswith(process_name.lower())


def long_textbox():
    # Check if a long text box is appearing
    current_path = os.getcwd()

    counter = 0
    try:
        location = pyautogui.locateOnScreen(current_path + r'\buttons\notification_load_files_box.png')
    except:
        location = pyautogui.locateOnScreen(current_path + r'\buttons\notification_message_box.png')

    time.sleep(0.5)
    while location is None:
        try:
            location = pyautogui.locateOnScreen(current_path + r'\buttons\notification_load_files_box.png')
        except:
            location = pyautogui.locateOnScreen(current_path + r'\buttons\notification_message_box.png')

        keep_computer_active()
        counter += 1
        if counter == 3:
            break
    if location is not None:
        # Press enter on specific checkbox
        pyautogui.press('esc')


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-o', '--output-path', help="Path where to generate reports", required=True)
    parser.add_argument('-p', '--project-path', help="Reqtify Project Path", required=True)

    args = parser.parse_args()

    current_path = os.getcwd()

    path_where_to_generate = args.output_path
    reqtify_project_path = args.project_path

    reqtify_project_name = r'PP4G_E_Ph2.rqtf'

    # Delete old generated files:
    if os.path.exists(path_where_to_generate + '\PSE_1P1P_SBE_Software_Arhictecture_Matrix_TR6.xlsm'):
        os.remove(path_where_to_generate + '\PSE_1P1P_SBE_Software_Arhictecture_Matrix_TR6.xlsm')

    if os.path.exists(path_where_to_generate + '\PSE_1P1P_SBE_SW_Design_Matrix_TR6.xlsm'):
        os.remove(path_where_to_generate + '\PSE_1P1P_SBE_SW_Design_Matrix_TR6.xlsm')

    if os.path.exists(path_where_to_generate + '\PSE_1P1P_SBE_Software_Requirement_Matrix_TR6.xlsm'):
        os.remove(path_where_to_generate + '\PSE_1P1P_SBE_Software_Requirement_Matrix_TR6.xlsm')

    # Show Desktop Before Anything
    pyautogui.keyDown('winleft')
    time.sleep(0.5)
    pyautogui.press('d')
    pyautogui.keyUp('winleft')

    # Kill Process Excel
    if process_exists('EXCEL.EXE'):
        os.system("taskkill /f /im EXCEL.EXE")

    # Open Reqtify
    subprocess.Popen([r'C:\Program Files (x86)\Reqtify v2018 FD01\bin.w32\reqtify.exe'])
    time.sleep(5)
    os.system("taskkill /f /im reqtify.exe")
    time.sleep(1)

    subprocess.Popen([r'C:\Program Files (x86)\Reqtify v2018 FD01\bin.w32\reqtify.exe'])
    # Keeps a little delay
    time.sleep(5)

    # Maximize Window
    window = pyautogui.getActiveWindow()
    window.maximize()

    # Keeps delay after maximizing
    time.sleep(3)

    # Click on that location
    location = pyautogui.locateOnScreen(current_path + r'\buttons\open_project_button.png')
    pyautogui.click(location)


    # Keeps a delay until the window appear
    time.sleep(1)

    # ============OPEN REQTIFY PROJECT===================================
    # Open text bar search
    location = pyautogui.locateOnScreen(current_path + r'\buttons\project_path_bar.png')
    pyautogui.click(location)

    time.sleep(1)

    # Write path to our Reqtify project and hit an enter
    pyautogui.write(reqtify_project_path)
    pyautogui.write('\n')
    time.sleep(1)

    # Click on project
    location = pyautogui.locateOnScreen(current_path + r'\buttons\reqtify_project_file_name_textbox.PNG')
    pyautogui.click(location)
    pyautogui.write(reqtify_project_name)

    time.sleep(1)

    # Hit an enter button
    pyautogui.write('\n')

    # ===========END OF OPENING REQTIFY PROJECT=============================

    counter = 0
    location = pyautogui.locateOnScreen(current_path + r'\buttons\notification_message_box.png')
    time.sleep(1)

    while location is None:
        location = pyautogui.locateOnScreen(current_path + r'\buttons\notification_message_box.png')
        keep_computer_active()
        counter += 1
        if counter == 3:
            break
    if location is not None:
        # Press enter on specific checkbox
        pyautogui.write('\n')

    # Check if DOORS Login box has appeard

    counter = 0
    location = pyautogui.locateOnScreen(current_path + r'\buttons\doors_login_box.png')
    time.sleep(1)

    while location is None:
        location = pyautogui.locateOnScreen(current_path + r'\buttons\doors_login_box.png')
        keep_computer_active()
        counter += 1
        if counter == 3:
            break
    # if Doors login box has appeard, let's log in
    if location is not None:
        try:
            pyautogui.write('lucian.ardeleanu')
            pyautogui.write('\t')
            pyautogui.write('hahm94VsiT')
            pyautogui.write('\n')
        except:
            pyautogui.write('lucian.ardeleanu')
            pyautogui.press('tab')
            pyautogui.write('hahm94VsiT')
            pyautogui.press('enter')

    # Wait for DOORS to load up files
    location = pyautogui.locateOnScreen(current_path + r'\buttons\project_overview_window.png')
    while location is None:
        time.sleep(1)
        keep_computer_active()
        location = pyautogui.locateOnScreen(current_path + r'\buttons\project_overview_window.png')

    # Click on screen to show long text box
    pyautogui.click(location)

    # Check if a long textbox has appeard
    long_textbox()

    # GENERATE REPORTS

    # Generate Software Arhitecture Matrix report
    # =========================================================================

    # Click on Reports button
    location = pyautogui.locateOnScreen(current_path + r'\buttons\reports_button.png')
    pyautogui.click(location)
    time.sleep(1)

    # click on Project Reports
    location = pyautogui.locateOnScreen(current_path + r'\buttons\project_reports_arhitecture_button.png')
    pyautogui.click(location)
    time.sleep(1)

    # Click on SRM P025
    location = pyautogui.locateOnScreen(current_path + r'\buttons\sw_arch_matrix_button.png')
    pyautogui.click(location)
    time.sleep(1)

    location = pyautogui.locateOnScreen(current_path + r'\buttons\notification_message_box.png')
    if location is not None:
        pyautogui.press('enter')
    time.sleep(1)

    pyautogui.write(r'PSE_1P1P_SBE_Software_Arhictecture_Matrix_TR6')
    pyautogui.press('enter')

    time.sleep(10)

    # End of Sw Arch Matrix report generation

    # Check if it's loading something
    location = pyautogui.locateOnScreen(current_path + r'\buttons\report_generation_loading_box.png')
    if location is not None:
        while location is not None:
            time.sleep(1)
            keep_computer_active()
            location = pyautogui.locateOnScreen(current_path + r'\buttons\report_generation_loading_box.png')

    # Check if a long textbox has appeard
    long_textbox()
    time.sleep(5)

    while process_exists('EXCEL.EXE'):
        fw = pyautogui.getWindowsWithTitle('Excel')
        while len(fw) == 0:
            time.sleep(1)
            keep_computer_active()
            fw = pyautogui.getWindowsWithTitle('Excel')

        time.sleep(3)
        if len(fw) == 1:
            os.system("taskkill /f /im EXCEL.EXE")
            break
        time.sleep(1)

    time.sleep(5)
    # Move file
    if process_exists('EXCEL.EXE'):
        os.system("taskkill /f /im EXCEL.EXE")

    time.sleep(5)

    first_path = reqtify_project_path + "\PSE_1P1P_SBE_Software_Arhictecture_Matrix_TR6.xlsm"
    second_path = path_where_to_generate + "\PSE_1P1P_SBE_Software_Arhictecture_Matrix_TR6.xlsm"
    try:
        shutil.move(first_path, second_path)
    except:
        shutil.copy(first_path, second_path)

    # END OF GENERATED FILE
    # =========================================================================

    time.sleep(1)
    location = pyautogui.locateOnScreen(current_path + r'\buttons\project_overview_window.png')
    pyautogui.click(location)
    time.sleep(1)

    # Generate SDM Matrix report
    # =========================================================================

    # Click on Reports button
    location = pyautogui.locateOnScreen(current_path + r'\buttons\reports_button.png')
    pyautogui.click(location)
    time.sleep(1)

    # click on Project Reports
    location = pyautogui.locateOnScreen(current_path + r'\buttons\project_reports_arhitecture_button.png')
    pyautogui.click(location)
    time.sleep(1)

    # Click on SRM P025
    location = pyautogui.locateOnScreen(current_path + r'\buttons\sdm_matrix_button.png')
    pyautogui.click(location)
    time.sleep(1)

    location = pyautogui.locateOnScreen(current_path + r'\buttons\notification_message_box.png')
    if location is not None:
        pyautogui.press('enter')
    time.sleep(1)

    pyautogui.write(r'PSE_1P1P_SBE_SW_Design_Matrix_TR6')
    pyautogui.press('enter')


    # End of SDM report generation
    long_textbox()
    time.sleep(10)

    # Check if it's loading something
    location = pyautogui.locateOnScreen(current_path + r'\buttons\report_generation_loading_box.png')
    if location is not None:
        while location is not None:
            time.sleep(1)
            keep_computer_active()
            location = pyautogui.locateOnScreen(current_path + r'\buttons\report_generation_loading_box.png')

    time.sleep(5)

    while process_exists('EXCEL.EXE'):
        fw = pyautogui.getWindowsWithTitle('Excel')
        while len(fw) == 0:
            time.sleep(1)
            keep_computer_active()
            fw = pyautogui.getWindowsWithTitle('Excel')
        time.sleep(3)
        if len(fw) == 1:
            os.system("taskkill /f /im EXCEL.EXE")
            break
        time.sleep(1)

    time.sleep(5)
    # Move file
    if process_exists('EXCEL.EXE'):
        os.system("taskkill /f /im EXCEL.EXE")

    time.sleep(5)
    first_path = reqtify_project_path + "\PSE_1P1P_SBE_SW_Design_Matrix_TR6.xlsm"
    second_path = path_where_to_generate + "\PSE_1P1P_SBE_SW_Design_Matrix_TR6.xlsm"
    try:
        shutil.move(first_path, second_path)
    except:
        shutil.copy(first_path, second_path)

    # END OF GENERATED FILE
    # =========================================================================

    time.sleep(1)
    location = pyautogui.locateOnScreen(current_path + r'\buttons\project_overview_window.png')
    pyautogui.click(location)
    time.sleep(1)

    # Generate SRM Matrix report
    # =========================================================================

    # Click on Reports button
    location = pyautogui.locateOnScreen(current_path + r'\buttons\reports_button.png')
    pyautogui.click(location)
    time.sleep(1)

    # click on Project Reports
    location = pyautogui.locateOnScreen(current_path + r'\buttons\project_reports_button.png')
    pyautogui.click(location)
    time.sleep(1)

    # Click on SRM P025
    location = pyautogui.locateOnScreen(current_path + r'\buttons\srm_matrix_button.png')
    pyautogui.click(location)
    time.sleep(1)

    location = pyautogui.locateOnScreen(current_path + r'\buttons\notification_message_box.png')
    if location is not None:
        pyautogui.press('enter')
    time.sleep(1)

    pyautogui.write(r'PSE_1P1P_SBE_Software_Requirement_Matrix_TR6')
    pyautogui.press('enter')
    time.sleep(1)

    # End of Sw Arch Matrix report generation
    # Check if a long textbox has appeard
    long_textbox()
    time.sleep(10)

    # Check if it's loading something
    location = pyautogui.locateOnScreen(current_path + r'\buttons\report_generation_loading_box.png')
    if location is not None:
        while location is not None:
            time.sleep(1)
            keep_computer_active()
            location = pyautogui.locateOnScreen(current_path + r'\buttons\report_generation_loading_box.png')

    # Check if a long textbox has appeard
    long_textbox()

    while process_exists('EXCEL.EXE'):
        fw = pyautogui.getWindowsWithTitle('Excel')
        while len(fw) == 0:
            time.sleep(1)
            keep_computer_active()
            fw = pyautogui.getWindowsWithTitle('Excel')
        time.sleep(3)
        if len(fw) == 1:
            os.system("taskkill /f /im EXCEL.EXE")
            break
        time.sleep(1)

    time.sleep(5)
    # Move file
    if process_exists('EXCEL.EXE'):
        os.system("taskkill /f /im EXCEL.EXE")

    time.sleep(5)

    first_path = reqtify_project_path + "\PSE_1P1P_SBE_Software_Requirement_Matrix_TR6.xlsm"
    second_path = path_where_to_generate + "\PSE_1P1P_SBE_Software_Requirement_Matrix_TR6.xlsm"
    try:
        shutil.move(first_path, second_path)
    except:
        shutil.copy(first_path, second_path)

    # END OF GENERATED FILE
    # =========================================================================

    time.sleep(1)
    location = pyautogui.locateOnScreen(current_path + r'\buttons\project_overview_window.png')
    pyautogui.click(location)
    time.sleep(1)

    # Generate SYSRM Matrix report
    # =========================================================================

    # Click on Reports button
    location = pyautogui.locateOnScreen(current_path + r'\buttons\reports_button.png')
    pyautogui.click(location)
    time.sleep(1)

    # click on Project Reports
    location = pyautogui.locateOnScreen(current_path + r'\buttons\system_reports_button.PNG')
    pyautogui.click(location)
    time.sleep(1)

    # Click on SRM P025
    location = pyautogui.locateOnScreen(current_path + r'\buttons\sysrm_matrix_button.PNG')
    pyautogui.click(location)
    time.sleep(1)

    location = pyautogui.locateOnScreen(current_path + r'\buttons\notification_message_box.png')
    if location is not None:
        pyautogui.press('enter')
    time.sleep(1)

    pyautogui.write(r'PSE_1P1P_RCM_System_Requirement_Matrix_TR6')
    pyautogui.press('enter')
    time.sleep(1)

    # End of Sw Arch Matrix report generation
    # Check if a long textbox has appeard
    long_textbox()
    time.sleep(10)

    # Check if it's loading something
    location = pyautogui.locateOnScreen(current_path + r'\buttons\report_generation_loading_box.png')
    if location is not None:
        while location is not None:
            time.sleep(1)
            keep_computer_active()
            location = pyautogui.locateOnScreen(current_path + r'\buttons\report_generation_loading_box.png')

    # Check if a long textbox has appeard
    long_textbox()

    while process_exists('EXCEL.EXE'):
        fw = pyautogui.getWindowsWithTitle('Excel')
        while len(fw) == 0:
            time.sleep(1)
            keep_computer_active()
            fw = pyautogui.getWindowsWithTitle('Excel')
        time.sleep(3)
        if len(fw) == 1:
            os.system("taskkill /f /im EXCEL.EXE")
            break
        time.sleep(1)

    time.sleep(5)
    # Move file
    if process_exists('EXCEL.EXE'):
        os.system("taskkill /f /im EXCEL.EXE")

    time.sleep(5)

    first_path = reqtify_project_path + "\PSE_1P1P_RCM_System_Requirement_Matrix_TR6.xlsm"
    second_path = path_where_to_generate + "\PSE_1P1P_RCM_System_Requirement_Matrix_TR6.xlsm"
    try:
        shutil.move(first_path, second_path)
    except:
        shutil.copy(first_path, second_path)

    # END OF GENERATED FILE
    # =========================================================================

    time.sleep(1)
    location = pyautogui.locateOnScreen(current_path + r'\buttons\project_overview_window.png')
    pyautogui.click(location)
    time.sleep(1)

    # Generate PRM Matrix report
    # =========================================================================

    # Click on Reports button
    location = pyautogui.locateOnScreen(current_path + r'\buttons\reports_button.png')
    pyautogui.click(location)
    time.sleep(1)

    # click on Project Reports
    location = pyautogui.locateOnScreen(current_path + r'\buttons\project_reports_button.png')
    pyautogui.click(location)
    time.sleep(1)

    # Click on SRM P025
    location = pyautogui.locateOnScreen(current_path + r'\buttons\prm_matrix_button.PNG')
    pyautogui.click(location)
    time.sleep(1)

    location = pyautogui.locateOnScreen(current_path + r'\buttons\notification_message_box.png')
    if location is not None:
        pyautogui.press('enter')
    time.sleep(1)

    pyautogui.write(r'PSE_1P1P_SBE_Product_Requirement_Matrix_TR6')
    pyautogui.press('enter')
    time.sleep(1)

    # End of Sw Arch Matrix report generation
    # Check if a long textbox has appeard
    long_textbox()
    time.sleep(10)

    # Check if it's loading something
    location = pyautogui.locateOnScreen(current_path + r'\buttons\report_generation_loading_box.png')
    if location is not None:
        while location is not None:
            time.sleep(1)
            keep_computer_active()
            location = pyautogui.locateOnScreen(current_path + r'\buttons\report_generation_loading_box.png')

    # Check if a long textbox has appeard
    long_textbox()

    while process_exists('EXCEL.EXE'):
        fw = pyautogui.getWindowsWithTitle('Excel')
        while len(fw) == 0:
            time.sleep(1)
            keep_computer_active()
            fw = pyautogui.getWindowsWithTitle('Excel')
        time.sleep(3)
        if len(fw) == 1:
            os.system("taskkill /f /im EXCEL.EXE")
            break
        time.sleep(1)

    time.sleep(5)
    # Move file
    if process_exists('EXCEL.EXE'):
        os.system("taskkill /f /im EXCEL.EXE")

    time.sleep(5)

    first_path = reqtify_project_path + "\PSE_1P1P_SBE_Product_Requirement_Matrix_TR6.xlsm"
    second_path = path_where_to_generate + "\PSE_1P1P_SBE_Product_Requirement_Matrix_TR6.xlsm"
    try:
        shutil.move(first_path, second_path)
    except:
        shutil.copy(first_path, second_path)

    # END OF GENERATED FILE
    # =========================================================================

    # Close Reqtify
    os.system("taskkill /f /im reqtify.exe")


if __name__ == '__main__':
    main()
