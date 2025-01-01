@ECHO OFF
FOR %%A IN ("%~dp0.") DO SET parent_folder=%%~dpA

set input_path_ptc=s:\Scripts\Configuration_Management\ptc_tracker\Executables\Exxxxxxx DAIMLER MMA CM Items Status PTC.csv
set input_path_plm=s:\Scripts\Configuration_Management\plm_tracker\Sources\Exxxxxxx DAIMLER MMA CM Items Status PLM.csv
set input_path_xlsx=%parent_folder%\Inputs\Exxxxxxx DAIMLER MMA - SW Work-Product Follow-up.xlsx

set output_folder=%parent_folder%\Outputs\Exxxxxxx DAIMLER MMA - SW Work-Product Follow-up.xlsx

SysSwPF_generator.exe -i="%input_path_ptc%" -l="%input_path_plm%" -t="%input_path_xlsx%" -o="%output_folder%" 
