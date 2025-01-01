@echo off
rem **********************************************************************************************************************
rem    FILE DESCRIPTION
rem  --------------------------------------------------------------------------------------------------------------------
rem    \file
rem    \brief        Hardware specific generate script
rem  --------------------------------------------------------------------------------------------------------------------
rem  COPYRIGHT
rem  --------------------------------------------------------------------------------------------------------------------
rem    \par Copyright
rem    \verbatim
rem    Copyright (c) 2018 by Vector Informatik GmbH.                                                 All rights reserved.
rem
rem                This software is copyright protected and proprietary to Vector Informatik GmbH.
rem                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
rem                All other rights remain with Vector Informatik GmbH.
rem    \endverbatim
rem
rem **********************************************************************************************************************

rem **********************************************************************************************************************
rem  AUTHOR IDENTITY
rem  --------------------------------------------------------------------------------------------------------------------
rem  Name                          Initials      Company
rem  --------------------------------------------------------------------------------------------------------------------
rem  Sebastian Loos                Shs           Vector Informatik GmbH
rem  --------------------------------------------------------------------------------------------------------------------
rem  REVISION HISTORY
rem  --------------------------------------------------------------------------------------------------------------------
rem  Version   Date        Author  Change Id          Description
rem  --------------------------------------------------------------------------------------------------------------------
rem  01.00.00  2018-10-17  visshs  -                  First implementation
rem  01.01.00  2021-10-08  visrie  -                  Rework based on new delivery structure / usage of ScriptHelper
rem **********************************************************************************************************************

echo.
echo This batch file will generate a valid UCB BMHD entry (with CRC32 checksums)
echo by the use of HEXVIEW.
echo.

rem Current directory
set local_dir=%~d0%~p0
rem Hexview executable
set HEXVIEW=S:\Tools\HexView\Installation\HexView-1.13.01\hexview.exe
rem Overwrite variables in case ScriptHelper is present

set BMI=0xFE00
set BMHDID=0x59B3
set PREFIX=__temp_

set /p STAD=Please enter the expected Startup Addess or press Enter for default (0xA0000000): || set STAD=0xA0000000
echo configured Startup Address STAD=%STAD%

echo this script uses BMI=%BMI%

:: BMHDID
if exist error.txt del error.txt /Q
%HEXVIEW% /FR:0,2 /FP:%BMI% /S /E=error.txt /XI -o %PREFIX%bmhdid.hex
if exist error.txt type error.txt

::BMI
if exist error.txt del error.txt /Q
%HEXVIEW% /FR:0x2,2 /FP:%BMHDID% /S /E=error.txt /XI -o %PREFIX%bmi.hex
if exist error.txt type error.txt

::STAD
if exist error.txt del error.txt /Q
%HEXVIEW% /FR:0x4,4 /FP:%STAD% /S /E=error.txt /XI -o %PREFIX%stad.hex
if exist error.txt type error.txt

:: Swap STAD (Endianess)
if exist error.txt del error.txt /Q
%HEXVIEW% %PREFIX%stad.hex /swaplong /S /E=error.txt /XI -o %PREFIX%stad_swap.hex
if exist error.txt type error.txt

:: Merge BMHDID+BMI+STAD
if exist error.txt del error.txt /Q
%HEXVIEW% /MT:%PREFIX%bmhdid.hex+%PREFIX%bmi.hex+%PREFIX%stad_swap.hex  /S /E=error.txt /XI -o %PREFIX%bmhd.hex
if exist error.txt type error.txt

:: Swap BMHD (Endianess)
if exist error.txt del error.txt /Q
%HEXVIEW% %PREFIX%bmhd.hex /swaplong /S /E=error.txt /XI -o %PREFIX%bmhd_swap.hex
if exist error.txt type error.txt

:: CRC32
if exist error.txt del error.txt /Q
%HEXVIEW% %PREFIX%bmhd_swap.hex /CS9:@append /S /E=error.txt /XI -o %PREFIX%bmhd_swap_crc.hex
if exist error.txt type error.txt

:: Swap BMHD (Endianess)
if exist error.txt del error.txt /Q
%HEXVIEW% %PREFIX%bmhd_swap_crc.hex /swaplong /S /E=error.txt /XI -o %PREFIX%bmhd_swap_crc_swap.hex
if exist error.txt type error.txt

:: Extract CRC
if exist error.txt del error.txt /Q
%HEXVIEW% %PREFIX%bmhd_swap_crc_swap.hex /CR:0,8 /S /E=error.txt /XI -o %PREFIX%crc.hex
if exist error.txt type error.txt

