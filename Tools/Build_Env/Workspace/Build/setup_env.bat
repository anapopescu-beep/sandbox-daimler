@echo off

call env_cfg.bat

cd %BUILD_PATH%

set INIT_TYPE=%1
set APP_VARIANT=%2

rem *****************************************************************************
rem * DO NOT EDIT ANYTHING BELOW THIS
rem *****************************************************************************

rem *****************************************************************************
rem * Initial installation of python package
rem *****************************************************************************
if not "%INIT_TYPE%"=="fast_build" (
   if exist %PYTHON_INSTALLATION_DIR% rmdir /q /s %PYTHON_INSTALLATION_DIR%
   %CYGWIN_DIR%\bin\unzip.exe -u -q %PYTHON_ZIP% -d %SW_DEV_TOOLS_DIR% 
   %PYTHON_INSTALLATION_DIR%\python.exe -m pip install --trusted-host pypi.org --trusted-host files.pythonhosted.org --upgrade --force-reinstall pip -q 
   if %ERRORLEVEL%==1 (
      echo Retry pip installation with proxy
      %PYTHON_INSTALLATION_DIR%\python.exe -m pip install --trusted-host pypi.org --trusted-host files.pythonhosted.org --upgrade --force-reinstall pip -q --proxy="ALVA-SWG01.alv.autoliv.int:3128"
   )
   %PYTHON_SCRIPTS_DIR%\pip.exe config set global.cert "%PYTHON_INSTALLATION_DIR%\certs\ca-bundle.crt"
)

rem *****************************************************************************
rem * Set TMP dir
rem *****************************************************************************

set TEMP=%~dp0\Makefile\tmp
set TMP=%~dp0\Makefile\tmp
set TMPDIR=%TMP:\=/%

if not exist %TEMP% mkdir %TEMP%

if not exist %CYGWIN_DIR%\tmp mkdir %CYGWIN_DIR%\tmp

rem *****************************************************************************
rem * Filter paths
rem *****************************************************************************
if not "%INIT_TYPE%"=="fast_build" (
   %PYTHON_SCRIPTS_DIR%\pip.exe uninstall -y build_assist -q -q 

   if %ERRORLEVEL%==1 (
      echo Retry pip installation with proxy
      %PYTHON_SCRIPTS_DIR%\pip.exe uninstall -y build_assist -q -q --proxy="ALVA-SWG01.alv.autoliv.int:3128"
   )

   %PYTHON_SCRIPTS_DIR%\pip.exe install %BUILD_ENV_WHL% -q -q 

   if %ERRORLEVEL%==1 (
      echo Retry pip installation with proxy
      %PYTHON_SCRIPTS_DIR%\pip.exe install %BUILD_ENV_WHL% -q -q --proxy="ALVA-SWG01.alv.autoliv.int:3128"
   )
) 

%PYTHON_SCRIPTS_DIR%\path_cleaner.exe -p="%PATH%" >> %TEMP%\path_cleaner.out
set /p PATH=<%TEMP%\path_cleaner.out
del %TEMP%\path_cleaner.out

rem *****************************************************************************
rem * Set project paths
rem *****************************************************************************

set PATH=%CYGWIN_DIR%\bin;%PYTHON_INSTALLATION_DIR%;%PYTHON_SCRIPTS_DIR%;%COMPILER_DIR%;%PATH%%

set CYGWIN=nodosfilewarning

rem *****************************************************************************
rem * Install zip_installer
rem *****************************************************************************
if not "%INIT_TYPE%"=="fast_build" (
   pip uninstall  -y zip_installer -q -q 

   if %ERRORLEVEL%==1 (
      echo Retry pip installation with proxy
      pip uninstall  -y zip_installer -q -q --proxy="ALVA-SWG01.alv.autoliv.int:3128"
   )

   pip install  %ZIP_INSTALLER_WHL% -q -q 

   if %ERRORLEVEL%==1 (
      echo Retry pip installation with proxy
      pip install  %ZIP_INSTALLER_WHL% -q -q --proxy="ALVA-SWG01.alv.autoliv.int:3128"
   )
)

