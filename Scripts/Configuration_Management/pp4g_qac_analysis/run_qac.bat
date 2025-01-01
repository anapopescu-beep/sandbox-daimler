@echo off

set "COMP=%1"

where python
if ERRORLEVEL 1 (
    echo python is missing from PATH. Setting default to: c:\Prog\python-3.7.1\
    set "PYTHON_PATH=c:\Prog\python-3.7.1\"
)  else (
    set "PYTHON_PATH="
)

if "%COMP%"=="" (
	%PYTHON_PATH%python.exe PP4G_QAC_Analysis.py
) else (
	%PYTHON_PATH%python.exe PP4G_QAC_Analysis.py -c=%1
)  