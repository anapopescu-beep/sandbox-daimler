@ECHO OFF
FOR %%A IN ("%~dp0.") DO SET parent_folder=%%~dpA

set input_path=s:\Tests\Tests_Qualification
set template_path=%parent_folder%\Templates\Audi_Tranche_6_Qualification_Tests_SummaryReport_P25_Template.docx
set output_path=%parent_folder%\Outputs\Audi_Tranche_6_Qualification_Tests_Summary_Report.docx

Qualification_test_summary_report.exe -i="%input_path%" -l="%template_path%" -x="%path_to_xml_files_folder%" -m="%path_to_xlsm_peer_review_folder%" -o="%output_path%"