:: Invert CRC
if exist error.txt del error.txt /Q
%HEXVIEW% %PREFIX%bmhd_swap_crc_swap.hex /DP1 /S /E=error.txt /XI -o %PREFIX%crc_invert.hex
if exist error.txt type error.txt

:: Extract CRC
if exist error.txt del error.txt /Q
%HEXVIEW% %PREFIX%crc_invert.hex /CR:0,8 /S /E=error.txt /XI -o %PREFIX%crc_invert_cut.hex
if exist error.txt type error.txt

:: CONFIRMATION=UNLOCKED
if exist error.txt del error.txt /Q
%HEXVIEW% /FR:0x1F0,4 /FP:34122143 /S /E=error.txt /XI -o %PREFIX%confirmation.hex
if exist error.txt type error.txt

:: Merge BMHDID+BMI+STAD
if exist error.txt del error.txt /Q
%HEXVIEW% /MT:%PREFIX%bmhd_swap_crc_swap.hex+%PREFIX%crc_invert_cut.hex;4+%PREFIX%confirmation.hex  /S /E=error.txt /XI -o %PREFIX%bmhd_merged.hex
if exist error.txt type error.txt

:: Fill unused with 0x00
if exist error.txt del error.txt /Q
%HEXVIEW% %PREFIX%bmhd_merged.hex /FR:0,0x200 /FP:00 /S /E=error.txt /XI -o %PREFIX%bmhd_merged_filled.hex
if exist error.txt type error.txt

:: Cleanup temporary files
if exist %PREFIX%bmhdid.hex del %PREFIX%bmhdid.hex /Q
if exist %PREFIX%bmi.hex del %PREFIX%bmi.hex /Q
if exist %PREFIX%stad.hex del %PREFIX%stad.hex /Q
if exist %PREFIX%stad_swap.hex del %PREFIX%stad_swap.hex /Q
if exist %PREFIX%bmhd.hex del %PREFIX%bmhd.hex /Q
if exist %PREFIX%bmhd_swap.hex del %PREFIX%bmhd_swap.hex /Q
if exist %PREFIX%bmhd_swap_crc.hex del %PREFIX%bmhd_swap_crc.hex /Q
if exist %PREFIX%bmhd_swap_crc_swap.hex del %PREFIX%bmhd_swap_crc_swap.hex /Q
if exist %PREFIX%crc.hex del %PREFIX%crc.hex /Q
if exist %PREFIX%crc_invert.hex del %PREFIX%crc_invert.hex /Q
if exist %PREFIX%crc_invert_cut.hex del %PREFIX%crc_invert_cut.hex /Q
if exist %PREFIX%confirmation.hex del %PREFIX%confirmation.hex /Q
if exist %PREFIX%bmhd_merged.hex del %PREFIX%bmhd_merged.hex /Q
if exist %PREFIX%bmhd_merged_filled.hex move /Y %PREFIX%bmhd_merged_filled.hex bmhd.hex

echo.
:target_input
echo Shall this BMHD be used for
echo 1: TO_UPDATER
echo 2: TO_FBL
set /p TARGET=Enter 1 or 2:

if "%TARGET%"=="1" goto UPDATER
if "%TARGET%"=="2" goto FBL
echo Invalid Input
goto target_input

:UPDATER
set TARGET=ToUpdater
goto CONTINUE
:FBL
set TARGET=ToFbl
goto CONTINUE
:CONTINUE

rem Generate ini-file for HexView
@echo [C_EXPORT]            > bmhd.ini
@echo Decryptvalue=0       >> bmhd.ini
@echo Prefix=FblUpdBmhdField_%TARGET% >> bmhd.ini
@echo Decryption=0         >> bmhd.ini
@echo WordSize=0           >> bmhd.ini
@echo WordType=-1          >> bmhd.ini
@echo StrictAnsiC=0        >> bmhd.ini
@echo CreateFAR=0          >> bmhd.ini
@echo CreateMemmap=1       >> bmhd.ini
@echo CreateStruct=1       >> bmhd.ini
@echo MaxBlockSize=        >> bmhd.ini
@echo Metrowerks=0         >> bmhd.ini

rem Create C-File for new Bootloader before generating the Update-FBL application.
if exist error.txt del error.txt /Q
%HEXVIEW% bmhd.hex -s /P:bmhd.ini /E=error.txt -xc
if exist error.txt type error.txt

:: Cleanup temporary files
if exist bmhd.ini del bmhd.ini /Q

if exist bmhd.c move bmhd.c Source/BMHD_%TARGET%.c
if exist bmhd.h move bmhd.h Include/BMHD_%TARGET%.h

echo.
echo Output is generated to Source/BMHD_%TARGET%.c / Include/BMHD_%TARGET%.h
echo.