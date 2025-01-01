@ECHO OFF
FOR %%A IN ("%~dp0.") DO SET parent_folder=%%~dpA


echo ------------------------------------------------
echo 	RAM ROM ANALYSER RUNTIME
echo Written by Ardeleanu Lucian
echo Assisted by Emilian Gustescu
echo ------------------------------------------------

rem Set relative paths to Release folder 
set input_path_app_map=..\\..\\..\\..\\..\\eCS_Platform_Git\\Release\\Application\\app.map
set input_path_fbl_map=..\\..\\..\\..\\..\\eCS_Platform_Git\\Release\\Bootloader\\fbl.map
set input_path_boot_manager_map=..\\..\\..\\..\\..\\eCS_Platform_Git\\Release\\Bootmanager\\fbm.map
set input_path_project_relative=..\\..\\..\\..\\..\\eCS_Platform_Git

set output_folder=%parent_folder%\Outputs\Ram_Rom_Analisys.xlsx


rem Go to relative path
cd %input_path_project_relative%

rem Get the absolute path from relative path 
set input_path_abs=%cd%

rem Go to back to script folder 
cd %parent_folder%\\Executables

rem Run script 
ram_rom_analyzer.exe -i="%input_path_app_map%" -l="%input_path_fbl_map%" -j="%input_path_boot_manager_map%" -p="%input_path_abs%" -o="%output_folder%" 

pause