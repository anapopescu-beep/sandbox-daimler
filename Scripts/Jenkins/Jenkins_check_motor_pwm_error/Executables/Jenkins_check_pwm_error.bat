@ECHO OFF
FOR %%A IN ("%~dp0.") DO SET parent_folder=%%~dpA


set input_folder=%parent_folder%\Inputs\Example_of_ts_result.xml
set output_folder=%parent_folder%\Outputs\Generated_text_file_with_error.txt

Jenkins_check_pwm_error.exe -i="%input_folder%" -o="%output_folder%"



