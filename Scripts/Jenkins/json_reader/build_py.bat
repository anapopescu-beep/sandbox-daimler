@echo off

echo Building %1 from %cd%

set "PYTHON_PATH=c:\_devapp\Python66"
set "PYTHON_SCRIPTS_PATH=%PYTHON_PATH%\Scripts"

if not exist "%cd%\py_build" mkdir %cd%\py_build
if not exist "%cd%\py_dist" mkdir %cd%\py_dist

%PYTHON_SCRIPTS_PATH%\pyinstaller.exe %cd%\%1 --onefile --workpath=%cd%\py_build --distpath=%cd%\py_dist --log-level=WARN --runtime-tmpdir=.\tmp

echo Cleaning up %cd%

if exist "%cd%\py_build" rmdir /S /Q %cd%\py_build
if exist "%cd%\__pycache__" rmdir /S /Q %cd%\__pycache__
if exist "%cd%\%~n1.spec" del "%cd%\%~n1.spec"
if exist "%cd%\py_dist\%~n1.exe" (
move /Y %cd%\py_dist\%~n1.exe %cd%\%~n1.exe >nul
rmdir /S /Q "%cd%\py_dist
) else (
rmdir /S /Q "%cd%\py_dist
)