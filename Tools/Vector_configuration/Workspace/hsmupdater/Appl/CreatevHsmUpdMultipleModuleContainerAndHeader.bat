@echo off
:: *******************************************************************************************************************
:: FILE DESCRIPTION
:: -------------------------------------------------------------------------------------------------------------------
:: File:         CreatevHsmUpdMultipleModuleContainerAndHeader.bat
:: Description:  Creates an HSM update container according to SPECDOC47356: vHSM Updater Specification
::               for multiple Modules. (Can also be used for one module in OTA use case)
::               The SBL-Area is not supported in this version.
:: -------------------------------------------------------------------------------------------------------------------
:: REVISION HISTORY
:: -------------------------------------------------------------------------------------------------------------------
:: 00.01.00  2021-03-05   visfnn    Initial version
:: *******************************************************************************************************************

rem ##################################################################################################################
rem ---------------------------------------------Predefinition Area---------------------------------------------------
rem ##################################################################################################################
rem                                     You shouldn't edit the Values below
rem ##################################################################################################################

setlocal ENABLEDELAYEDEXPANSION
set TARGET_ACTIVE_PARTITION=0x00000000
set TARGET_INACTIVE_PARTITION=0x00000001

rem prepare some variables:
set /A UPD_IMG_NUMBEROFMODULES=0
set UPD_IMG_PAYLOADBINARYS=
set UPD_IMG_TARGET_ADDRESS=
set UPD_IMG_TARGET_PARTITIONS=

rem ----  Container Sizes ----
set CNT_HDR_MAGIC_PATTERN_SIZE=16
set CNT_HDR_UPDATE_VERSION_SIZE=4
set CNT_HDR_OFFSET_SIZE=4

rem ----  AES BLOCK ALIGNMENT ----
set /A HSM_ALIGNMENT=16

rem ----- Predefined Header values -------
set HSM_UPD_HEADER_PRESENCEPATTERN_VALUE=736A253E
set HSM_UPD_HEADER_TAG=5645435F4550505F48534D0000000001

rem ----  Container Magic Pattern and Version ( Container TAG )----
set MAGIC_PATTERN=5645435F4844525F48534D0000000001

rem ---- If set to ON, the interim result files will not deleted ----
set DEBUG=ON

set TEMP_DIR=_temp
rem ##################################################################################################################
rem ---------------------------------------------Configuration Area---------------------------------------------------
rem ##################################################################################################################
rem                           You have to edit the values below for your project
rem                                     Some of the values are predefined
rem ##################################################################################################################

rem ----------------------------------  General Configuration ------------------------------------------
rem ----  Path to HexView executable ----
set "HEXVIEW=S:\Tools\HexView\Installation\HexView-1.14.00\hexview.exe"

rem ----  Set the PAGESIZE of your ECU here ----
set PLATFORM_PAGESIZE=32

rem ----------------------------------  Update Container -----------------------------------------------

set "CONTAINER_FILE=vHsmUpd_ModularUpdateContainer"


rem ----  BEEFBABE is used to have a impressive sign, if the update was successfull ----
set UPDATE_VERSION=00222400

:: Target address (host memory area to which the HSM update will be downloaded)
set HSM_UPD_CONTAINER_ADDRESS_HEX=0x8006C100

:: Encryption parameters (AES-CBC, no padding)
set "ENC_PARAM=/DP11:92122a4c923b39217e1bb0698d691d1b#IV=5370657A69616C4569576F6D69736175"

:: Signature parameters (ED25519PH on hashed data w/ SHA-512, private key in .txt file)
set "SIG_PARAM=/DP46:833fe62409237b9d62ec77587520911e9a759cec1d19755b7da901b96dca3d42"
rem PubKey:  0xec, 0x17, 0x2b, 0x93, 0xad, 0x5e, 0x56, 0x3b, 0xf4, 0x93, 0x2c, 0x70, 0xe1, 0x24, 0x50, 0x34, 0xc3, 0x54, 0x67, 0xef, 0x2e, 0xfd, 0x4d, 0x64, 0xeb, 0xf8, 0x19, 0x68, 0x34, 0x67, 0xe2, 0xbf
rem or load from file containing the priv key:
rem set "SIG_PARAM=/DP46:@hsm_sig_param.txt"


