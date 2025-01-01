@ECHO OFF
FOR %%A IN ("%~dp0.") DO SET parent_folder=%%~dpA


set hostname=ALVA-MKS03
set username=Jenkins01
set password=jnk01
set query=ToBeVerifed_for_DAIMLER_MMA
set output_path=%parent_folder%\Outputs
set template_path=%parent_folder%\Templates\IssueReport_Template.xlsx

ptc_issue_report.exe -n="%hostname%" -u="%username%" -p="%password%" -q="%query%" -o="%output_path%" -t="%template_path%"