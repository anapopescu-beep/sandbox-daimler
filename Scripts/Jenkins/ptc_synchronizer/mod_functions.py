import datetime
from mod_config import *

analysis_sub_task_offset = 1
requirements_sub_task_offset = 2
requirements_review_sub_task_offset = 3
architecture_sub_task_offset = 4
architecture_review_sub_task_offset = 5
design_sub_task_offset = 6
design_review_sub_task_offset = 7
implementation_sub_task_offset = 8
qac_sub_task_offset = 9
implementation_review_sub_task_offset = 10
unit_test_sub_task_offset = 11
unit_test_review_sub_task_offset = 12
integration_test_sub_task_offset = 13
integration_test_review_sub_task_offset = 14

def find_alias_in_dict(value, dict):
    ret_val = None

    for field in dict:
        if value == field:
            ret_val = dict[field]
            break

    return  ret_val

def format_team_member_name_for_ptc_vi(name):
    ret_val = None

    ret_val = "{} ({}.{})".format(name,
        name.split(' ')[0].lower(),
        name.split(' ')[1].lower()
    )

    return ret_val

def format_team_member_name_for_ptc_ei(name):
    ret_val = None

    ret_val = "{}.{}".format(name.split(' ')[0].lower(),
        name.split(' ')[1].lower()
    )

    return ret_val

def format_duration_to_hrs(duration):

    duration = duration.replace('?', '')

    if 'mon' in duration:
        duration = str(int(duration.replace('mon', '').strip()) * 31 * 8)
    elif 'wk' in duration:
        duration = str(int(duration.replace('wk', '').strip()) * 7 * 8)
    elif 'day' in duration or 'days' in duration:
        duration = str(int(duration.replace('days', '').replace('day', '').strip()) * 8)
    elif 'hrs' in duration:
        duration = str(duration.replace('days', '').strip())

    return duration


def format_date_time(date, variant):
    ret_val = None

    date_time_obj = datetime.datetime.strptime(date, '%a %d.%m.%y')  # mpp format: Tue 24.11.20

    if variant == 1:
        ret_val = date_time_obj.strftime("%b %d, %Y")  # Oct 16, 2020
    elif variant == 2:
        ret_val = date_time_obj.strftime("%b %d, %Y %H:%M:%S %p")  # Jan 21, 2021 4:37:41 PM
    elif variant == 3:
        ret_val = date_time_obj.strftime("%b %d, %Y GMT+01:00")  # Jan 21, 2021 GMT+01:00

    return ret_val

def compare_analysis(orig_description):
    ret_val = True

    keywords = ['Analysis:', 'Root Cause:', 'Reproducibility:', 'Affected Modules or SW Components:', 'Workproduct Verification and Complexity:']

    for keyword in keywords:
        if keyword in orig_description:
            continue
        else:
            # keyword not found
            ret_val = False
            break

    return ret_val

def sync_Submitted(local_mpp_export, local_row):
    return "N/A"

def sync_ToBeAnalyzed(local_mpp_export, local_row):

    task_token = ' - Analysis'
    ret_dict = {}

    # sub task found, proceed to dump appropriate information in PTC item
    if task_token in local_mpp_export["Task Name"][local_row+analysis_sub_task_offset]:
        ret_dict['Description'] = \
