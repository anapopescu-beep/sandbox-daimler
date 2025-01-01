@echo off
rem **********************************************************************************************************************
rem    FILE DESCRIPTION
rem  --------------------------------------------------------------------------------------------------------------------
rem    \file
rem    \brief        Prepare updater script
rem  --------------------------------------------------------------------------------------------------------------------
rem  COPYRIGHT
rem  --------------------------------------------------------------------------------------------------------------------
rem    \par Copyright
rem    \verbatim
rem    Copyright (c) 2016 by Vector Informatik GmbH.                                                 All rights reserved.
rem 
rem                This software is copyright protected and proprietary to Vector Informatik GmbH.
rem                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
rem                All other rights remain with Vector Informatik GmbH.
rem    \endverbatim
rem
rem  -------------------------------------------------------------------------------------------------------------------
rem  EXAMPLE CODE ONLY
rem  -------------------------------------------------------------------------------------------------------------------
rem  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW
rem  configuration. The Example Code has not passed any quality control measures and may be incomplete. The
rem  Example Code is neither intended nor qualified for use in series production. The Example Code as well
rem  as any of its modifications and/or implementations must be tested with diligent care and must comply
rem  with all quality requirements which are necessary according to the state of the art before their use.
rem
rem **********************************************************************************************************************

rem **********************************************************************************************************************
rem  AUTHOR IDENTITY
rem  --------------------------------------------------------------------------------------------------------------------
rem  Name                          Initials      Company
rem  --------------------------------------------------------------------------------------------------------------------
rem  Marco Riedl                   Rie           Vector Informatik GmbH
rem  --------------------------------------------------------------------------------------------------------------------
rem  REVISION HISTORY
rem  --------------------------------------------------------------------------------------------------------------------
rem  Version   Date        Author  Change Id          Description
rem  --------------------------------------------------------------------------------------------------------------------
rem  01.00.00  2016-08-18  Rie     -                  First implementation
rem **********************************************************************************************************************

set APPL_PATH_SRC=%~dp0\..\..\..\..\Components\FBLBM_UPDATER\Autoliv\FblUsr\Implementation\src
set APPL_PATH_INC=%~dp0\..\..\..\..\Components\FBLBM_UPDATER\Autoliv\FblUsr\Implementation\inc
set FBL_HEX_LOCATION=%~dp0\..\..\..\Build_Env\Workspace\Outputs\fbl\Out\fbl.hex
set NEW_FBL_DIR=%~dp0\..\..\..\Build_Env\Workspace\Outputs\fblbm_upd\Out

echo Preparing new FBL version for the Updater

echo Removing old FBL .c/.h files
if exist %APPL_PATH_SRC%\NewFbl.c del %APPL_PATH_SRC%\NewFbl.c
if exist %APPL_PATH_INC%\NewFbl.h del %APPL_PATH_INC%\NewFbl.h

rem Copy FBL to NEW_FBL_DIR
if exist %NEW_FBL_DIR%\NewFbl.hex del %NEW_FBL_DIR%\NewFbl.hex
xcopy %FBL_HEX_LOCATION% %NEW_FBL_DIR%\NewFbl.hex* > nul

set argument=NewFbl.hex

rem *****************************************************************************
rem * Prepare FBL update
rem *****************************************************************************

set local_dir=%~d0%~p0

rem *** Configuration section for files and directories *************************

rem Hexview executable
set hexview_exe=S:\Tools\HexView\Installation\HexView-1.13.01\hexview.exe

rem *** End of configuration section ********************************************

rem *** error checking **********************************************************

if not exist %hexview_exe% goto error

rem *** End of error checking ***************************************************

rem Align data to the flash segment size
%hexview_exe% %NEW_FBL_DIR%\%argument% /AD:0x20 /AL:0x20 /XI /s -o %NEW_FBL_DIR%\%argument%

rem Generate ini-file for HexView
@echo [C_EXPORT]            > %NEW_FBL_DIR%\%argument%.ini
@echo Decryptvalue=0       >> %NEW_FBL_DIR%\%argument%.ini
@echo Prefix=FblUpdate     >> %NEW_FBL_DIR%\%argument%.ini
@echo Decryption=0         >> %NEW_FBL_DIR%\%argument%.ini
@echo WordSize=0           >> %NEW_FBL_DIR%\%argument%.ini
@echo WordType=-1          >> %NEW_FBL_DIR%\%argument%.ini
@echo StrictAnsiC=0        >> %NEW_FBL_DIR%\%argument%.ini
@echo CreateFAR=0          >> %NEW_FBL_DIR%\%argument%.ini
@echo CreateMemmap=1       >> %NEW_FBL_DIR%\%argument%.ini
@echo CreateStruct=1       >> %NEW_FBL_DIR%\%argument%.ini
@echo MaxBlockSize=        >> %NEW_FBL_DIR%\%argument%.ini
@echo Metrowerks=0         >> %NEW_FBL_DIR%\%argument%.ini

echo Creating C-File for new Bootloader before generating the FBL UPDATER application.
rem Start Hexview to convert new FBL into C-Array.
%hexview_exe% %NEW_FBL_DIR%\%argument%%~x1 -s -p=%NEW_FBL_DIR%\%argument%.ini -e:%NEW_FBL_DIR%\%argument%_err.log -xc

echo Moving prepared files to the source directory of the FBL UPDATER
move %NEW_FBL_DIR%\NewFbl.c %APPL_PATH_SRC%\NewFbl.c > nul
move %NEW_FBL_DIR%\NewFbl.h %APPL_PATH_INC%\NewFbl.h > nul

rem Remove temporary files needed for this step
del %NEW_FBL_DIR%\%argument%.ini
del %NEW_FBL_DIR%\%argument%

if not exist %APPL_PATH_SRC%\NewFbl.c (
  echo Creating NewFbl.c failed or invalid selection. aborting.
  goto End
)

Echo New FBL successfully prepared

goto end

:usage
echo "Please call with a hex file as parameter."
pause
goto end

:error
echo "Please adapt hexview parameter in FblUpd_Prepare.bat."
pause
goto end

:end

