@ECHO OFF
FOR %%A IN ("%~dp0.") DO SET parent_folder=%%~dpA


set input_path=s:\Components\Application\Autoliv
set output_folder=%parent_folder%\Outputs

qac_warning_plotter.exe -i="%input_path%" -o="%output_folder%" -d=26.05.2021 -b=100
