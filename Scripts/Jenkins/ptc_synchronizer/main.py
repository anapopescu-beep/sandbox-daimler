"""ptc_issue_updater.py: Updates issues in PTC(due date, asigned user)"""

__author__ = 'Dan Dustinta'
__copyright__ = "Copyright 2018, Autoliv Electronic"
__version__ = "1.0.0"
__email__ = 'dan.dustinta@autoliv.com'
__status__ = 'Draft'

import os
import sys
from pandas import *
import logging
import pandas as pd

from const_library import *
from std_functions import *
from mod_functions import *
from mod_config import *

currentDir = os.getcwd()
sys.path.append(currentDir)

def main():

    xls = ExcelFile('TestProject.xlsx')
    mpp_export = xls.parse(xls.sheet_names[0], dtype={'UID':str, '% Complete':float})
    mpp_export = mpp_export.where(pd.notnull(mpp_export), None)
    mpp_export = mpp_export.to_dict()

    for row, ptc_issue_id in mpp_export["UID"].items():
        if ptc_issue_id is not None:

            switch = {
                "(Submitted)": sync_Submitted,
                "(To Be Analyzed)": sync_ToBeAnalyzed,
                "(Analyzed)": sync_Analyzed,
                "(To Be Implemented)": sync_ToBeImplemented,
                "(Implemented)": sync_Implemented,
                "(To Be Reviewed)": sync_ToBeReviewed,
                "(Reviewed)": sync_Reviewed,
                "(To Be Verified)": sync_ToBeVerified,
                "(Verified)": sync_Verified,
                "(Closed)": sync_Closed,
            }

            # Get the function from switcher dictionary
            func = switch.get(mpp_export["State"][row], lambda: "Invalid state")
            # Execute the function
            mpp_dict = func(mpp_export, row)

            # if state is not supported, then skip it
            if type(mpp_dict) is not dict:
                continue

            ###ToDo: Format duration from 8h 1d to number only
            ###ToDo: Configure Release Container/Release Canndidate from SW Schedule

            # read information that you want to edit
            cmd_line_dump = run_command_str(ptc_view_issue_cmd.format(ptc_issue_id=mpp_dict["UID"]))

            ptc_issue_dict = {}

            for line in cmd_line_dump.split('\n'):
                for field in ptc_im_commandline_fields:
                    if field in line:
                        if field.replace(":", "") not in ptc_issue_dict:
                            ptc_issue_dict[field.replace(":", "")] = line.lstrip(field)
            final_cmd_field_value_pair = ""
            for desired_field, desired_value in mpp_dict.items():
                selected_field_real = find_alias_in_dict(desired_field, mpp_to_ptc_field_mapping)
                selected_field_view = find_alias_in_dict(selected_field_real, ptc_real_to_view_value_mapping)

                # format data if needed
                if selected_field_real in ptc_im_ei_field_dispatch_formatting and ptc_im_ei_field_dispatch_formatting[selected_field_real] is not None:
                    if selected_field_real in ptc_im_field_date_formatting and ptc_im_field_date_formatting[selected_field_real] is not None:
                        selected_field_value = ptc_im_ei_field_dispatch_formatting[selected_field_real](desired_value, ptc_im_field_date_formatting[selected_field_real])
                    else:
                        selected_field_value = ptc_im_ei_field_dispatch_formatting[selected_field_real](desired_value)
                else:
                    selected_field_value = desired_value

                if selected_field_real is not None and selected_field_view is not None:
                    # check if field is visible
                    if ptc_issue_dict["State"].strip() not in ptc_im_field_restrictions[selected_field_real]:
                        # field is not visible
                        print("w02: '{}' is not visible for the current item State: {}.".format(selected_field_view, ptc_issue_dict["State"].strip()))
                    elif ptc_im_field_restrictions[selected_field_real][ptc_issue_dict["State"].strip()] == visible_not_editable:
                        # field is not editable
                        print("w03: '{}' is not editable in the current item State: {}.".format(selected_field_view, ptc_issue_dict["State"].strip()))

                    selected_field_value_for_vi = selected_field_value

                    # apply special formatting if needed
                    if selected_field_real in ptc_im_vi_field_dispatch_formatting and ptc_im_vi_field_dispatch_formatting[selected_field_real] is not None:
                            selected_field_value_for_vi = ptc_im_vi_field_dispatch_formatting[selected_field_real](desired_value)

                    if selected_field_view in ptc_issue_dict:
                        # compare with existing content
                        if ptc_issue_dict[selected_field_view].strip() == str(selected_field_value_for_vi):
                            if verbosity_level != 0:
                                print("w01: '{}' was not updated since the field content is the same.".format(selected_field_view))

                    ret_comparison = False

                    if selected_field_real in ptc_im_vi_field_dispatch_comparison and ptc_im_vi_field_dispatch_comparison[selected_field_real] is not None:
                        ret_comparison = ptc_im_vi_field_dispatch_comparison[selected_field_real](desired_value)

                    if ret_comparison == True:
                        print("w04: '{}' was not updated since the field comparison rule is True.".format(selected_field_view))
                    else:
                        # write content
                        final_cmd_field_value_pair += ''' --field="{ptc_field}"="{ptc_field_value}"'''.format(ptc_field=selected_field_real, ptc_field_value=selected_field_value)

            cmd_line_dump = run_command_str(ptc_edit_issue_cmd.format(ptc_field_value=final_cmd_field_value_pair, ptc_issue_id=mpp_dict["UID"]))

            logging.basicConfig(filename='sync.log', format='%(asctime)s %(message)s', level=logging.DEBUG)
            logging.info(ptc_edit_issue_cmd.format(ptc_field_value=final_cmd_field_value_pair, ptc_issue_id=mpp_dict["UID"]))

            if 'Updated item' not in cmd_line_dump:
                print(cmd_line_dump)
                logging.error(cmd_line_dump)
            else:
                print('Item {} was updated succesfully'.format(mpp_dict["UID"]))

if __name__ == '__main__':
    main()





