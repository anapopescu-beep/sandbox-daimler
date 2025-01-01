@ECHO OFF
FOR %%A IN ("%~dp0.") DO SET parent_folder=%%~dpA


set input_path_1=%parent_folder%\Inputs\QAC_Metrics_Report.xlsx
set input_path_2=%parent_folder%\Inputs\QAC_Warning_Report.xlsx
set output_path=%parent_folder%\Outputs\QAC_Metrics_Analysis_Report.docx

QAC_summary_report.exe -i="%input_path_1%" -l="%input_path_2%" -m="%output_path%"