rem ----------------------------------  Update IMAGE -----------------------------------------------

:: The number of modules to update at once


rem #################################################################################################################
rem Add the Modules as shown in this example
rem
rem
rem    call        :registerModule       Module.hex        0x00030300                %TARGET_ACTIVE_PARTITION%
rem                      ^                   ^                  ^                                ^
rem                      |                   |                  |                                |
rem            Function to add another       |         Target address, where                     |
rem                   module                 |        hex file will be written                   |
rem                                          |    (normally regionStart + 3*pagesize)            |
rem                                          |        WITH ALL LEADING ZEROS!
rem                                          |                                                   |
rem                              Name of the module update                                       |
rem                                      hex file                                    The target partition for the 
rem                                                                                 module update hex file.
rem                                                                                use: %TARGET_ACTIVE_PARTITION% or
rem                                                                                   %TARGET_INACTIVE_PARTITION%
rem      
rem #################################################################################################################

rem example for two modules
call :registerModule  _vHsm_original.hex  0x80008060  %TARGET_ACTIVE_PARTITION%
rem call :registerModule  vHsmUpd.hex  0x80000000  %TARGET_INACTIVE_PARTITION%

rem #################################################################################################################
rem To prevent from having the same encrypted binary on similar updates you can modify the padding inside of the
rem first update image block (See TechRef chapter	Encryption with static IV)
rem #################################################################################################################

rem 12 hex digets of padding (change one digest on any update!!)
set paddingInFirstBlock=010203040506070809101112

echo !UPD_IMG_PAYLOADBINARYS!
echo !UPD_IMG_TARGET_ADDRESS!
echo !UPD_IMG_TARGET_PARTITIONS!

rem ----------------------------------  Update Header -----------------------------------------------
rem The update header is normally created by the FBL on the host core. For an integration help, a valid Update header is
rem created.
rem ----  Update Header Infos ----

set "HSM_UPD_HEADER_FILENAME=vHsmUpd_Header"

set HSM_UPD_HEADER_ADDRESS=0x8006C000

set "CMAC_PARAM=/DP44:000102030405060708090A0B0C0D0E0F"


rem ##################################################################################################################
rem ---------------------------------------------Production Area------------------------------------------------------
rem ##################################################################################################################
rem                                    You shouldn't edit the batchfile below
rem ##################################################################################################################















if not EXIST !TEMP_DIR! (
  mkdir !TEMP_DIR!
)

rem ---- Update Image Sizes ----

set /A MODULAR_UPDATE_HEADER_SIZE=16
set /A MODULAR_IMGAGE_HEADER_SIZE=32

set FW_OFFSET_BIN=


set UPD_IMG_PAYLOADBINARYS_ALIGNED=
set UPD_IMG_PAYLOADBINARYS_ALIGNED_SIZES_HEX=
set UPD_IMG_PAYLOADBINARYS_ALIGNED_SIZES=
set UPD_IMG_PAYLOADBINARYS_CRC_BIN=
set UPD_IMG_PAYLOADBINARYS_CRC_HEX=
set UPD_IMG_PAYLOADBINARYS_TARGET_PARTITION_HEX=
set UPD_IMG_PAYLOADBINARYS_TARGET_ADDRESS_HEX=
set UPD_IMG_PAYLOADBINARYS_LENGTH_OF_HEADER_HEX=
set UPD_IMG_PAYLOADBINARYS_NUMBER_OF_MODULES_HEX=

set UPD_IMG_HEADER_UPDATE_PATTERN_HEX=4D4F4455

rem --- Container Sizes ----
set /A CNT_TAG_SIZE=16
set /A CNT_UPDATE_VERSION_SIZE=4
set /A CNT_SIGNATURE_OFFSET_SIZE=4


set /A counter=1
rem --------------------------------      Prepare the Module image header      ---------------------------------------------

