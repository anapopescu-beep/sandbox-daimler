@echo off
rem *****************************************************************************
rem * CYGWIN_DIR has to be set to Make_support root directory or to a cygwin dist
rem * There MUSTN'T be any blanks between the '=' sign and the path string
rem * Example: 
rem *     set CYGWIN_DIR=..\..\Make_support
rem *****************************************************************************

set "CYGWIN_DIR=%~dp0\Make_support"
set "BUILD_PATH=%~dp0\Makefile"

rem *****************************************************************************
rem * THREAD has to be set in order to enable or disable parralel execution
rem * of receipes. Leave blank for maximum amount of available threads(fastest).
rem *****************************************************************************
set THREAD=8

set SRECORD_BASE=srecord-1.63-win32
set ECLIPSE_BASE=eclipse-embedcpp-2022-03
set CYCLONE_BASE=cyclone_universal
set HEXVIEW_BASE=HexView-1.13.01
set TRAFO_BASE=Trafo-9.02.015
set PYTHON_BASE=python-3.7.1
set VERA_BASE=vera++
set MSR_SIP_BASE=msr_aurix-vMB-BLuC-1.2.2.0
set FBL_SIP_BASE=fbl_aurix-vMB-BLuC-1.2.1.0
set HSM_SIP_BASE=hsm_aurix-vMB-BLuC-1.2.2.0
set DAVINCI_DEV_BASE=Vector-DaVinci-Developer-4.7-SP2
set ZIP_INSTALLER_BASE=zip_installer-1.0.1-py3-none-any
set BUILD_ENV_BASE=build_assist-2.0.0-py3-none-any
set TASKING_BASE=TASKING_TriCore_v6.3r1p2

set "SW_DEV_TOOLS_DIR=c:\Prog"

set "SRECORD_DIR=%~dp0\..\..\..\srecord\Installation"
set "ECLIPSE_DIR=%~dp0\..\..\..\Eclipse\Installation"
set "ECLIPSE_CONFIG_DIR=%~dp0\..\..\..\Eclipse\Config"
set "HEXVIEW_DIR=%~dp0\..\..\..\HexView\Installation"
set "TRAFO_DIR=%~dp0\..\..\..\DTS_Trafo\Installation"
set "PYTHON_DIR=%~dp0\..\..\..\Python\Installation"
set "VERA_DIR=%~dp0\..\..\..\vera++\Installation"
set "MSR_SIP_DIR=%~dp0\..\..\..\Vector\Installation"
set "FBL_SIP_DIR=%~dp0\..\..\..\Vector\Installation"
set "HSM_SIP_DIR=%~dp0\..\..\..\Vector\Installation"
set "DAVINCI_DEV_DIR=%~dp0\..\..\..\Vector\Installation"
set "BUILD_ENV_DIR=%~dp0\..\..\..\Build_Env\Installation"
set "ZIP_INSTALLER_DIR=%~dp0\..\..\..\ZipInstaller\Installation"
set "FBL_UPDATER_CONFIG_DIR=%~dp0\..\..\..\Vector_configuration\Workspace\fblupdater"
set "FBLBM_UPDATER_CONFIG_DIR=%~dp0\..\..\..\Vector_configuration\Workspace\fblbmupdater"
set "HSM_UPDATER_CONFIG_DIR=%~dp0\..\..\..\Vector_configuration\Workspace\hsmupdater"
set "TASKING_DIR=%~dp0\..\..\..\Tasking\Installation"

set "SRECORD_ZIP=%SRECORD_DIR%\%SRECORD_BASE%.zip"
set "ECLIPSE_ZIP=%ECLIPSE_DIR%\%ECLIPSE_BASE%.zip"
set "HEXVIEW_ZIP=%HEXVIEW_DIR%\%HEXVIEW_BASE%.zip"
set "TRAFO_ZIP=%TRAFO_DIR%\%TRAFO_BASE%.zip"
set "PYTHON_ZIP=%PYTHON_DIR%\%PYTHON_BASE%.zip"
set "VERA_ZIP=%VERA_DIR%\%VERA_BASE%.zip"
set "MSR_SIP_ZIP=%MSR_SIP_DIR%\%MSR_SIP_BASE%.zip"
set "FBL_SIP_ZIP=%FBL_SIP_DIR%\%FBL_SIP_BASE%.zip"
set "HSM_SIP_ZIP=%HSM_SIP_DIR%\%HSM_SIP_BASE%.zip"
set "DAVINCI_DEV_ZIP=%DAVINCI_DEV_DIR%\%DAVINCI_DEV_BASE%.zip"
set "TASKING_ZIP=%TASKING_DIR%\%TASKING_BASE%.zip"
set "ZIP_INSTALLER_WHL=%ZIP_INSTALLER_DIR%\%ZIP_INSTALLER_BASE%.whl"
set "BUILD_ENV_WHL=%BUILD_ENV_DIR%\%BUILD_ENV_BASE%.whl"

set "SRECORD_INSTALLATION_DIR=%SW_DEV_TOOLS_DIR%\%SRECORD_BASE%"
set "ECLIPSE_INSTALLATION_DIR=%SW_DEV_TOOLS_DIR%\%ECLIPSE_BASE%"
set "HEXVIEW_INSTALLATION_DIR=%SW_DEV_TOOLS_DIR%\%HEXVIEW_BASE%"
set "TRAFO_INSTALLATION_DIR=%TRAFO_DIR%\%TRAFO_BASE%"
set "PYTHON_INSTALLATION_DIR=%SW_DEV_TOOLS_DIR%\%PYTHON_BASE%"
set "PYTHON_SCRIPTS_DIR=%SW_DEV_TOOLS_DIR%\%PYTHON_BASE%\Scripts"
set "VERA_INSTALLATION_DIR=%SW_DEV_TOOLS_DIR%\%VERA_BASE%"
set "MSR_SIP_INSTALLATION_DIR=%MSR_SIP_DIR%\%MSR_SIP_BASE%"
set "FBL_SIP_INSTALLATION_DIR=%FBL_SIP_DIR%\%FBL_SIP_BASE%"
set "HSM_SIP_INSTALLATION_DIR=%HSM_SIP_DIR%\%HSM_SIP_BASE%"
set "DAVINCI_DEV_INSTALLATION_DIR=%DAVINCI_DEV_DIR%\%DAVINCI_DEV_BASE%"
set "TASKING_INSTALLATION_DIR=%TASKING_DIR%\%TASKING_BASE%"

set ECLIPSE_WORKSPACE=%~dp0\..\..\..\..\Tools\Eclipse\Workspace\eclipse_workspace
set ECLIPSE_PROJECT_ROOT=%~dp0\..\..\..\..\Tools\Eclipse\Workspace\eclipse_project

rem *****************************************************************************
rem * COMPILER_DIR has to be set to compiler root directory
rem * There MUSTN'T be any blanks between the '=' sign and the path string
rem * Example: 
rem *     set COMPILER_DIR=C:\COSMIC\CXS12Z
rem *****************************************************************************

set COMPILER_DIR=%TASKING_INSTALLATION_DIR%

goto End

:End