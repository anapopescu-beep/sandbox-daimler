doors_column_configuration = {
    'ID': [''],
    '_Type': ['Heading', 'Information', 'Functional Requirement', 'Non-functional Requirement', 'Functional_Requirement', 'Non-functional_Requirement', 'Safety Requirement'],
    '_ReqStatus': ['Approved', 'InReview_by_Design_Team', 'InReview_by_Test_Team', 'Init', 'To_be_clarified', 'Obsolete', 'NA'],
    '_ProjectApplicableJLR': ['Applicable', 'N/A'],
    '_TargetJLR': ['P10', 'P20', 'P30'],
    'AEEC_TestScope_PP4G': ['SW Global Integration Tests', 'SW Module Tests', 'SW Verification Tests', 'Reviews'],
    '_ImpactedDiscipline': ['SW', 'System'],
    '_CoveredByDownstreamJLR': ['DES_TF_', 'ARCH_SW_'],
    '_CoversUpstreamJLR': ['JLR_FRD_'],
	'_ImplementedJLR': ['True']
}

doors_filter_configuration = {
    # 'Comments_Status': {
    #     'Columns': ['_Comment'],
    #     'Values': [None]
    # },

	# '__Number_of_requierments': {
    #     'Columns': ['_Type', '_ReqStatus', '_ProjectApplicableJLR', '_TargetJLR'],
    #     'Values': [['Functional Requirement', 'Non-functional Requirement', 'Functional_Requirement', 'Non-functiona_Requirement'], 'Approved', 'Applicable', ['P10', 'P20', 'P30']]
    # },
	# '__Number_of_implemented_requierments': {
    #     'Columns': ['_Type', '_ReqStatus', '_ImplementedJLR', '_ProjectApplicableJLR', '_TargetJLR'],
    #     'Values': [['Functional Requirement', 'Non-functional Requirement', 'Functional_Requirement', 'Non-functiona_Requirement'], 'Approved', 'True', 'Applicable', ['P10', 'P20', 'P30']]
    # },
	#
	# '__Number_of_requierments_tested_in_SWD_Reviews_scope': {
    #     'Columns': ['_Type', '_ReqStatus', '_ImpactedDiscipline', '_ImplementedJLR', '_ProjectApplicableJLR', '_TargetJLR', 'AEEC_TestScope_PP4G'],
    #     'Values': [['Functional Requirement', 'Non-functional Requirement', 'Functional_Requirement', 'Non-functiona_Requirement'], 'Approved', 'SW', 'True', 'Applicable', ['P10', 'P20', 'P30'], 'Reviews']
    # },
	#
	# '__Number_of_requierments_tested_by_SWD_Reviews_scope': {
    #     'Columns': ['_Type', '_ReqStatus', '_ImpactedDiscipline', '_ImplementedJLR', '_ProjectApplicableJLR', '_TargetJLR', 'AEEC_TestScope_PP4G', '_MLA_SWDevelopment_Review_TestID'],
    #     'Values': [['Functional Requirement', 'Non-functional Requirement', 'Functional_Requirement', 'Non-functiona_Requirement'], 'Approved', 'SW', 'True', 'Applicable', ['P10', 'P20', 'P30'], 'Reviews', 'Peer Review Workbook']
    # },
	#
	# '__Number_of_requierments_tested_by_SWD_Reviews_scope_PASSED': {
    #     'Columns': ['_Type', '_ReqStatus', '_ImplementedJLR', '_ProjectApplicableJLR', '_TargetJLR', 'AEEC_TestScope_PP4G', '_MLA_SWDevelopment_Review_TestID', '_MLA_SWDevelopment_Review_TestResult'],
    #     'Values': [['Functional Requirement', 'Non-functional Requirement', 'Functional_Requirement', 'Non-functiona_Requirement'], 'Approved', 'True', 'Applicable', ['P10', 'P20', 'P30'], 'Reviews', 'Peer Review Workbook', 'PASSED']
    # },
	#
	# '__Number_of_requierments_tested_by_SWD_Reviews_scope_FAILED': {
    #     'Columns': ['_Type', '_ReqStatus', '_ImplementedJLR', '_ProjectApplicableJLR', '_TargetJLR', 'AEEC_TestScope_PP4G', '_MLA_SWDevelopment_Review_TestID', '_MLA_SWDevelopment_Review_TestResult', '_MLA_SWDevelopment_Review_TestResult'],
    #     'Values': [['Functional Requirement', 'Non-functional Requirement', 'Functional_Requirement', 'Non-functiona_Requirement'], 'Approved', 'True', 'Applicable', ['P10', 'P20', 'P30'], 'Reviews', 'Peer Review Workbook', '!PASSED', '!N/A']
    # },
	#
	# '__Number_of_requierments_tested_by_SWD_Reviews_scope_NA': {
    #     'Columns': ['_Type', '_ReqStatus', '_ImplementedJLR', '_ProjectApplicableJLR', '_TargetJLR', 'AEEC_TestScope_PP4G', '_MLA_SWDevelopment_Review_TestResult'],
    #     'Values': [['Functional Requirement', 'Non-functional Requirement', 'Functional_Requirement', 'Non-functiona_Requirement'], 'Approved', 'True', 'Applicable', ['P10', 'P20', 'P30'], 'Reviews', 'N/A']
    # },
	#
	# '__Number_of_requierments_tested_in_SWD_UnitTest_scope': {
    #     'Columns': ['_Type', '_ReqStatus', '_ImpactedDiscipline', '_ImplementedJLR', '_ProjectApplicableJLR', '_TargetJLR', 'AEEC_TestScope_PP4G'],
    #     'Values': [['Functional Requirement', 'Non-functional Requirement', 'Functional_Requirement', 'Non-functiona_Requirement'], 'Approved', 'SW', 'True', 'Applicable', ['P10', 'P20', 'P30'], 'SW Module Tests']
    # },
	#
	# '__Number_of_requierments_tested_by_SWD_UnitTest_scope': {
    #     'Columns': ['_Type', '_ReqStatus', '_ImplementedJLR', '_ProjectApplicableJLR', '_TargetJLR', 'AEEC_TestScope_PP4G', '_MLA_SWDevelopment_ModuleTest_TestID'],
    #     'Values': [['Functional Requirement', 'Non-functional Requirement', 'Functional_Requirement', 'Non-functiona_Requirement'], 'Approved', 'True', 'Applicable', ['P10', 'P20', 'P30'], 'SW Module Tests', 'UNIT_TST']
    # },
	#
	# '__Number_of_requierments_tested_by_SWD_UnitTest_scope_PASSED': {
    #     'Columns': ['_Type', '_ReqStatus', '_ImplementedJLR', '_ProjectApplicableJLR', '_TargetJLR', 'AEEC_TestScope_PP4G', '_MLA_SWDevelopment_ModuleTest_TestID', '_MLA_SWDevelopment_ModuleTest_TestResult'],
    #     'Values': [['Functional Requirement', 'Non-functional Requirement', 'Functional_Requirement', 'Non-functiona_Requirement'], 'Approved', 'True', 'Applicable', ['P10', 'P20', 'P30'], 'SW Module Tests', 'UNIT_TST', 'PASSED']
    # },
	#
	# '__Number_of_requierments_tested_by_SWD_UnitTest_scope_FAILED': {
    #     'Columns': ['_Type', '_ReqStatus', '_ImplementedJLR', '_ProjectApplicableJLR', '_TargetJLR', 'AEEC_TestScope_PP4G', '_MLA_SWDevelopment_ModuleTest_TestID', '_MLA_SWDevelopment_ModuleTest_TestResult', '_MLA_SWDevelopment_ModuleTest_TestResult'],
    #     'Values': [['Functional Requirement', 'Non-functional Requirement', 'Functional_Requirement', 'Non-functiona_Requirement'], 'Approved', 'True', 'Applicable', ['P10', 'P20', 'P30'], 'SW Module Tests', 'UNIT_TST', '!PASSED', '!N/A']
    # },
	#
	# '__Number_of_requierments_tested_by_SWD_UnitTest_scope_NA': {
    #     'Columns': ['_Type', '_ReqStatus', '_ImplementedJLR', '_ProjectApplicableJLR', '_TargetJLR', 'AEEC_TestScope_PP4G', '_MLA_SWDevelopment_ModuleTest_TestResult'],
    #     'Values': [['Functional Requirement', 'Non-functional Requirement', 'Functional_Requirement', 'Non-functiona_Requirement'], 'Approved', 'True', 'Applicable', ['P10', 'P20', 'P30'], 'SW Module Tests', 'N/A']
    # },
    #
	# '__Number_of_requierments_tested_in_SWD_IntegrationTest_scope': {
    #     'Columns': ['_Type', '_ReqStatus', '_ImpactedDiscipline', '_ImplementedJLR', '_ProjectApplicableJLR', '_TargetJLR', 'AEEC_TestScope_PP4G'],
    #     'Values': [['Functional Requirement', 'Non-functional Requirement', 'Functional_Requirement', 'Non-functiona_Requirement'], 'Approved', 'SW', 'True', 'Applicable', ['P10', 'P20', 'P30'], 'SW Global Integration Tests']
    # },
	#
	# '__Number_of_requierments_tested_by_SWD_IntegrationTest_scope': {
    #     'Columns': ['_Type', '_ReqStatus', '_ImplementedJLR', '_ProjectApplicableJLR', '_TargetJLR', 'AEEC_TestScope_PP4G', '_MLA_SWDevelopment_IntegrationTest_TestID'],
    #     'Values': [['Functional Requirement', 'Non-functional Requirement', 'Functional_Requirement', 'Non-functiona_Requirement'], 'Approved', 'True', 'Applicable', ['P10', 'P20', 'P30'], 'SW Global Integration Tests', 'INT_GLO']
    # },
	#
	# '__Number_of_requierments_tested_by_SWD_IntegrationTest_scope_PASSED': {
    #     'Columns': ['_Type', '_ReqStatus', '_ImplementedJLR', '_ProjectApplicableJLR', '_TargetJLR', 'AEEC_TestScope_PP4G', '_MLA_SWDevelopment_IntegrationTest_TestID', '_MLA_SWDevelopment_IntegrationTest_TestResult'],
    #     'Values': [['Functional Requirement', 'Non-functional Requirement', 'Functional_Requirement', 'Non-functiona_Requirement'], 'Approved', 'True', 'Applicable', ['P10', 'P20', 'P30'], 'SW Global Integration Tests', 'INT_GLO', 'PASSED']
    # },
	#
	# '__Number_of_requierments_tested_by_SWD_IntegrationTest_scope_FAILED': {
    #     'Columns': ['_Type', '_ReqStatus', '_ImplementedJLR', '_ProjectApplicableJLR', '_TargetJLR', 'AEEC_TestScope_PP4G', '_MLA_SWDevelopment_IntegrationTest_TestID', '_MLA_SWDevelopment_IntegrationTest_TestResult', '_MLA_SWDevelopment_IntegrationTest_TestResult'],
    #     'Values': [['Functional Requirement', 'Non-functional Requirement', 'Functional_Requirement', 'Non-functiona_Requirement'], 'Approved', 'True', 'Applicable', ['P10', 'P20', 'P30'], 'SW Global Integration Tests', 'INT_GLO', '!PASSED', '!N/A']
    # },
	#
	# '__Number_of_requierments_tested_by_SWD_IntegrationTest_scope_NA': {
    #     'Columns': ['_Type', '_ReqStatus', '_ImplementedJLR', '_ProjectApplicableJLR', '_TargetJLR', 'AEEC_TestScope_PP4G', '_MLA_SWDevelopment_IntegrationTest_TestResult'],
    #     'Values': [['Functional Requirement', 'Non-functional Requirement', 'Functional_Requirement', 'Non-functiona_Requirement'], 'Approved', 'True', 'Applicable', ['P10', 'P20', 'P30'], 'SW Global Integration Tests', 'N/A']
    # },
	
	'__Number_of_requierments_tested_in_SWV_scope': {
        'Columns': ['_Type', '_ReqStatus', '_ImplementedJLR', '_ProjectApplicableJLR', '_TargetJLR', 'AEEC_TestScope_PP4G'],
        'Values': [['Functional Requirement', 'Non-functional Requirement', 'Functional_Requirement', 'Non-functiona_Requirement'], 'Approved', 'True', 'Applicable', ['P10', 'P20', 'P30'], 'SW Verification Tests']
    },
	'__Number_of_requierments_tested_by_SWV': {
        'Columns': ['_Type', '_ReqStatus', '_ImplementedJLR', '_ProjectApplicableJLR', '_TargetJLR', 'AEEC_TestScope_PP4G', '_MLA_Verification_TestID'],
        'Values': [['Functional Requirement', 'Non-functional Requirement', 'Functional_Requirement', 'Non-functiona_Requirement'], 'Approved', 'True', 'Applicable', ['P10', 'P20', 'P30'], 'SW Verification Tests', "!None"]
    },
	
	'__Number_of_requierments_tested_by_SWV_Passed': {
        'Columns': ['_Type', '_ReqStatus', '_ImplementedJLR', '_ProjectApplicableJLR', '_TargetJLR', 'AEEC_TestScope_PP4G', '_MLA_Verification_TestID', '_MLA_Verification_TestResult'],
        'Values': [['Functional Requirement', 'Non-functional Requirement', 'Functional_Requirement', 'Non-functiona_Requirement'], 'Approved', 'True', 'Applicable', ['P10', 'P20', 'P30'], 'SW Verification Tests', "!None", 'PASSED']
    },
	
	'__Number_of_requierments_tested_by_SWV_Failed': {
        'Columns': ['_Type', '_ReqStatus', '_ImplementedJLR', '_ProjectApplicableJLR', '_TargetJLR', 'AEEC_TestScope_PP4G', '_MLA_Verification_TestID', '_MLA_Verification_TestResult'],
        'Values': [['Functional Requirement', 'Non-functional Requirement', 'Functional_Requirement', 'Non-functiona_Requirement'], 'Approved', 'True', 'Applicable', ['P10', 'P20', 'P30'], 'SW Verification Tests', "!None", '!PASSED']
    },
	'__Number_of_not_tested_requierments': {
        'Columns': ['_Type', '_ReqStatus', '_ImplementedJLR', '_ProjectApplicableJLR', '_TargetJLR', 'AEEC_TestScope_PP4G'],
        'Values': [['Functional Requirement', 'Non-functional Requirement', 'Functional_Requirement', 'Non-functiona_Requirement'], 'Approved', 'True', 'Applicable', ['P10', 'P20', 'P30'], None]
    },
	
	'__QACheck_TargetJLR': {
        'Columns': ['_Type', '_ReqStatus', '_ImplementedJLR', '_ProjectApplicableJLR', '_TargetJLR'],
        'Values': [['Functional Requirement', 'Non-functional Requirement', 'Functional_Requirement', 'Non-functiona_Requirement'], 'Approved', 'True', 'Applicable', None]
    },
	'__QACheck_ImplementedJLR': {
        'Columns': ['_Type', '_ReqStatus', '_ImplementedJLR', '_ProjectApplicableJLR', '_TargetJLR'],
        'Values': [['Functional Requirement', 'Non-functional Requirement', 'Functional_Requirement', 'Non-functiona_Requirement'], 'Approved', None, 'Applicable', ['P10', 'P20', 'P30']]
    },
	
	'__QACheck_ReqStatus_ToBeClarified': {
        'Columns': ['_Type', '_ReqStatus', '_ImplementedJLR', '_ProjectApplicableJLR', '_TargetJLR'],
        'Values': [['Functional Requirement', 'Non-functional Requirement', 'Functional_Requirement', 'Non-functiona_Requirement'], 'To_be_clarified', 'True', 'Applicable', ['P10', 'P20', 'P30']]
    },
	'__QACheck_ReqStatus_InReview_by_Design_Team': {
        'Columns': ['_Type', '_ReqStatus', '_ImplementedJLR', '_ProjectApplicableJLR', '_TargetJLR'],
        'Values': [['Functional Requirement', 'Non-functional Requirement', 'Functional_Requirement', 'Non-functiona_Requirement'], 'InReview_by_Design_Team', 'True', 'Applicable', ['P10', 'P20', 'P30']]
    },
	'__QACheck_ReqStatus_InReview_by_Test_Team': {
		'Columns': ['_Type', '_ReqStatus', '_ImplementedJLR', '_ProjectApplicableJLR', '_TargetJLR'],
        'Values': [['Functional Requirement', 'Non-functional Requirement', 'Functional_Requirement', 'Non-functiona_Requirement'], 'InReview_by_Test_Team', 'True', 'Applicable', ['P10', 'P20', 'P30']]
    },
	
	'__QACheck_ReqStatus_InReview_by_Test_Team_Out_Of_Scope': {
		'Columns': ['_Type', '_ReqStatus', '_ImplementedJLR', '_ProjectApplicableJLR', '_TargetJLR', 'AEEC_TestScope_PP4G', 'AEEC_TestScope_PP4G'],
        'Values': [['Functional Requirement', 'Non-functional Requirement', 'Functional_Requirement', 'Non-functiona_Requirement'], 'InReview_by_Test_Team', 'True', 'Applicable', ['P10', 'P20', 'P30'], ['SW Global Integration Tests', 'SW Module Tests', 'Reviews'], '!SW Verification Tests']
    },
	
	'__QACheck_ReqStatus_ImpactedDiscipline': {
        'Columns': ['_Type', '_ReqStatus', '_ImplementedJLR', '_ProjectApplicableJLR', '_TargetJLR', '_ImpactedDiscipline'],
        'Values': [['Functional Requirement', 'Non-functional Requirement', 'Functional_Requirement', 'Non-functiona_Requirement'], 'Approved', 'True', 'Applicable', ['P10', 'P20', 'P30'], None]
    },
}

chart_configuration = None

#chart_configuration = {
#    'Chart_Configuration_1': {
#        'Categories': '=Summary!A2:A3',
#        'Values': '=Summary!B2:B3',
#        'Location': 'A44'
#    },
#}