rem Padd all module payloads to AES Block length and fill gaps
for %%a in (!UPD_IMG_PAYLOADBINARYS!) do (
  :: Padd all module payloads to AES Block length and fill gaps
  %HEXVIEW% %%a /AD:%HSM_ALIGNMENT% /AL /FA /XN /s -o !TEMP_DIR!/%%~na_aligned.bin
  set UPD_IMG_PAYLOADBINARYS_ALIGNED[!counter!]=!TEMP_DIR!/%%~na_aligned.bin
  
  :: Calculate the length of each module
  call :GetFileSize !TEMP_DIR!/%%~na_aligned.bin UPD_IMG_PAYLOADBINARYS_ALIGNED_SIZES[!counter!]
  
  rem ::get CRC values of binaries
  %HEXVIEW% !TEMP_DIR!/%%~na_aligned.bin /CS9:%%~na_Crc.txt /s
  call :GetCrC32ValueFromFile %%~na_Crc.txt UPD_IMG_PAYLOADBINARYS_CRC_HEX[!counter!]
  
  del %%~na_Crc.txt
  
  (for /f %%c in ("!counter!") do ( 
    %HEXVIEW% /FR:0,4 /FP:!UPD_IMG_PAYLOADBINARYS_CRC_HEX[%%c]! /XN /s -o !TEMP_DIR!/%%~na_Crc.bin
    %HEXVIEW% !TEMP_DIR!/%%~na_Crc.bin /AD:%HSM_ALIGNMENT% /AL /AF00 /FA /XN /s -o !TEMP_DIR!/%%~na_Crc.bin
  
    rem recalculate length to hex
    call :Dec2Hex !UPD_IMG_PAYLOADBINARYS_ALIGNED_SIZES[%%c]! UPD_IMG_PAYLOADBINARYS_ALIGNED_SIZES_HEX[%%c]
  ))
  
  set UPD_IMG_PAYLOADBINARYS_CRC_BIN[!counter!]=!TEMP_DIR!/%%~na_Crc.bin
  set /A counter+=1
)

set /A counter=1

rem ---- Set the target partition ----
for %%a in (!UPD_IMG_TARGET_PARTITIONS!) do (
  set buffer=%%a
  set UPD_IMG_PAYLOADBINARYS_TARGET_PARTITION_HEX[!counter!]=!buffer:~2!
  set /A counter+=1
)

rem ---- Reset Counter ----
set /A counter=1
rem ---- Set the target Address ----
for %%a in (!UPD_IMG_TARGET_ADDRESS!) do (
  set buffer=%%a
  set UPD_IMG_PAYLOADBINARYS_TARGET_ADDRESS_HEX[!counter!]=!buffer:~2!
  set /A counter+=1
)

rem -------------------------------     prepare ModularUpdateHeader parts      ---------------------------------------------
set /A MODULAR_HEADER_COMPLETE_LENGTH=%MODULAR_UPDATE_HEADER_SIZE% + (%UPD_IMG_NUMBEROFMODULES% * %MODULAR_IMGAGE_HEADER_SIZE%)
echo The Number of Modules: %UPD_IMG_NUMBEROFMODULES%
call :Dec2Hex %MODULAR_HEADER_COMPLETE_LENGTH% UPD_IMG_PAYLOADBINARYS_LENGTH_OF_HEADER_HEX
call :Dec2Hex %UPD_IMG_NUMBEROFMODULES% UPD_IMG_PAYLOADBINARYS_NUMBER_OF_MODULES_HEX

echo Length of Header 0x%UPD_IMG_PAYLOADBINARYS_LENGTH_OF_HEADER_HEX%

set /A FW_OFSET=%MODULAR_HEADER_COMPLETE_LENGTH% + %HSM_ALIGNMENT%
call :Dec2Hex %FW_OFSET% FW_OFFSET_HEX
%HEXVIEW% /FR:0,16 /FP:%FW_OFFSET_HEX%%paddingInFirstBlock% /AD:%HSM_ALIGNMENT% /AL /AF00 /FA /XN /s -o !TEMP_DIR!/FwOffset.bin



