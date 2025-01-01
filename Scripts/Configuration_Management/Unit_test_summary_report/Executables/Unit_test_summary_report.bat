@ECHO OFF
FOR %%A IN ("%~dp0.") DO SET parent_folder=%%~dpA


set template_folder=%parent_folder%\Templates\Audi_Tranche_6_Unit_Tests_Summary_Report_Template.docx
set output_folder=%parent_folder%\Outputs\Audi_Tranche_6_Unit_Tests_Summary_Report.docx

Unit_test_summary_report.exe -i="%template_folder%" -o="%output_folder%"
