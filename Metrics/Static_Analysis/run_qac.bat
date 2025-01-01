@echo off

set "COMP=%1"
set "PYTHON_PATH=c:\Prog\python-3.7.1\"
if "%COMP%"=="" (
	%PYTHON_PATH%\python.exe PP4G_QAC_Analysis.py
) else (
	%PYTHON_PATH%\python.exe PP4G_QAC_Analysis.py -c=%1
)