"""<First_Name> <Last_Name> <dd.mm.yyyy>:
        Analysis:
                Root Cause:
                Reproducibility: (e.g. Sporadic: Low Frequency/Sporadic: High Frequency/Always)
                Affected Modules or SW Components: (e.g. Adc/CIL/DIA/etc. or Beltstack/Diagnostics/MCAL/OS/etc.)
                Impact and Complexity:
                        Requirements: (e.g. None/Low/Medium/High)
                        Architecture: (e.g. None/Low/Medium/High)
                        Design: (e.g. None/Low/Medium/High)
                        Code: (e.g. None/Low/Medium/High)
                Workproduct Verification and Complexity:
                        Qualification Tests: (e.g. None/Low/Medium/High)
                        Integration Tests: (e.g. None/Low/Medium/High)
                        Unit Tests: (e.g. None/Low/Medium/High)
                        Unit Verification: (e.g. None/Low/Medium/High)
                
<First_Name> <Last_Name> <dd.mm.yyyy>:
        Implementation:
                (Describe implementation outcome for affected workproducts)
            
<First_Name> <Last_Name> <dd.mm.yyyy>:
        Review:
                (Describe review outcome for affected workproducts)
        """

        ret_dict['State'] = local_mpp_export["State"][local_row]
        ret_dict['UID'] = local_mpp_export["UID"][local_row]
        ret_dict['Resource Names' + task_token] = local_mpp_export["Resource Names"][local_row + analysis_sub_task_offset]
        ret_dict['Duration Est' + task_token] = local_mpp_export["Duration"][local_row + analysis_sub_task_offset]
        ret_dict['Finish' + task_token] = local_mpp_export["Finish"][local_row + analysis_sub_task_offset]

        ret_dict['Requirements_Est_Effort'] = local_mpp_export["Duration"][local_row + requirements_sub_task_offset]
        # ret_dict['Requirements_Act_Effort'] = '0'
        # ret_dict['Requirements_Status'] = 'Not Required'

        ret_dict['Architecture_Est_Effort'] = local_mpp_export["Duration"][local_row + architecture_sub_task_offset]
        # ret_dict['Architecture_Act_Effort'] = '0'
        # ret_dict['Architecture_Status'] = 'Not Required'

        ret_dict['Design_Est_Effort'] = local_mpp_export["Duration"][local_row + design_sub_task_offset]
        # ret_dict['Design_Act_Effort'] = '0'
        # ret_dict['Design_Status'] = 'Not Required'

        ret_dict['Implementation_Est_Effort'] = local_mpp_export["Duration"][local_row + implementation_sub_task_offset]
        # ret_dict['Implementation_Act_Effort'] = '0'
        # ret_dict['Implementation_Status'] = 'Not Required'

        ret_dict['QAC_Est_Effort'] = local_mpp_export["Duration"][local_row + qac_sub_task_offset]
        # ret_dict['QAC_Act_Effort'] = '0'
        # ret_dict['QAC_Status'] = 'Not Required'

        ret_dict['UnitTest_Est_Effort'] = local_mpp_export["Duration"][local_row + unit_test_sub_task_offset]
        # ret_dict['UnitTest_Act_Effort'] = '0'
        # ret_dict['UnitTest_Status'] = 'Not Required'

        ret_dict['Integration_Est_Effort'] = local_mpp_export["Duration"][local_row + integration_test_sub_task_offset]
        # ret_dict['Integration_Act_Effort'] = '0'
        # ret_dict['Integration_Status'] = 'Not Required'

    return ret_dict

def sync_Analyzed(local_mpp_export, local_row):
    analysis_sub_task_offset = 1

    task_token = ' - Analysis'
    ret_dict = {}

    # sub task found, proceed to dump appropriate information in PTC item
    if task_token in local_mpp_export["Task Name"][local_row + analysis_sub_task_offset]:
        ret_dict['State'] = local_mpp_export["State"][local_row]
        ret_dict['UID'] = local_mpp_export["UID"][local_row]
        ret_dict['Resource Names' + task_token] = local_mpp_export["Resource Names"][local_row + analysis_sub_task_offset]
        ret_dict['Duration Act' + task_token] = local_mpp_export["Duration"][local_row + analysis_sub_task_offset]
        ret_dict['Finish' + task_token] = local_mpp_export["Finish"][local_row + analysis_sub_task_offset]

    return ret_dict


def sync_ToBeImplemented(local_mpp_export, local_row):

    implementation_types_list = [
        requirements_sub_task_offset,
        # requirements_review_sub_task_offset,
        architecture_sub_task_offset,
        # architecture_review_sub_task_offset,
        design_sub_task_offset,
        # design_review_sub_task_offset,
        implementation_sub_task_offset,
        qac_sub_task_offset,
        # implementation_review_sub_task_offset,
        unit_test_sub_task_offset,
        # unit_test_review_sub_task_offset,
        integration_test_sub_task_offset,
        # integration_test_review_sub_task_offset
        ]

    ret_dict = {}
    task_token = None

    ret_dict['Restraints_Target_Release_Container'] = release_containter
    ret_dict['Restraints_Target_Software_Release'] = software_release

    for implementation_type in implementation_types_list:
        # check if task is completed to determine which task is next and which user to assign
        if str(int(local_mpp_export['% Complete'][local_row+implementation_type]*100)) + "%" != "100%":
            if implementation_type == requirements_sub_task_offset:
                task_token = ' - Requirements'
            elif implementation_type == architecture_sub_task_offset:
                task_token = ' - Architecture'
            elif implementation_type == design_sub_task_offset:
                task_token = ' - Design'
            elif implementation_type == implementation_sub_task_offset:
                task_token = ' - Implementation'
            elif implementation_type == qac_sub_task_offset:
                task_token = ' - QAC'
            elif implementation_type == unit_test_sub_task_offset:
                task_token = ' - Unit'
            elif implementation_type == integration_test_sub_task_offset:
                task_token = ' - Integration'

        if task_token is not None:
            break

    ret_dict['Resource Names' + task_token] = local_mpp_export["Resource Names"][local_row + implementation_type]
    ret_dict['Finish' + task_token] = local_mpp_export["Finish"][local_row + implementation_type]

    ret_dict['State'] = local_mpp_export["State"][local_row]
    ret_dict['UID'] = local_mpp_export["UID"][local_row]

    return ret_dict

