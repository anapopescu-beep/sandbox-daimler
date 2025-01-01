"""plm_tracker.py: Used to check document status in plm"""

__author__ = 'Dan Dustinta'
__copyright__ = "Copyright 2018, Autoliv Electronic"
__version__ = "2.0.0"
__email__ = 'dan.dustinta@autoliv.com'
__status__ = 'Released'

import sys
import os
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.keys import Keys
from selenium.common.exceptions import StaleElementReferenceException, NoSuchElementException, NoSuchWindowException
import yaml
import time
import csv


current_dir = os.getcwd()
sys.path.append(current_dir)

def plm_status_check(search_text):

    # disable extra warnings
    chromeOptions = webdriver.ChromeOptions()
    chromeOptions.add_experimental_option('useAutomationExtension', False)
    chromeOptions.add_experimental_option("excludeSwitches", ["enable-logging"])

    #launch plm page
    driver = webdriver.Chrome(options=chromeOptions, desired_capabilities=chromeOptions.to_capabilities()) # , desired_capabilities=chromeOptions.to_capabilities()
    driver.get('https://plm.autoliv.int')

    driver.maximize_window()
    time.sleep(1)

    try:
        elementName = WebDriverWait(driver, 5).until(EC.visibility_of_element_located((By.NAME, "login_name")))
        #elementName = driver.find_element_by_name('login_name')
        elementName.click()
        elementName.send_keys("PDM viewer")
        elementName.send_keys(Keys.RETURN)
    except:
        pass

    # # WebDriverWait(driver, 10).until(EC.visibility_of_element_located((By.XPATH, "/html/body/form/div[2]/div/div/div[1]/table/tbody/tr/td[6]")))
    # text_area = driver.find_element_by_xpath("/html/body/form/div[2]/div/div/div[1]/table/tbody/tr/td[6]")
    # text_area.click()

    # save main window handler
    main_window = driver.window_handles[0]

    # # WebDriverWait(driver, 10).until(EC.visibility_of_element_located((By.XPATH, "/html/body/div[4]/div/div/div/div/div[1]/ul[1]/li[2]")))
    # text_area = driver.find_element_by_xpath("/html/body/div[4]/div/div/div/div/div[1]/ul[1]/li[2]")
    # text_area.click()

    time.sleep(5)
    driver.get('https://plm.autoliv.int:10090/enovia/tvc-action/beginSearch/dummy.jsp?searchConfig=tvc%3Asearchconfig%2F%2Ftvc%2Feng%2Fdocument%2FDocumentsSearchConfig.xml&suiteKey=EngineeringCentral&StringResourceFileId=emxEngineeringCentralStringResource&SuiteDirectory=engineeringcentral&targetLocation=popup')

    # handle search window
    # pop_up_window = driver.window_handles[1]
    pop_up_window = driver.window_handles[0]
    driver.switch_to.window(pop_up_window)

    # wait for frame to load
    WebDriverWait(driver, 20).until(EC.visibility_of_element_located((By.XPATH, "//iframe[contains(@id, 'searchContentFrame')]")))

    # switch to iframe searchContentFrame
    driver.switch_to.frame(driver.find_element_by_name('searchContentFrame'))

    # wait for frame to load
    WebDriverWait(driver, 10).until(EC.visibility_of_element_located((By.XPATH, "//iframe[contains(@id, 'tableContentFrame')]")))

    # switch to iframe tableContentFrame
    driver.switch_to.frame(driver.find_element_by_name('tableContentFrame'))

    # identify input area for E-no
    input_area_list = driver.find_elements_by_xpath("//*[contains(@id, '_input')]")

    # input area for E-no is always 2nd
    input_area_list[2].click()
    input_area_list[2].send_keys(search_text + "*")

    # input area for last document is always 5th
    input_area_list[document_revision_type].click()

    # switch to parent frame
    driver.switch_to.parent_frame()

    # switch to iframe tableBottomFrame
    driver.switch_to.frame(driver.find_element_by_name('tableBottomFrame'))

    # identify Find button and click it
    find_area = driver.find_element_by_xpath("//*[contains(text(), 'Find')]")
    find_area.click()

    # switch to default content
    driver.switch_to.default_content()

    start_time = time.time()
    expires_in = 59 #in seconds

    # kill loop after 50s
    while (time.time() - start_time < expires_in):
        try:

            # switch to iframe searchContentFrame
            driver.switch_to.frame(driver.find_element_by_name('searchContentFrame'))

            # switch to iframe tableTopFrame
            driver.switch_to.frame(driver.find_element_by_name('tableTopFrame'))

            # poll title to get page readiness
            driver.find_element_by_xpath("//*[@id='header'][contains(text(), 'Search Results')]")
            break
        except (NoSuchElementException, NoSuchWindowException) as e:
            pass

    driver.maximize_window()


    # switch to parent frame
    driver.switch_to.parent_frame()

    # wait for frame to load
    WebDriverWait(driver, 10).until(EC.visibility_of_element_located((By.XPATH, "//iframe[contains(@id, 'tableContentFrame')]")))

    # switch to tableContentFrame
    driver.switch_to.frame(driver.find_element_by_name('tableContentFrame'))

    # wait for frame to load
    WebDriverWait(driver, 10).until(EC.visibility_of_element_located((By.XPATH, "//iframe[contains(@id, 'tableBodyRight')]")))

    # switch to tableBodyRight
    driver.switch_to.frame(driver.find_element_by_name('tableBodyRight'))

    # collect header and body information
    #header_left = driver.find_element_by_xpath("//*[@id='thl']")
    #header_right = driver.find_element_by_xpath("//*[@id='thr']")
    try:
        body_info = driver.find_element_by_xpath("//*[@id='tblc']")
    except:
        body_info = driver.find_element_by_xpath("//*[@name='tvcTableForm']")

    body = []

    t1 = body_info.find_elements_by_xpath("//*[@class='c']")
    for t2 in t1:
        body.append(t2.text.strip())

    # close search window
    driver.close()

    # close main window
    # driver.switch_to.window(main_window)

    driver.quit()

    return  body

def main():
    global document_revision_type

    with open("plm_config.yaml", 'r') as stream:
        try:
            plm_config = yaml.load(stream, Loader=yaml.FullLoader)
        except yaml.YAMLError as exc:
            print(exc)

    # header is hard-coded due to bad html structuring
    # default view for Manufacturing Process Specification Table
    header = ["", "", "", "", "Type", "Name", "Rev", "Title", "State", "", "Status",
              "Product Area", "Process Type", "Target Fulfilment Date", "Files",
              "Ver", "Drop File Area", "Authority", "Originator", "Originated",
              "Modifeid", ""]

    with open('{}.csv'.format(plm_config["document_name"]), 'w', newline='') as f:
        writer = csv.writer(f)

        writer.writerow(header)
        # debug purposes
        # print(header)

        if plm_config["document_revision_type"] == 'Last only':
            document_revision_type = 5
        elif plm_config["document_revision_type"] == 'Latest Released':
            document_revision_type = 6
        else:
            document_revision_type = 5

        for e_no in plm_config["tracked_documents"]:
            number_of_attemps = 1
            while number_of_attemps < 4:
                try:
                    status = plm_status_check(e_no)
                    writer.writerow(status)
                    # debug purposes
                    print(status)
                    break
                except Exception as e:
                    if ( number_of_attemps == 3):
                        os.system("echo FILE " + e_no +  " HAS NOT BEEN FOUND AFTER 3 ATTEMPTS! Exception caught: " + str(e)  )
                    number_of_attemps += 1
                    pass


if __name__ == "__main__":
    main()