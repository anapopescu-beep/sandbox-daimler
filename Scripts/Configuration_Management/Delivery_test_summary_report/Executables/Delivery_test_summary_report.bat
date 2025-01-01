@ECHO OFF
FOR %%A IN ("%~dp0.") DO SET parent_folder=%%~dpA


set path_to_ra_files=s:\Tests\Tests_Deliveries\Automatic_Tests\SW Delivery Tests follow-up.xls
set template_folder=%parent_folder%\Templates\Audi_Tranche_6_Delivery_Test_Summary_Report_template.docx
set output_folder=%parent_folder%\Outputs\Audi_Tranche_6_Delivery_Tests_Summary_Report.docx

Delivery_test_summary_report.exe -i="%path_to_ra_files%" -l="%template_folder%" -o="%output_folder%"
