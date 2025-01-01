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
    size = 12288; /* 12 KiB */
    map (dest=bus:local_bus, dest_offset = 0x70000000, size = 12288);
  }
  memory DefaultRamArea_DSPR0
  {
    mau = 8;
    type = ram;
    size = 86016; /* 84 KiB */
    map (dest=bus:local_bus, dest_offset = 0x70003000, size = 86016);
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
    size = 81120; /* 79 KiB */
    map (dest=bus:local_bus, dest_offset = 0xA0034320, size = 81120);
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
    size = 601088; /* 587 KiB */
    map (dest=bus:local_bus, dest_offset = 0xA006C400, size = 601088);
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
    size = 8064; /* 8 KiB */
    map (dest=bus:local_bus, dest_offset = 0xB0000000, size = 8064);
  }
  memory RegionBlock_0_LMU0_ReprogrammingData
  {
    mau = 8;
    type = ram;
    size = 128; /* 128 Byte */
    map (dest=bus:local_bus, dest_offset = 0xB0001F80, size = 128);
  }
}

section_layout mpe:vtc:linear
{
  group BMHD0_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:RegionBlock_0_BMHD0)
  {
    group BMHD0 (ordered, contiguous, fill)
    {
      section "BMHD0_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]rodata.BMHD0";
      }
    }
    "_BMHD0_START" = "_lc_gb_BMHD0";
    "_BMHD0_END" = ("_lc_ge_BMHD0" == 0) ? 0 : "_lc_ge_BMHD0" - 1;
    "_BMHD0_LIMIT" = "_lc_ge_BMHD0";

    "_BMHD0_ALL_START" = "_BMHD0_START";
    "_BMHD0_ALL_END" = "_BMHD0_END";
    "_BMHD0_ALL_LIMIT" = "_BMHD0_LIMIT";
  }

  group BmHeaderGroup_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:BmHeader)
  {
    group BmHeaderSectionGroup (ordered, contiguous, fill)
    {
      section "BmHeaderSectionGroup_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]rodata.BmHeaderSection";
      }
    }
    "_BmHeaderSectionGroup_START" = "_lc_gb_BmHeaderSectionGroup";
    "_BmHeaderSectionGroup_END" = ("_lc_ge_BmHeaderSectionGroup" == 0) ? 0 : "_lc_ge_BmHeaderSectionGroup" - 1;
    "_BmHeaderSectionGroup_LIMIT" = "_lc_ge_BmHeaderSectionGroup";

    "_BmHeaderGroup_ALL_START" = "_BmHeaderSectionGroup_START";
    "_BmHeaderGroup_ALL_END" = "_BmHeaderSectionGroup_END";
    "_BmHeaderGroup_ALL_LIMIT" = "_BmHeaderSectionGroup_LIMIT";
  }

  group CSA_CORE0_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:DefaultRamArea_DSPR0)
  {
    group CSA_CORE0 (ordered, contiguous, fill, align = 64)
    {
      reserved "CSA_CORE0" (size = 4096);
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

  group RamCodeConstGroup_ROM_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:BmRomArea)
  {
    group BmRamConstSection_ROM (ordered, contiguous, fill, align = 4)
    {
      section "BmRamConstSection_ROM_SEC" (fill, blocksize = 1, attributes = rx)
      {
        group (load_addr)
        {
          select "[.]text.RamCodeSection";
          select "[.]rodata.RamConstSection";
          select "[.]text.fbl_flio*";
          select "[.]text.fbl_diag*";
          select "[.]rodata.fbl_flio*";
          select "[.]rodata.fbl_diag*";
        }
      }
    }
    "_BmRamConstSection_ROM_START" = "_lc_gb_BmRamConstSection_ROM";
    "_BmRamConstSection_ROM_LIMIT" = "_lc_ge_BmRamConstSection_ROM";

  }

  group RamCodeConstGroup_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:DefaultRamArea_DSPR0)
  {
    group BmRamConstSection_ALIGN (align = 4)
    {
      reserved "BmRamConstSection_ALIGN" (size = 4);
    }
    group BmRamConstSection (ordered, contiguous, fill, align = 1, copy)
    {
      /* Due to a Linker issue: 'COPY_TO_RAM' const groups cannot be created with inner output section */
      select "[.]text.RamCodeSection";
      select "[.]rodata.RamConstSection";
      select "[.]text.fbl_flio*";
      select "[.]text.fbl_diag*";
      select "[.]rodata.fbl_flio*";
      select "[.]rodata.fbl_diag*";
    }
    group BmRamConstSection_PAD (align = 4)
    {
      reserved "BmRamConstSection_PAD" (size = 0);
    }
    "_BmRamConstSection_START" = "_lc_gb_BmRamConstSection";
    "_BmRamConstSection_END" = ("_lc_ge_BmRamConstSection" == 0) ? 0 : "_lc_ge_BmRamConstSection" - 1;
    "_BmRamConstSection_LIMIT" = "_lc_ge_BmRamConstSection";

    "_RamCodeConstGroup_ALL_START" = "_BmRamConstSection_START";
    "_RamCodeConstGroup_ALL_END" = "_BmRamConstSection_END";
    "_RamCodeConstGroup_ALL_LIMIT" = "_BmRamConstSection_LIMIT";
  }

  group RomStartupGroup_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:BmRom_Startup)
  {
    group BmStartup (ordered, contiguous, fill, align = 8)
    {
      section "BmStartup_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]text.brsResetLabel";
        select "[.]text.brsStartup";
        select "[.]text.brsStartupEntry";
      }
    }
    "_BmStartup_START" = "_lc_gb_BmStartup";
    "_BmStartup_END" = ("_lc_ge_BmStartup" == 0) ? 0 : "_lc_ge_BmStartup" - 1;
    "_BmStartup_LIMIT" = "_lc_ge_BmStartup";

    "_RomStartupGroup_ALL_START" = "_BmStartup_START";
    "_RomStartupGroup_ALL_END" = "_BmStartup_END";
    "_RomStartupGroup_ALL_LIMIT" = "_BmStartup_LIMIT";
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

  group DataDefaultGroup_ROM_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:BmRomArea)
  {
    group BmDataDefault_ROM (ordered, contiguous, fill, align = 16)
    {
      section "BmDataDefault_ROM_SEC" (fill, blocksize = 2, attributes = rx)
      {
        group (load_addr)
        {
          select "[.]data*";
          select "[.]zdata*";
        }
      }
    }
    "_BmDataDefault_ROM_START" = "_lc_gb_BmDataDefault_ROM";
    "_BmDataDefault_ROM_LIMIT" = "_lc_ge_BmDataDefault_ROM";

  }

  group DataDefaultGroup_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:DefaultRamArea_DSPR0)
  {
    group BmDataDefault (ordered, contiguous, fill, align = 16)
    {
      section "BmDataDefault_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]data*";
        select "[.]zdata*";
      }
    }
    group BmDataDefault_PAD (align = 4)
    {
      reserved "BmDataDefault_PAD" (size = 0);
    }
    "_BmDataDefault_START" = "_lc_gb_BmDataDefault";
    "_BmDataDefault_END" = ("_lc_ge_BmDataDefault" == 0) ? 0 : "_lc_ge_BmDataDefault" - 1;
    "_BmDataDefault_LIMIT" = "_lc_ge_BmDataDefault";

    "_DataDefaultGroup_ALL_START" = "_BmDataDefault_START";
    "_DataDefaultGroup_ALL_END" = "_BmDataDefault_END";
    "_DataDefaultGroup_ALL_LIMIT" = "_BmDataDefault_LIMIT";
  }

  group brsExcVect_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:BmRom_ExceptionTable)
  {
    group brsExcVect (ordered, contiguous, fill, align = 4)
    {
      section "brsExcVect_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]text.brsExcVect";
      }
    }
    group brsExcVect_PAD (align = 4)
    {
      reserved "brsExcVect_PAD" (size = 0);
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

  group RomDefaultGroup_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:BmRomArea)
  {
    group Bm_Rom (ordered, contiguous, fill)
    {
      section "Bm_Rom_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]text.RamCodeSectionEth";
        select "[.]rodata*";
        select "[.]text*";
        select "[.]zrodata*";
      }
    }
    "_Bm_Rom_START" = "_lc_gb_Bm_Rom";
    "_Bm_Rom_END" = ("_lc_ge_Bm_Rom" == 0) ? 0 : "_lc_ge_Bm_Rom" - 1;
    "_Bm_Rom_LIMIT" = "_lc_ge_Bm_Rom";

    "_RomDefaultGroup_ALL_START" = "_Bm_Rom_START";
    "_RomDefaultGroup_ALL_END" = "_Bm_Rom_END";
    "_RomDefaultGroup_ALL_LIMIT" = "_Bm_Rom_LIMIT";
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
      reserved "STACK_C0" (size = 2044);
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


