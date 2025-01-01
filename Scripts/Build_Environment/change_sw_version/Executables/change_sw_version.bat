@ECHO OFF
FOR %%A IN ("%~dp0.") DO SET parent_folder=%%~dpA

set file_path=s:\Tools\Build_Env\Workspace\Build\Makefile\Makefile.wers.mk
set new_swversion=NEW_SW_VERSION
set old_swversion=ER01472H.P25

change_sw_version.exe -f="%file_path%" -s="%new_swversion%" -o="%old_swversion%"