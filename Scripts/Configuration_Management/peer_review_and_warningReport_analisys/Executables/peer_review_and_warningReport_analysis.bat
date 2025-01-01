rem @ECHO OFF
rem -----------------------------------------------------------------------------------
rem 		PEER REVIEW AND WARNING_REPORT ANALYSER SCRIPT
REM WRITTEN BY: Ardeleanu Lucian 
rem -----------------------------------------------------------------------------------

rem get here parrent folder name 
FOR %%A IN ("%~dp0.") DO SET parent_folder=%%~dpA


set yaml_config_path="D:\workspace\KPI_Manager\DAIMLER_MMA_Reports\Scripts\Configuration_Management\peer_review_and_warningReport_analisys\Executables"

rem Run script with parameters 
peer_review_and_warningReport_analysis.exe -i="%yaml_config_path%" 