rem ------------------------------- Build the single modular headers -----------------------------------
set MODULEUPDATE_OFFSET_HEX=00000000
set /A MODULEUPDATE_OFFSET=0
(for /l %%e in (1,1,!UPD_IMG_NUMBEROFMODULES!) do (
%HEXVIEW% /FR:0,20 /FP:!UPD_IMG_PAYLOADBINARYS_TARGET_PARTITION_HEX[%%e]!!UPD_IMG_PAYLOADBINARYS_TARGET_ADDRESS_HEX[%%e]!!MODULEUPDATE_OFFSET_HEX!!UPD_IMG_PAYLOADBINARYS_ALIGNED_SIZES_HEX[%%e]!!UPD_IMG_PAYLOADBINARYS_CRC_HEX[%%e]! /AD:%HSM_ALIGNMENT% /AL /AF00 /FA /XN /s -o !TEMP_DIR!/Module%%e_Header.bin
set /A MODULEUPDATE_OFFSET=!MODULEUPDATE_OFFSET!+!UPD_IMG_PAYLOADBINARYS_ALIGNED_SIZES[%%e]!
call :Dec2Hex !MODULEUPDATE_OFFSET! MODULEUPDATE_OFFSET_HEX
))

rem -------------------------------Concatenate the modular image headers ------------------------------------
set CONCATENATED_MODULES_BIN=
if !UPD_IMG_NUMBEROFMODULES! EQU 1 (

  set CONCATENATED_MODULES_BIN=!TEMP_DIR!/Module1_Header.bin

) else (
  
  set /A EINS=1
  set /A NUMBEROFMODULES_MINUS_1=!UPD_IMG_NUMBEROFMODULES!-1
  
  rem ---- if more than one module, concatenate in loop ----
  for /l %%e in (1,1,!NUMBEROFMODULES_MINUS_1!) do (
    set /A NEXT_HEADER=%%e+1
    set /A CURRENT_MODULE_HEADER_OFFSET=!MODULAR_IMGAGE_HEADER_SIZE!*%%e
    %HEXVIEW% !TEMP_DIR!/Module%%e_Header.bin /MT:!TEMP_DIR!/Module!NEXT_HEADER!_Header.bin;!CURRENT_MODULE_HEADER_OFFSET! /XN /s -o !TEMP_DIR!/Module!NEXT_HEADER!_Header.bin
    set CONCATENATED_MODULES_BIN=!TEMP_DIR!/Module!NEXT_HEADER!_Header.bin

  )
)

rem ----------- Build Modular update header -------------
%HEXVIEW% /FR:0,12 /FP:!UPD_IMG_HEADER_UPDATE_PATTERN_HEX!!UPD_IMG_PAYLOADBINARYS_LENGTH_OF_HEADER_HEX!!UPD_IMG_PAYLOADBINARYS_NUMBER_OF_MODULES_HEX! /AD:%HSM_ALIGNMENT% /AL /AF00 /FA /XN /s -o !TEMP_DIR!/ModuleUpdate_Header.bin

rem ----------- Concatenate Module image headers with module update header  ---------------
%HEXVIEW% !TEMP_DIR!/ModuleUpdate_Header.bin /MT:!CONCATENATED_MODULES_BIN!;16 /XN /s -o !TEMP_DIR!/CompleteModularUpdateHeader.bin

rem ----------- Add FwOffset  ---------------
%HEXVIEW% !TEMP_DIR!/FwOffset.bin /MT:!TEMP_DIR!/CompleteModularUpdateHeader.bin;16 /XN /s -o !TEMP_DIR!/CompleteModularUpdateHeader.bin

rem ------------ Add the binarys -------------------
set /A MODULEUPDATE_OFFSET=!MODULAR_HEADER_COMPLETE_LENGTH! + !HSM_ALIGNMENT!

for /l %%e in (1,1,!UPD_IMG_NUMBEROFMODULES!) do (
  %HEXVIEW% !TEMP_DIR!/CompleteModularUpdateHeader.bin /MT:!UPD_IMG_PAYLOADBINARYS_ALIGNED[%%e]!;!MODULEUPDATE_OFFSET! /XN /s -o !TEMP_DIR!/CompleteModularUpdateHeader.bin
  
  set /A MODULEUPDATE_OFFSET=!MODULEUPDATE_OFFSET!+!UPD_IMG_PAYLOADBINARYS_ALIGNED_SIZES[%%e]!
)

rem ------------ Add the last empty aes block -------------------
rem setup a empty last block
%HEXVIEW% /FR:0,16 /FP:00 /XN /s -o !TEMP_DIR!/EmptyBlock.bin
%HEXVIEW% !TEMP_DIR!/CompleteModularUpdateHeader.bin /MT:!TEMP_DIR!/EmptyBlock.bin;!MODULEUPDATE_OFFSET! /XN /s -o !TEMP_DIR!/CompleteUpdateImage.bin

