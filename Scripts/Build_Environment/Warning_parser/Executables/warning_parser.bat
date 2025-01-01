@ECHO OFF
FOR %%A IN ("%~dp0.") DO SET parent_folder=%%~dpA


set output_folder=%parent_folder%\Outputs


warning_parser.exe -w=S:\Tools\Build_Env\Workspace\Outputs\app\Err\ -s=S:\Components\Autoliv\*\ -l=-1 -b=1 -d=13.12.2021 -o="%output_folder%"
