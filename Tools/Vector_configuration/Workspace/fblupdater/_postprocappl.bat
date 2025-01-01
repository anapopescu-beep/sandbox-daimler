@echo off
rem **********************************************************************************************************************
rem *  -------------------------------------------------------------------------------------------------------------------
rem *  EXAMPLE CODE ONLY
rem *  -------------------------------------------------------------------------------------------------------------------
rem *  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW
rem *  configuration. The Example Code has not passed any quality control measures and may be incomplete. The
rem *  Example Code is neither intended nor qualified for use in series production. The Example Code as well
rem *  as any of its modifications and/or implementations must be tested with diligent care and must comply
rem *  with all quality requirements which are necessary according to the state of the art before their use.
rem *********************************************************************************************************************

set FBL_UPD_LOCATION=%~dp0\..\..\..\Build_Env\Workspace\Outputs\fbl_upd\Out

set fbl_sip_path=C:\Vector\stk_aurix\mb\fbl_mcal_integrated_1.2.1.0
set hexview=S:\Tools\HexView\Installation\HexView-1.13.01\hexview.exe

if not exist %hexview% goto error
  
rem SWDL files now created in ODX project  
rem dag_swdl_files_create.py -i %FBL_UPD_LOCATION%\fbl_upd.hex

echo Moving DAG SWDL files to FBL_UPDATER's output folder

move fbl_upd.crc %FBL_UPD_LOCATION% > nul
move fbl_upd_cccv2.sig %FBL_UPD_LOCATION% > nul
move fbl_upd_enc.hex %FBL_UPD_LOCATION% > nul
move fbl_upd_enc_cccv2.sig %FBL_UPD_LOCATION% > nul
move fbl_upd_lz77.hex %FBL_UPD_LOCATION% > nul
move fbl_upd_lz77_cccv2.sig %FBL_UPD_LOCATION% > nul
move fbl_upd_lz77_enc.hex %FBL_UPD_LOCATION% > nul
move fbl_upd_lz77_enc_cccv2.sig %FBL_UPD_LOCATION% > nul
move fbl_upd_lzma.hex %FBL_UPD_LOCATION% > nul
move fbl_upd_lzma_cccv2.sig %FBL_UPD_LOCATION% > nul
move fbl_upd_lzma_enc.hex %FBL_UPD_LOCATION% > nul
move fbl_upd_lzma_enc_cccv2.sig %FBL_UPD_LOCATION% > nul

goto end

:usage
echo "Please call with a hex file as parameter."
pause
goto end

:error
echo "Please adapt hexview parameter in _postprocappl.bat."
pause
goto end

:end