:: Encrypt [ HSM_FW_OFFSET | MOD_UPD_HEADER | MOD_IMG_HEADER| MOD_BINARY_1...* | EMPTYBLOCK ]
%HEXVIEW% !TEMP_DIR!/CompleteUpdateImage.bin %ENC_PARAM% /XN /s -o !TEMP_DIR!/CompleteUpdateImage_Encrypted.bin

rem --------------------------------------------------------- Build Container around encrypted image ------------------------------------------------
:: Calculate offset values for header
:: - CNT_SIGNATURE_OFFSET_HEX is calculated based on the encrypted concatenation of [ HSM_FW_OFFSET | MOD_UPD_HEADER | MOD_IMG_HEADER| MOD_BINARY_1...* | EMPTYBLOCK ]
set /a CNT_HDR_TOTAL_SIZE=%CNT_TAG_SIZE% + %CNT_UPDATE_VERSION_SIZE% + %CNT_SIGNATURE_OFFSET_SIZE%
call :GetFileSize !TEMP_DIR!/CompleteUpdateImage_Encrypted.bin COMPLETE_UPDATE_IMG_ENC_SIZE
set /a SIG_OFFSET=%CNT_HDR_TOTAL_SIZE% + %COMPLETE_UPDATE_IMG_ENC_SIZE%
call :Dec2Hex %SIG_OFFSET% CNT_SIGNATURE_OFFSET_HEX

:: Build Container header
%HEXVIEW% /FR:0,%CNT_HDR_TOTAL_SIZE% /FP:%MAGIC_PATTERN%%UPDATE_VERSION%%CNT_SIGNATURE_OFFSET_HEX% /XN /s -o !TEMP_DIR!/Container_Header.bin

:: Build container with image
%HEXVIEW% !TEMP_DIR!/Container_Header.bin /MT:!TEMP_DIR!/CompleteUpdateImage_Encrypted.bin;%CNT_HDR_TOTAL_SIZE% /XN /s -o !TEMP_DIR!/Container_HDR_IMG.bin

:: Calculate container signature (RSA-PSS with SHA-256 on data)
%HEXVIEW% !TEMP_DIR!/Container_HDR_IMG.bin %SIG_PARAM%;Container_HDR_IMG_Signature.asc /s /E:hexview.log

:: Append signature to container
call :GetFileSize !TEMP_DIR!/Container_HDR_IMG.bin HSM_UPD_CONTAINER_SIZE
%HEXVIEW% /IA:!TEMP_DIR!/Container_HDR_IMG_Signature.asc /XN /s -o !TEMP_DIR!/Container_HDR_IMG_Signature.bin
%HEXVIEW% !TEMP_DIR!/Container_HDR_IMG.bin /MT:!TEMP_DIR!/Container_HDR_IMG_Signature.bin;%HSM_UPD_CONTAINER_SIZE% /XN /s -o !TEMP_DIR!/CompleteUpdateContainer.bin
%HEXVIEW% /MT:!TEMP_DIR!/CompleteUpdateContainer.bin;%HSM_UPD_CONTAINER_ADDRESS_HEX% /XS /s -o %CONTAINER_FILE%.hex

echo.
echo ####################
echo Update Container:
echo ####################
echo Info:
echo This data is passed to the vHsm AEAD encrypt job by the FBL
echo.
echo Tag:                VEC_HDR_HSM
echo Address:            %HSM_UPD_CONTAINER_ADDRESS_HEX%  (Start address of the update container beginning with the header. The header (first 24 bytes) is passed as input during the START call of the AEAD job.)
echo Sig Offset:         0x%CNT_SIGNATURE_OFFSET_HEX%  (Offset of the signature as seen from the start address of the update container. The signature is passed as secondary input during the FINISH call of the AEAD job.)
echo Version:            0x%CNT_UPDATE_VERSION_SIZE%
echo.


rem ##################################################################################################################
rem ---------------------------------------------Integration Help-----------------------------------------------------
rem ##################################################################################################################
rem                         Building a update header to flash this header directly
rem ##################################################################################################################

