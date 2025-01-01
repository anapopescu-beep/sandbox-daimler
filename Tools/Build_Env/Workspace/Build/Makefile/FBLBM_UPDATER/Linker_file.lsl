/**********************************************************************************************************************
 *  EXAMPLE CODE ONLY
 *  -------------------------------------------------------------------------------------------------------------------
 *  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW configuration.
 *  The Example Code has not passed any quality control measures and may be incomplete. The Example Code is neither
 *  intended nor qualified for use in series production. The Example Code as well as any of its modifications and/or
 *  implementations must be tested with diligent care and must comply with all quality requirements which are necessary
 *  according to the state of the art before their use.
 *********************************************************************************************************************/


architecture TC1V1.6.2
{
  endianness
  {
    little;
  }
  space linear
  {
    id = 1;
    mau = 8;
    map (dest = bus:local_bus, size = 4G);
    copytable (align = 4, copy_unit = 1, dest = linear);
  }
  bus local_bus
  {
    mau = 8;
    width = 32;
  }
}

derivative mpe
{
  core vtc
  {
    architecture = TC1V1.6.2;
  }
  bus local_bus
  {
    mau = 8;
    width = 32;
    map (dest = bus:vtc:local_bus, dest_offset = 0, size = 4G);
  }
  section_setup :vtc:linear
  {
    start_address (symbol = "brsStartupEntry");
  }
  memory DefaultRamArea_Stack
  {
    mau = 8;
    type = ram;
    size = 16384; /* 16 KiB */
    map (dest=bus:local_bus, dest_offset = 0x70000000, size = 16384);
  }
  memory DefaultRamArea_DSPR0
  {
    mau = 8;
    type = ram;
    size = 81920; /* 80 KiB */
    map (dest=bus:local_bus, dest_offset = 0x70004000, size = 81920);
  }
  memory FlashDrvArea
  {
    mau = 8;
    type = ram;
    size = 2048; /* 2 KiB */
    map (dest=bus:local_bus, dest_offset = 0x70100000, size = 2048);
  }
  memory BmRom_Startup
  {
    mau = 8;
    type = rom;
    size = 512; /* 512 Byte */
    map (dest=bus:local_bus, dest_offset = 0xA0034000, size = 512);
  }
  memory BmRom_ExceptionTable
  {
    mau = 8;
    type = rom;
    size = 256; /* 256 Byte */
    map (dest=bus:local_bus, dest_offset = 0xA0034200, size = 256);
  }
  memory BmHeader
  {
    mau = 8;
    type = rom;
    size = 32; /* 32 Byte */
    map (dest=bus:local_bus, dest_offset = 0xA0034300, size = 32);
  }
  memory BmRomArea
  {
    mau = 8;
    type = rom;
    size = 64736; /* 63 KiB */
    map (dest=bus:local_bus, dest_offset = 0xA0034320, size = 64736);
  }
  memory FblRom_ExceptionTable
  {
    mau = 8;
    type = rom;
    size = 256; /* 256 Byte */
    map (dest=bus:local_bus, dest_offset = 0xA0048000, size = 256);
  }
  memory FblRom_Startup
  {
    mau = 8;
    type = rom;
    size = 512; /* 512 Byte */
    map (dest=bus:local_bus, dest_offset = 0xA0048100, size = 512);
  }
  memory FblBmHdrHeader
  {
    mau = 8;
    type = rom;
    size = 32; /* 32 Byte */
    map (dest=bus:local_bus, dest_offset = 0xA0048300, size = 32);
  }
  memory FblHeader
  {
    mau = 8;
    type = rom;
    size = 32; /* 32 Byte */
    map (dest=bus:local_bus, dest_offset = 0xA0048320, size = 32);
  }
  memory FblRomArea
  {
    mau = 8;
    type = rom;
    size = 126144; /* 123 KiB */
    map (dest=bus:local_bus, dest_offset = 0xA0048340, size = 126144);
  }
  memory FblRomReserved
  {
    mau = 8;
    type = rom;
    size = 4096; /* 4 KiB */
    map (dest=bus:local_bus, dest_offset = 0xA006B000, size = 4096);
  }
  memory ApplInfoHeader
  {
    mau = 8;
    type = rom;
    size = 224; /* 224 Byte */
    map (dest=bus:local_bus, dest_offset = 0xA006C000, size = 224);
  }
  memory ApplBmHdrHeader
  {
    mau = 8;
    type = rom;
    size = 32; /* 32 Byte */
    map (dest=bus:local_bus, dest_offset = 0xA006C0E0, size = 32);
  }
  memory ApplRom_ExceptionTable
  {
    mau = 8;
    type = rom;
    size = 256; /* 256 Byte */
    map (dest=bus:local_bus, dest_offset = 0xA006C100, size = 256);
  }
  memory ApplRom_Startup
  {
    mau = 8;
    type = rom;
    size = 512; /* 512 Byte */
    map (dest=bus:local_bus, dest_offset = 0xA006C200, size = 512);
  }
  memory ApplRomArea
  {
    mau = 8;
    type = rom;
    size = 453632; /* 443 KiB */
    map (dest=bus:local_bus, dest_offset = 0xA006C400, size = 453632);
  }
  memory AppRomReserved
  {
    mau = 8;
    type = rom;
    size = 4096; /* 4 KiB */
    map (dest=bus:local_bus, dest_offset = 0xA00FF000, size = 4096);
  }
  memory RegionBlock_0_BMHD0
  {
    mau = 8;
    type = rom;
    size = 512; /* 512 Byte */
    map (dest=bus:local_bus, dest_offset = 0xAF400000, size = 512);
  }
  memory RegionBlock_0_BMHD1
  {
    mau = 8;
    type = rom;
    size = 512; /* 512 Byte */
    map (dest=bus:local_bus, dest_offset = 0xAF400200, size = 512);
  }
  memory RegionBlock_0_BMHD2
  {
    mau = 8;
    type = rom;
    size = 512; /* 512 Byte */
    map (dest=bus:local_bus, dest_offset = 0xAF400400, size = 512);
  }
  memory RegionBlock_0_BMHD3
  {
    mau = 8;
    type = rom;
    size = 512; /* 512 Byte */
    map (dest=bus:local_bus, dest_offset = 0xAF400600, size = 512);
  }
  memory RegionBlock_0_LMU0_vHsm_Shared
  {
    mau = 8;
    type = ram;
    size = 7680; /* 8 KiB */
    map (dest=bus:local_bus, dest_offset = 0xB0000000, size = 7680);
  }
  memory RegionBlock_0_LMU0_ReprogrammingData
  {
    mau = 8;
    type = ram;
    size = 512; /* 512 Byte */
    map (dest=bus:local_bus, dest_offset = 0xB0001E00, size = 512);
  }
}

