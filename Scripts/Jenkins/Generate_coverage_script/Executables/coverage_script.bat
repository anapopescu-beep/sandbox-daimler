@ECHO OFF
FOR %%A IN ("%~dp0.") DO SET parent_folder=%%~dpA


set output_folder=%parent_folder%\Outputs

coverage_script.exe -i="S:\Architectures\Application\Description\Associated_Documents" -o="%output_folder%"