:: Create Updateheader
:: recalculate address to decimal and add the container header length
set /A ENCRYPTED_IMAGE_IN_CONTAINER_ADDRESS_DEC=%HSM_UPD_CONTAINER_ADDRESS_HEX%+%CNT_HDR_TOTAL_SIZE%
call :Dec2Hex %ENCRYPTED_IMAGE_IN_CONTAINER_ADDRESS_DEC% ENCRYPTED_IMAGE_IN_CONTAINER_ADDRESS_HEX

call :Dec2Hex %COMPLETE_UPDATE_IMG_ENC_SIZE% COMPLETE_UPDATE_IMG_ENC_SIZE_HEX



%HEXVIEW% /FR:0,16 /FP:%HSM_UPD_HEADER_TAG% /XN /s -o !TEMP_DIR!/%HSM_UPD_HEADER_FILENAME%_tag.bin
%HEXVIEW% /FR:0,12 /FP:%UPDATE_VERSION%%ENCRYPTED_IMAGE_IN_CONTAINER_ADDRESS_HEX%%COMPLETE_UPDATE_IMG_ENC_SIZE_HEX% /XN /s -o !TEMP_DIR!/%HSM_UPD_HEADER_FILENAME%_version_address_length.bin
%HEXVIEW% !TEMP_DIR!/CompleteUpdateImage_Encrypted.bin /MT:!TEMP_DIR!/%HSM_UPD_HEADER_FILENAME%_version_address_length.bin;%COMPLETE_UPDATE_IMG_ENC_SIZE% /XN /s -o !TEMP_DIR!/%HSM_UPD_HEADER_FILENAME%_dataForCmac.bin

%HEXVIEW% !TEMP_DIR!/%HSM_UPD_HEADER_FILENAME%_dataForCmac.bin %CMAC_PARAM%;%HSM_UPD_HEADER_FILENAME%_cmac.asc /s

%HEXVIEW% /IA:!TEMP_DIR!/%HSM_UPD_HEADER_FILENAME%_cmac.asc /XN /s -o !TEMP_DIR!/%HSM_UPD_HEADER_FILENAME%_cmac.bin
%HEXVIEW% !TEMP_DIR!/%HSM_UPD_HEADER_FILENAME%_tag.bin /MT:!TEMP_DIR!/%HSM_UPD_HEADER_FILENAME%_version_address_length.bin;16 /XN /s -o !TEMP_DIR!/%HSM_UPD_HEADER_FILENAME%_tag_version_address_length.bin
%HEXVIEW% !TEMP_DIR!/%HSM_UPD_HEADER_FILENAME%_tag_version_address_length.bin /MT:!TEMP_DIR!/%HSM_UPD_HEADER_FILENAME%_cmac.bin;28 /XN /s -o !TEMP_DIR!/%HSM_UPD_HEADER_FILENAME%.bin

rem ----- Align the header to pagesize -----
%HEXVIEW% !TEMP_DIR!/%HSM_UPD_HEADER_FILENAME%.bin /AD:%PLATFORM_PAGESIZE% /AL /AF00 /FA /XN /s -o !TEMP_DIR!/%HSM_UPD_HEADER_FILENAME%_woPP.bin
%HEXVIEW% /FR:0,4 /FP:%HSM_UPD_HEADER_PRESENCEPATTERN_VALUE% /AD:%PLATFORM_PAGESIZE% /AL /AF00 /XN /s -o !TEMP_DIR!/PresencePattern.bin

call :GetFileSize !TEMP_DIR!/%HSM_UPD_HEADER_FILENAME%_woPP.bin PP_OFFSET
%HEXVIEW% !TEMP_DIR!/%HSM_UPD_HEADER_FILENAME%_woPP.bin /MT:!TEMP_DIR!/PresencePattern.bin;%PP_OFFSET% /XN /s -o !TEMP_DIR!/%HSM_UPD_HEADER_FILENAME%.bin
%HEXVIEW% /MT:!TEMP_DIR!/%HSM_UPD_HEADER_FILENAME%.bin;%HSM_UPD_HEADER_ADDRESS% /XI /s -o %HSM_UPD_HEADER_FILENAME%.hex