section_layout mpe:vtc:linear
{
  group ApplInfoHeaderSection_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:ApplInfoHeader)
  {
    group Upd_ApplBmHdrHeader (ordered, contiguous, fill)
    {
      section "Upd_ApplBmHdrHeader_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]rodata.ApplInfoHeaderSection";
      }
    }
    "_Upd_ApplBmHdrHeader_START" = "_lc_gb_Upd_ApplBmHdrHeader";
    "_Upd_ApplBmHdrHeader_END" = ("_lc_ge_Upd_ApplBmHdrHeader" == 0) ? 0 : "_lc_ge_Upd_ApplBmHdrHeader" - 1;
    "_Upd_ApplBmHdrHeader_LIMIT" = "_lc_ge_Upd_ApplBmHdrHeader";

    "_ApplInfoHeaderSection_ALL_START" = "_Upd_ApplBmHdrHeader_START";
    "_ApplInfoHeaderSection_ALL_END" = "_Upd_ApplBmHdrHeader_END";
    "_ApplInfoHeaderSection_ALL_LIMIT" = "_Upd_ApplBmHdrHeader_LIMIT";
  }

  group BmHdrHeaderGroup_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:ApplBmHdrHeader)
  {
    group Upd_ApplInfoHeader (ordered, contiguous, fill)
    {
      section "Upd_ApplInfoHeader_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]rodata.BmHdrHeaderSection";
      }
    }
    "_Upd_ApplInfoHeader_START" = "_lc_gb_Upd_ApplInfoHeader";
    "_Upd_ApplInfoHeader_END" = ("_lc_ge_Upd_ApplInfoHeader" == 0) ? 0 : "_lc_ge_Upd_ApplInfoHeader" - 1;
    "_Upd_ApplInfoHeader_LIMIT" = "_lc_ge_Upd_ApplInfoHeader";

    "_BmHdrHeaderGroup_ALL_START" = "_Upd_ApplInfoHeader_START";
    "_BmHdrHeaderGroup_ALL_END" = "_Upd_ApplInfoHeader_END";
    "_BmHdrHeaderGroup_ALL_LIMIT" = "_Upd_ApplInfoHeader_LIMIT";
  }

  group CSA_CORE0_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:DefaultRamArea_DSPR0)
  {
    group CSA_CORE0 (ordered, contiguous, fill, align = 64)
    {
      reserved "CSA_CORE0" (size = 16384);
    }
    "_CSA_CORE0_START" = "_lc_gb_CSA_CORE0";
    "_CSA_CORE0_END" = ("_lc_ge_CSA_CORE0" == 0) ? 0 : "_lc_ge_CSA_CORE0" - 1;
    "_CSA_CORE0_LIMIT" = "_lc_ge_CSA_CORE0";

    "_CSA_CORE0_ALL_START" = "_CSA_CORE0_START";
    "_CSA_CORE0_ALL_END" = "_CSA_CORE0_END";
    "_CSA_CORE0_ALL_LIMIT" = "_CSA_CORE0_LIMIT";
  }

  "__CSA_BEGIN_CPU0_" = "_CSA_CORE0_START";
  "__CSA_END_CPU0_" = "_CSA_CORE0_LIMIT";

  group RamConstGroup_ROM_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:ApplRomArea)
  {
    group UpdRamConstSection_ROM (ordered, contiguous, fill, align = 4)
    {
      section "UpdRamConstSection_ROM_SEC" (fill, blocksize = 1, attributes = rx)
      {
        group (load_addr)
        {
          select "[.]rodata.RamConstSection";
          select "[.]rodata.fbl_flio*";
          select "[.]rodata.fbl_diag*";
        }
      }
    }
    "_UpdRamConstSection_ROM_START" = "_lc_gb_UpdRamConstSection_ROM";
    "_UpdRamConstSection_ROM_LIMIT" = "_lc_ge_UpdRamConstSection_ROM";

  }

  group RamConstGroup_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:DefaultRamArea_DSPR0)
  {
    group UpdRamConstSection_ALIGN (align = 4)
    {
      reserved "UpdRamConstSection_ALIGN" (size = 4);
    }
    group UpdRamConstSection (ordered, contiguous, fill, align = 1, copy)
    {
      /* Due to a Linker issue: 'COPY_TO_RAM' const groups cannot be created with inner output section */
      select "[.]rodata.RamConstSection";
      select "[.]rodata.fbl_flio*";
      select "[.]rodata.fbl_diag*";
    }
    group UpdRamConstSection_PAD (align = 4)
    {
      reserved "UpdRamConstSection_PAD" (size = 0);
    }
    "_UpdRamConstSection_START" = "_lc_gb_UpdRamConstSection";
    "_UpdRamConstSection_END" = ("_lc_ge_UpdRamConstSection" == 0) ? 0 : "_lc_ge_UpdRamConstSection" - 1;
    "_UpdRamConstSection_LIMIT" = "_lc_ge_UpdRamConstSection";

    "_RamConstGroup_ALL_START" = "_UpdRamConstSection_START";
    "_RamConstGroup_ALL_END" = "_UpdRamConstSection_END";
    "_RamConstGroup_ALL_LIMIT" = "_UpdRamConstSection_LIMIT";
  }

  "_RESET" = "brsStartupEntry";
  "_start" = "brsStartupEntry";
  "_start_tc0" = "brsStartupEntry";
  "_start_tc1" = "brsStartupEntry";
  "_start_tc2" = "brsStartupEntry";
  "_start_tc3" = "brsStartupEntry";
  "_start_tc4" = "brsStartupEntry";
  "_start_tc5" = "brsStartupEntry";
  "_brsStartupEntry" = "brsStartupEntry";

  "__STARTUPSTACK_CORE0" = "_STACK_C0_LIMIT";

  group StartupGroup_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:ApplRom_Startup)
  {
    group Upd_ApplStartup (ordered, contiguous, fill)
    {
      section "Upd_ApplStartup_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]text.brsResetLabel";
        select "[.]text.brsStartup";
        select "[.]text.brsStartupEntry";
      }
    }
    "_Upd_ApplStartup_START" = "_lc_gb_Upd_ApplStartup";
    "_Upd_ApplStartup_END" = ("_lc_ge_Upd_ApplStartup" == 0) ? 0 : "_lc_ge_Upd_ApplStartup" - 1;
    "_Upd_ApplStartup_LIMIT" = "_lc_ge_Upd_ApplStartup";

    "_StartupGroup_ALL_START" = "_Upd_ApplStartup_START";
    "_StartupGroup_ALL_END" = "_Upd_ApplStartup_END";
    "_StartupGroup_ALL_LIMIT" = "_Upd_ApplStartup_LIMIT";
  }

  group DataDefaultGroup_ROM_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:ApplRomArea)
  {
    group AppDataDefault_ROM (ordered, contiguous, fill, align = 16)
    {
      section "AppDataDefault_ROM_SEC" (fill, blocksize = 2, attributes = rx)
      {
        group (load_addr)
        {
          select "[.]data*";
          select "[.]zdata*";
        }
      }
    }
    "_AppDataDefault_ROM_START" = "_lc_gb_AppDataDefault_ROM";
    "_AppDataDefault_ROM_LIMIT" = "_lc_ge_AppDataDefault_ROM";

  }

  group DataDefaultGroup_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:DefaultRamArea_DSPR0)
  {
    group AppDataDefault (ordered, contiguous, fill, align = 16)
    {
      section "AppDataDefault_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]data*";
        select "[.]zdata*";
      }
    }
    group AppDataDefault_PAD (align = 4)
    {
      reserved "AppDataDefault_PAD" (size = 0);
    }
    "_AppDataDefault_START" = "_lc_gb_AppDataDefault";
    "_AppDataDefault_END" = ("_lc_ge_AppDataDefault" == 0) ? 0 : "_lc_ge_AppDataDefault" - 1;
    "_AppDataDefault_LIMIT" = "_lc_ge_AppDataDefault";

    "_DataDefaultGroup_ALL_START" = "_AppDataDefault_START";
    "_DataDefaultGroup_ALL_END" = "_AppDataDefault_END";
    "_DataDefaultGroup_ALL_LIMIT" = "_AppDataDefault_LIMIT";
  }

  group RamCodeGroup_DSPR0_ROM_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:ApplRomArea)
  {
    group UpdRamCodeSection_DSPR0_ROM (ordered, contiguous, fill, align = 4)
    {
      section "UpdRamCodeSection_DSPR0_ROM_SEC" (fill, blocksize = 1, attributes = rx)
      {
        group (load_addr)
        {
          select "[.]text.RamCodeSection";
          select "[.]text.fbl_flio*";
          select "[.]text.fbl_diag*";
        }
      }
    }
    "_UpdRamCodeSection_DSPR0_ROM_START" = "_lc_gb_UpdRamCodeSection_DSPR0_ROM";
    "_UpdRamCodeSection_DSPR0_ROM_LIMIT" = "_lc_ge_UpdRamCodeSection_DSPR0_ROM";

  }

  group RamCodeGroup_DSPR0_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:DefaultRamArea_DSPR0)
  {
    group UpdRamCodeSection_DSPR0_ALIGN (align = 4)
    {
      reserved "UpdRamCodeSection_DSPR0_ALIGN" (size = 4);
    }
    group UpdRamCodeSection_DSPR0 (ordered, contiguous, fill, align = 1, copy)
    {
      /* Due to a Linker issue: 'COPY_TO_RAM' const groups cannot be created with inner output section */
      select "[.]text.RamCodeSection";
      select "[.]text.fbl_flio*";
      select "[.]text.fbl_diag*";
    }
    group UpdRamCodeSection_DSPR0_PAD (align = 4)
    {
      reserved "UpdRamCodeSection_DSPR0_PAD" (size = 0);
    }
    "_UpdRamCodeSection_DSPR0_START" = "_lc_gb_UpdRamCodeSection_DSPR0";
    "_UpdRamCodeSection_DSPR0_END" = ("_lc_ge_UpdRamCodeSection_DSPR0" == 0) ? 0 : "_lc_ge_UpdRamCodeSection_DSPR0" - 1;
    "_UpdRamCodeSection_DSPR0_LIMIT" = "_lc_ge_UpdRamCodeSection_DSPR0";

    "_RamCodeGroup_DSPR0_ALL_START" = "_UpdRamCodeSection_DSPR0_START";
    "_RamCodeGroup_DSPR0_ALL_END" = "_UpdRamCodeSection_DSPR0_END";
    "_RamCodeGroup_DSPR0_ALL_LIMIT" = "_UpdRamCodeSection_DSPR0_LIMIT";
  }

  group brsExcVect_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:ApplRom_ExceptionTable)
  {
    group brsExcVect (ordered, contiguous, fill)
    {
      section "brsExcVect_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]text.brsExcVect";
      }
    }
    "_brsExcVect_START" = "_lc_gb_brsExcVect";
    "_brsExcVect_END" = ("_lc_ge_brsExcVect" == 0) ? 0 : "_lc_ge_brsExcVect" - 1;
    "_brsExcVect_LIMIT" = "_lc_ge_brsExcVect";

    "_brsExcVect_ALL_START" = "_brsExcVect_START";
    "_brsExcVect_ALL_END" = "_brsExcVect_END";
    "_brsExcVect_ALL_LIMIT" = "_brsExcVect_LIMIT";
  }

  group SharedData_ReprogrammingData_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:RegionBlock_0_LMU0_ReprogrammingData)
  {
    group MagicFlag (ordered, contiguous, fill, align = 16)
    {
      section "MagicFlag_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]bss.MagicFlagSection";
      }
    }
    "_MagicFlag_START" = "_lc_gb_MagicFlag";
    "_MagicFlag_END" = ("_lc_ge_MagicFlag" == 0) ? 0 : "_lc_ge_MagicFlag" - 1;
    "_MagicFlag_LIMIT" = "_lc_ge_MagicFlag";

    group ProgConditions (ordered, contiguous, fill)
    {
      section "ProgConditions_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]bss.ProgConditionSection";
      }
    }
    "_ProgConditions_START" = "_lc_gb_ProgConditions";
    "_ProgConditions_END" = ("_lc_ge_ProgConditions" == 0) ? 0 : "_lc_ge_ProgConditions" - 1;
    "_ProgConditions_LIMIT" = "_lc_ge_ProgConditions";

    "_SharedData_ReprogrammingData_ALL_START" = "_MagicFlag_START";
    "_SharedData_ReprogrammingData_ALL_END" = "_ProgConditions_END";
    "_SharedData_ReprogrammingData_ALL_LIMIT" = "_ProgConditions_LIMIT";
  }

  group SharedData_vHsm_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:RegionBlock_0_LMU0_vHsm_Shared)
  {
    group vHsmIpcMemory (ordered, contiguous, fill, align = 16)
    {
      section "vHsmIpcMemory_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]bss.vHsmIpcMemory";
      }
    }
    "_vHsmIpcMemory_START" = "_lc_gb_vHsmIpcMemory";
    "_vHsmIpcMemory_END" = ("_lc_ge_vHsmIpcMemory" == 0) ? 0 : "_lc_ge_vHsmIpcMemory" - 1;
    "_vHsmIpcMemory_LIMIT" = "_lc_ge_vHsmIpcMemory";

    group vHsmGlobalRamBuffer (ordered, contiguous, fill, align = 16)
    {
      section "vHsmGlobalRamBuffer_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]bss.vHsmGlobalRamBuffer";
      }
    }
    "_vHsmGlobalRamBuffer_START" = "_lc_gb_vHsmGlobalRamBuffer";
    "_vHsmGlobalRamBuffer_END" = ("_lc_ge_vHsmGlobalRamBuffer" == 0) ? 0 : "_lc_ge_vHsmGlobalRamBuffer" - 1;
    "_vHsmGlobalRamBuffer_LIMIT" = "_lc_ge_vHsmGlobalRamBuffer";

    "_SharedData_vHsm_ALL_START" = "_vHsmIpcMemory_START";
    "_SharedData_vHsm_ALL_END" = "_vHsmGlobalRamBuffer_END";
    "_SharedData_vHsm_ALL_LIMIT" = "_vHsmGlobalRamBuffer_LIMIT";
  }

  group FlashDrvGroup_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:FlashDrvArea)
  {
    group FblFlashDrvSection (ordered, contiguous, fill, align = 16)
    {
      section "FblFlashDrvSection_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]bss.FblFlashDrvSection";
      }
    }
    "_FblFlashDrvSection_START" = "_lc_gb_FblFlashDrvSection";
    "_FblFlashDrvSection_END" = ("_lc_ge_FblFlashDrvSection" == 0) ? 0 : "_lc_ge_FblFlashDrvSection" - 1;
    "_FblFlashDrvSection_LIMIT" = "_lc_ge_FblFlashDrvSection";

    "_FlashDrvGroup_ALL_START" = "_FblFlashDrvSection_START";
    "_FlashDrvGroup_ALL_END" = "_FblFlashDrvSection_END";
    "_FlashDrvGroup_ALL_LIMIT" = "_FblFlashDrvSection_LIMIT";
  }

  group RomDefaultGroup_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:ApplRomArea)
  {
    group Upd_Rom (ordered, contiguous, fill)
    {
      section "Upd_Rom_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]rodata*";
        select "[.]text*";
        select "[.]zrodata*";
      }
    }
    "_Upd_Rom_START" = "_lc_gb_Upd_Rom";
    "_Upd_Rom_END" = ("_lc_ge_Upd_Rom" == 0) ? 0 : "_lc_ge_Upd_Rom" - 1;
    "_Upd_Rom_LIMIT" = "_lc_ge_Upd_Rom";

    "_RomDefaultGroup_ALL_START" = "_Upd_Rom_START";
    "_RomDefaultGroup_ALL_END" = "_Upd_Rom_END";
    "_RomDefaultGroup_ALL_LIMIT" = "_Upd_Rom_LIMIT";
  }

  group Ram_Bss_Zbss_Group_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:DefaultRamArea_DSPR0)
  {
    group bss (ordered, contiguous, fill, align = 16)
    {
      section "bss_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]bss*";
      }
    }
    group bss_PAD (align = 4)
    {
      reserved "bss_PAD" (size = 0);
    }
    "_bss_START" = "_lc_gb_bss";
    "_bss_END" = ("_lc_ge_bss" == 0) ? 0 : "_lc_ge_bss" - 1;
    "_bss_LIMIT" = "_lc_ge_bss";

    group zbss (ordered, contiguous, fill, align = 16)
    {
      section "zbss_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]zbss*";
      }
    }
    group zbss_PAD (align = 4)
    {
      reserved "zbss_PAD" (size = 0);
    }
    "_zbss_START" = "_lc_gb_zbss";
    "_zbss_END" = ("_lc_ge_zbss" == 0) ? 0 : "_lc_ge_zbss" - 1;
    "_zbss_LIMIT" = "_lc_ge_zbss";

    "_Ram_Bss_Zbss_Group_ALL_START" = "_bss_START";
    "_Ram_Bss_Zbss_Group_ALL_END" = "_zbss_END";
    "_Ram_Bss_Zbss_Group_ALL_LIMIT" = "_zbss_LIMIT";
  }

  group STACK_C0_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:DefaultRamArea_Stack)
  {
    group STACK_C0 (ordered, contiguous, fill, align = 4)
    {
      reserved "STACK_C0" (size = 16380);
    }
    "_STACK_C0_START" = "_lc_gb_STACK_C0";
    "_STACK_C0_END" = ("_lc_ge_STACK_C0" == 0) ? 0 : "_lc_ge_STACK_C0" - 1;
    "_STACK_C0_LIMIT" = "_lc_ge_STACK_C0";

    "_STACK_C0_ALL_START" = "_STACK_C0_START";
    "_STACK_C0_ALL_END" = "_STACK_C0_END";
    "_STACK_C0_ALL_LIMIT" = "_STACK_C0_LIMIT";
  }

  "_OS_EXCVEC_CORE0_CODE_START" = "brsStartupEntry";
  "_OS_INTVEC_CORE0_CODE_START" = "brsStartupEntry";

}


