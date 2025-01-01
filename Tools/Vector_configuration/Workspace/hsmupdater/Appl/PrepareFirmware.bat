@echo off


set HEXVIEW=S:\Tools\HexView\Installation\HexView-1.13.01\hexview.exe
set VHSM_HEX=S:\Tools\Build_Env\Workspace\Outputs\hsm\Out\hsm.hex
set VHSM_OUTPUT_LOCATION==%~dp0\..\..\..\..\Build_Env\Workspace\Outputs\hsm\Out
set VHSM_UPD_FLASH=0x80000000
set VHSM_FLASH=0x80008000
set VHSM_VERSION=0x80008040
set VHSM_FW=0x80008060

:: Create a single block but leave space for the PP (0x20) and MASK (0x20)
if exist %VHSM_HEX% copy %VHSM_HEX% _vHsm_original.hex

:: Add PP and remove the dummy function vHsmUpd_Reset_Handler from the vHsmUpd address space, since it is only needed to link to the jump to vHsmUpd address.
if exist _vHsm_original.hex %HEXVIEW% _vHsm_original.hex /FP:736A253E00000000000000000000000000000000000000000000000000000000 /FR:%VHSM_FLASH%,0x20 /CR:%VHSM_UPD_FLASH%,0x4000 /XI /s -o _vHsm_Merged_1.hex

:: Leave the mask empty so it remains erased!
:: if exist _vHsm_original.hex ..\..\Misc\Hexview\hexview.exe _vHsm_original.hex /FP:00000000 /FR:0x80008020,0x04 /XI /s -o _vHsm_Merged.hex

:: Add Version
if exist _vHsm_Merged_1.hex %HEXVIEW% _vHsm_Merged_1.hex /FP:0022240000000000000000000000000000000000000000000000000000000000 /FR:%VHSM_VERSION%,0x20 /XI /s -o _vHsm_Merged_2.hex

:: Single Block the rest
if exist _vHsm_Merged_2.hex %HEXVIEW% _vHsm_Merged_2.hex /FR:%VHSM_FW%,0x1FFA0 /FP:0x00 /XI /s -o vHsm.hex
::if exist _vHsm_Merged_2.hex %HEXVIEW% _vHsm_Merged_2.hex /FR:%VHSM_FW%,0x1FFA0 /FP:0xCA /XI /s -o vHsm_new.hex

:: Copy the output to hsm's output location and replace existing one
if exist vHsm.hex copy vHsm.hex %VHSM_OUTPUT_LOCATION%\hsm.hex

if exist _vHsm_Merged_1.hex del _vHsm_Merged_1.hex
if exist _vHsm_Merged_2.hex del _vHsm_Merged_2.hex