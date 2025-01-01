:: Create checksums
@echo off
if "%1" == "" goto usage

echo.
echo Generate 2 checksums (CRC32, ECC)
echo Compress file (Vector compression)
echo.
echo CRC (Security model NONE)          :
echo %~d1%~p1%~n1.crc
echo ECC signature (Security Class CCCv2) : 
echo %~d1%~p1%~n1_cccv2.sig
echo Compressed file                    :
echo %~d1%~p1%~n1_cmpr%~x1
echo.

set local_dir=%~d0%~p0

:: Please configure the following variables
:: Root directory
set root_dir=%local_dir%..\..\..
:: Hexview executable
set hexview_exe=%root_dir%\Misc\Hexview\hexview.exe
:: Key
set ecc_key=%root_dir%\Demo\Demokeys\cccv2_key_private.txt

echo Calculate CRC...
%hexview_exe% %1 /S -e:%local_dir%error.txt /cs9:%~n1.crc

echo Calculate Ed25519ph signature (Security class CCCv2)..
%hexview_exe% %1 /S -e:%local_dir%error.txt /dp49:%ecc_key%;%~n1_cccv2.sig

echo Create compressed download file...
%hexview_exe% %1 -S -e:%local_dir%error.txt -dp19 -xi -o %~n1_cmpr%~x1

echo ...finished.
echo.
goto end

:usage
echo "Please call with a hex file as parameter."

pause
del %local_dir%\error.txt

:end