rem *****************************************************************************
rem * Install necessary tools
rem *****************************************************************************
if not "%INIT_TYPE%"=="fast_build" (
if exist %SRECORD_INSTALLATION_DIR%     rmdir  /q /s %SRECORD_INSTALLATION_DIR%
if exist %ECLIPSE_INSTALLATION_DIR%     rmdir  /q /s %ECLIPSE_INSTALLATION_DIR%
if exist %HEXVIEW_INSTALLATION_DIR%     rmdir  /q /s %HEXVIEW_INSTALLATION_DIR%
if exist %VERA_INSTALLATION_DIR%        rmdir  /q /s %VERA_INSTALLATION_DIR%

if exist %ECLIPSE_WORKSPACE%            rmdir  /q /s %ECLIPSE_WORKSPACE%
if exist %ECLIPSE_PROJECT_ROOT%         rmdir  /q /s %ECLIPSE_PROJECT_ROOT%

zip_installer --zip %SRECORD_ZIP% 		--path %SW_DEV_TOOLS_DIR%
zip_installer --zip %ECLIPSE_ZIP% 		--path %SW_DEV_TOOLS_DIR%
zip_installer --zip %HEXVIEW_ZIP% 		--path %SW_DEV_TOOLS_DIR%
zip_installer --zip %TRAFO_ZIP%   		--path %TRAFO_DIR%
zip_installer --zip %VERA_ZIP%    		--path %SW_DEV_TOOLS_DIR%
zip_installer --zip %MSR_SIP_ZIP% 		--path %MSR_SIP_DIR%
zip_installer --zip %FBL_SIP_ZIP% 		--path %FBL_SIP_DIR%
zip_installer --zip %HSM_SIP_ZIP% 		--path %HSM_SIP_DIR%
zip_installer --zip %DAVINCI_DEV_ZIP% 		--path %DAVINCI_DEV_DIR%
zip_installer --zip %TASKING_ZIP% 		--path %TASKING_DIR%
)

rem *****************************************************************************
rem * echo environment variables for eclipse configuration
rem *****************************************************************************
if exist %ECLIPSE_CONFIG_DIR%\env_variables.yaml del %ECLIPSE_CONFIG_DIR%\env_variables.yaml

echo COMPILER_DIR: '%COMPILER_DIR%' >> %ECLIPSE_CONFIG_DIR%\env_variables.yaml 
echo SRECORD_INSTALLATION_DIR: '%SRECORD_INSTALLATION_DIR%' >> %ECLIPSE_CONFIG_DIR%\env_variables.yaml
echo ECLIPSE_INSTALLATION_DIR: '%ECLIPSE_INSTALLATION_DIR%' >> %ECLIPSE_CONFIG_DIR%\env_variables.yaml
echo HEXVIEW_INSTALLATION_DIR: '%HEXVIEW_INSTALLATION_DIR%' >> %ECLIPSE_CONFIG_DIR%\env_variables.yaml
echo PYTHON_INSTALLATION_DIR:  '%PYTHON_INSTALLATION_DIR%' >> %ECLIPSE_CONFIG_DIR%\env_variables.yaml
echo VERA_INSTALLATION_DIR:    '%VERA_INSTALLATION_DIR%' >> %ECLIPSE_CONFIG_DIR%\env_variables.yaml
echo CYGWIN_DIR: '%CYGWIN_DIR%' >> %ECLIPSE_CONFIG_DIR%\env_variables.yaml
echo BUILD_PATH: '%BUILD_PATH%' >> %ECLIPSE_CONFIG_DIR%\env_variables.yaml
echo TMP: '%TMP%' >> %ECLIPSE_CONFIG_DIR%\env_variables.yaml
echo TEMP: '%TEMP%' >> %ECLIPSE_CONFIG_DIR%\env_variables.yaml
echo TMPDIR: '%TMPDIR%' >> %ECLIPSE_CONFIG_DIR%\env_variables.yaml
echo SYSTEMDRIVE: '%SYSTEMDRIVE%' >> %ECLIPSE_CONFIG_DIR%\env_variables.yaml

goto End

:End

if "%INIT_TYPE%"=="global_build" (
make %APP_VARIANT%-clean
make %APP_VARIANT%
)