def sync_Implemented(local_mpp_export, local_row):

    implementation_types_list = [
        requirements_sub_task_offset,
        # requirements_review_sub_task_offset,
        architecture_sub_task_offset,
        # architecture_review_sub_task_offset,
        design_sub_task_offset,
        # design_review_sub_task_offset,
        implementation_sub_task_offset,
        qac_sub_task_offset,
        # implementation_review_sub_task_offset,
        unit_test_sub_task_offset,
        # unit_test_review_sub_task_offset,
        integration_test_sub_task_offset,
        # integration_test_review_sub_task_offset
        ]

    ret_dict = {}

    for implementation_type in implementation_types_list:
        # check if task is completed to determine which task is next and which user to assign
        if str(int(local_mpp_export['% Complete'][local_row+implementation_type]*100)) + "%" == "100%" and \
               str(int(local_mpp_export['% Complete'][local_row+implementation_type])) != '0':
            if implementation_type == requirements_sub_task_offset:
                ret_dict['Requirements_Act_Effort'] = local_mpp_export["Duration"][local_row + requirements_sub_task_offset]
            elif implementation_type == architecture_sub_task_offset:
                ret_dict['Architecture_Act_Effort'] = local_mpp_export["Duration"][local_row + architecture_sub_task_offset]
            elif implementation_type == design_sub_task_offset:
                ret_dict['Design_Act_Effort'] = local_mpp_export["Duration"][local_row + design_sub_task_offset]
            elif implementation_type == implementation_sub_task_offset:
                ret_dict['Implementation_Act_Effort'] = local_mpp_export["Duration"][local_row + implementation_sub_task_offset]
            elif implementation_type == qac_sub_task_offset:
                ret_dict['QAC_Act_Effort'] = local_mpp_export["Duration"][local_row + qac_sub_task_offset]
            elif implementation_type == unit_test_sub_task_offset:
                ret_dict['UnitTest_Act_Effort'] = local_mpp_export["Duration"][local_row + unit_test_sub_task_offset]
            elif implementation_type == integration_test_sub_task_offset:
                ret_dict['Integration_Act_Effort'] = local_mpp_export["Duration"][local_row + integration_test_sub_task_offset]

    ret_dict['State'] = local_mpp_export["State"][local_row]
    ret_dict['UID'] = local_mpp_export["UID"][local_row]

    return ret_dict


def sync_ToBeReviewed(local_mpp_export, local_row):

    implementation_types_list = [
        requirements_review_sub_task_offset,
        architecture_review_sub_task_offset,
        design_review_sub_task_offset,
        implementation_review_sub_task_offset,
        unit_test_review_sub_task_offset,
        integration_test_review_sub_task_offset
        ]

    task_token = ' - Review'

    ret_dict = {}
    est_effort_total = 0
    current_assigned_user_for_review_idx = None

    for implementation_type in implementation_types_list:
       est_effort_total += int(local_mpp_export["Duration"][local_row + implementation_types_list[implementation_types_list.index(implementation_type)]])
       if str(int(local_mpp_export['% Complete'][local_row + implementation_type] * 100)) + "%" != "100%" and current_assigned_user_for_review_idx == None:
           current_assigned_user_for_review_idx = implementation_type

    ret_dict['State'] = local_mpp_export["State"][local_row]
    ret_dict['UID'] = local_mpp_export["UID"][local_row]
    ret_dict['Resource Names' + task_token] = local_mpp_export["Resource Names"][local_row + current_assigned_user_for_review_idx]
    ret_dict['Duration Est' + task_token] = est_effort_total
    ret_dict['Finish' + task_token] = local_mpp_export["Finish"][local_row + analysis_sub_task_offset]

    return ret_dict

def sync_Reviewed(local_mpp_export, local_row):

    implementation_types_list = [
        requirements_review_sub_task_offset,
        architecture_review_sub_task_offset,
        design_review_sub_task_offset,
        implementation_review_sub_task_offset,
        unit_test_review_sub_task_offset,
        integration_test_review_sub_task_offset
        ]

    task_token = ' - Review'

    ret_dict = {}
    est_effort_total = 0
    current_assigned_user_for_review_idx = None

    for implementation_type in implementation_types_list:
       if str(int(local_mpp_export['% Complete'][local_row + implementation_type] * 100)) + "%" == "100%" and \
               str(int(local_mpp_export['% Complete'][local_row + implementation_type])) != '0':
           est_effort_total += int(local_mpp_export["Duration"][local_row + implementation_types_list[implementation_types_list.index(implementation_type)]])
           if current_assigned_user_for_review_idx == None:
               current_assigned_user_for_review_idx = implementation_type

    ret_dict['State'] = local_mpp_export["State"][local_row]
    ret_dict['UID'] = local_mpp_export["UID"][local_row]
    ret_dict['Resource Names' + task_token] = local_mpp_export["Resource Names"][local_row + current_assigned_user_for_review_idx]
    ret_dict['Duration Act' + task_token] = est_effort_total

    return ret_dict

def sync_ToBeVerified(local_mpp_export, local_row):
    # ToDo: Allocate to SWVTL or if WI to the person who created it
    # ToDo: Allocate to M3 Date
    return "N/A"

def sync_Verified(local_mpp_export, local_row):
    return "N/A"

def sync_Closed(local_mpp_export, local_row):
    return "N/A"

