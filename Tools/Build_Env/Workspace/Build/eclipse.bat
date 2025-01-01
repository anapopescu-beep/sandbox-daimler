@echo off
set "arg1=%1"
set "arg2=%2"

call env_cfg.bat

set ECLIPSE_EXE=%ECLIPSE_INSTALLATION_DIR%\eclipse.exe

if "%arg1%"=="import_workspace" (
set ECLIPSE_PROJECT=%ECLIPSE_PROJECT_ROOT%\%arg2%
)

if "%arg1%"=="import_workspace" (
	if not exist %ECLIPSE_WORKSPACE% mkdir %ECLIPSE_WORKSPACE%
   %ECLIPSE_EXE% -nosplash -application com.seeq.eclipse.importprojects.headlessimport -data "%ECLIPSE_WORKSPACE%" -import "%ECLIPSE_PROJECT%"
	goto End
)

    
if "%arg1%"=="post_import_workspace" (
xcopy /E /Y /Q %~dp0\..\..\..\..\Tools\Eclipse\Config\.settings\*.* %ECLIPSE_WORKSPACE%\.metadata\.plugins\org.eclipse.core.runtime\.settings\
xcopy /E /Y /Q %~dp0\..\..\..\..\Tools\Eclipse\Config\.launches\*.* %ECLIPSE_WORKSPACE%\.metadata\.plugins\org.eclipse.debug.core\.launches\
)
	
start %ECLIPSE_EXE% -refresh -data %ECLIPSE_WORKSPACE%
goto End

:End