echo ####################
echo Update Header:
echo ####################
echo Info:
echo This data is usually created by the FBL during a download of the vHsm Update container.
echo The header (first 28 bytes of it which excludes the CMAC) is passed as secondary input during START of the AEAD job.
echo.
echo Tag:                VEC_EPP_HSM
echo Upd Header Address: %HSM_UPD_HEADER_ADDRESS%  (Address where the vHsm Updater will search for a valid header)
echo FW Image Address:   0x%ENCRYPTED_IMAGE_IN_CONTAINER_ADDRESS_HEX%  (Start of encrypted FW image data which is located inside the update container. This is passed as input during the UPDATE calls of the AEAD job. )
echo FW Image Size:      0x%COMPLETE_UPDATE_IMG_ENC_SIZE_HEX%  (Size of the encrypted firmware image (excluding the other information from the update container header like version and signature offset and the signature itself.
echo                                  This is the amount of data passed as input during the UPDATE calls of the AEAD job.)
echo Update Version:     0x%UPDATE_VERSION%
echo Platform Pagesize:  %PLATFORM_PAGESIZE%          (Used to calculate the offset and length of the presence pattern)
echo Cmac:                           (The CMAC is calculated by the vHsm AEAD Encrypt job over the data of encrypted firmware image and some additional information of the headers. The CMAC is returned by the AEAD job as secondary output in the FINISH call)
rem type %HEADER_FILE%_cmac.bin
echo.

:: Delete intermediate files
if "%DEBUG%" NEQ "ON" (

RMDIR /S /Q !TEMP_DIR!

) else (

(for /l %%e in (1,1,!UPD_IMG_NUMBEROFMODULES!) do ( 
   echo !UPD_IMG_PAYLOADBINARYS_ALIGNED[%%e]!
   echo !UPD_IMG_PAYLOADBINARYS_ALIGNED_SIZES_HEX[%%e]!
   echo !UPD_IMG_PAYLOADBINARYS_ALIGNED_SIZES[%%e]!
   echo !UPD_IMG_PAYLOADBINARYS_CRC_BIN[%%e]!
   echo !UPD_IMG_PAYLOADBINARYS_TARGET_ADDRESS_HEX[%%e]!
   echo !UPD_IMG_PAYLOADBINARYS_TARGET_PARTITION_HEX[%%e]!
   
))
)
endlocal

:: %1 Name Of crc txt
:: %2 output concatenated string.
:GetCrC32ValueFromFile
(for /F "tokens=1-4 delims=, " %%a in (%1) do ( 
  set awert=%%a
  set awert=!awert:~2!
  set  crcValue=!awert!
  set awert=%%b
  set awert=!awert:~2!
  set  crcValue=!crcValue!!awert!
  set awert=%%c
  set awert=!awert:~2!
  set  crcValue=!crcValue!!awert!
  set awert=%%d
  set awert=!awert:~2!
  set  crcValue=!crcValue!!awert!
  set %2=!crcValue!
  ))
exit /b


:Dec2Hex
setlocal ENABLEDELAYEDEXPANSION
call cmd /c exit /b %~1
set hex=%=exitcode%

( endlocal & REM RETURN VALUES
    if "%~2" NEQ "" (SET %~2=%hex%) else echo.%hex%
)
exit /b

:GetFileSize
if /i "%~x1" == ".bin" (
   :: Binary file passed
   call :GetBinFileSize %1 %2
) else (
   :: Convert to bin file
   %HEXVIEW% %1 /FA /XN /s -o %~n1.bin
   call :GetBinFileSize %~n1.bin %2
)
exit /b

:GetBinFileSize
set %2=%~z1
exit /b

:Hex2Dec
setlocal ENABLEDELAYEDEXPANSION
set /a dec=%hex%
( endlocal & REM RETURN VALUES
    if "%~2" NEQ "" (SET %~2=%dec%) else echo.%dec%
)
exit /b

:registerModule
set /A UPD_IMG_NUMBEROFMODULES+=1
set UPD_IMG_PAYLOADBINARYS=!UPD_IMG_PAYLOADBINARYS! %1
set UPD_IMG_TARGET_ADDRESS=!UPD_IMG_TARGET_ADDRESS! %2
set UPD_IMG_TARGET_PARTITIONS=!UPD_IMG_TARGET_PARTITIONS! %3
exit /b
