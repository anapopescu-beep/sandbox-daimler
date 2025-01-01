@ECHO OFF
FOR %%A IN ("%~dp0.") DO SET parent_folder=%%~dpA


set path_to_ra_files=S:\Tests\Tests_Integration\Automatic_Tests\Test_Reports
set template_folder=%parent_folder%\Templates\Audi_Tranche_6_Integration_Tests_Summary_Report_template.docx
set output_folder=%parent_folder%\Outputs\Audi_Tranche_6_Integration_Tests_Summary_Report.docx

Integration_test_summary_report.exe -i="%path_to_ra_files%" -l="%template_folder%" -o="%output_folder%"