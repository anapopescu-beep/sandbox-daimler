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

/**********************************************************************************************************************
 * CAUTION - DO NOT EDIT
 * -------------------------------------------------------------------------------------------------------------------
 * Never manually edit the following memory definitions in this file. Only change them in the vLinkGen configuration
 * (/MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenMemoryRegion/vLinkGenMemoryRegionBlock) and regenerate the files.
 *********************************************************************************************************************/
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
    size = 1024; /* 1024 Byte */
    map (dest=bus:local_bus, dest_offset = 0x70000000, size = 1024);
  }
  memory DefaultRamArea_DSPR0
  {
    mau = 8;
    type = ram;
    size = 97280; /* 95 KiB */
    map (dest=bus:local_bus, dest_offset = 0x70000400, size = 97280);
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
    size = 145600; /* 142 KiB */
    map (dest=bus:local_bus, dest_offset = 0xA0048340, size = 145600);
  }
  memory FblRom_SW_Versions
  {
    mau = 8;
    type = rom;
    size = 80; /* 80 Byte */
    map (dest=bus:local_bus, dest_offset = 0xA006BC60, size = 80);
  }
  memory FblRomReserved
  {
    mau = 8;
    type = rom;
    size = 848; /* 848 Byte */
    map (dest=bus:local_bus, dest_offset = 0xA006BCB0, size = 848);
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
  group BmHdrHeaderGroup_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:FblBmHdrHeader)
  {
    group FblBmHdrHeaderGroup (ordered, contiguous, fill)
    {
      section "FblBmHdrHeaderGroup_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]rodata.BmHdrHeaderSection";
      }
    }
    "_FblBmHdrHeaderGroup_START" = "_lc_gb_FblBmHdrHeaderGroup";
    "_FblBmHdrHeaderGroup_END" = ("_lc_ge_FblBmHdrHeaderGroup" == 0) ? 0 : "_lc_ge_FblBmHdrHeaderGroup" - 1;
    "_FblBmHdrHeaderGroup_LIMIT" = "_lc_ge_FblBmHdrHeaderGroup";

    "_BmHdrHeaderGroup_ALL_START" = "_FblBmHdrHeaderGroup_START";
    "_BmHdrHeaderGroup_ALL_END" = "_FblBmHdrHeaderGroup_END";
    "_BmHdrHeaderGroup_ALL_LIMIT" = "_FblBmHdrHeaderGroup_LIMIT";
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

  group FblHeaderGroup_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:FblHeader)
  {
    group FblHeaderSectionGroup (ordered, contiguous, fill)
    {
      section "FblHeaderSectionGroup_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]rodata.FblHeaderSection";
      }
    }
    "_FblHeaderSectionGroup_START" = "_lc_gb_FblHeaderSectionGroup";
    "_FblHeaderSectionGroup_END" = ("_lc_ge_FblHeaderSectionGroup" == 0) ? 0 : "_lc_ge_FblHeaderSectionGroup" - 1;
    "_FblHeaderSectionGroup_LIMIT" = "_lc_ge_FblHeaderSectionGroup";

    "_FblHeaderGroup_ALL_START" = "_FblHeaderSectionGroup_START";
    "_FblHeaderGroup_ALL_END" = "_FblHeaderSectionGroup_END";
    "_FblHeaderGroup_ALL_LIMIT" = "_FblHeaderSectionGroup_LIMIT";
  }

  group PresencePatternGroup_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:FblRomReserved)
  {
    group Fbl_PP (ordered, contiguous, fill)
    {
      reserved "Fbl_PP" (size = 0);
    }
    "_Fbl_PP_START" = "_lc_gb_Fbl_PP";
    "_Fbl_PP_END" = ("_lc_ge_Fbl_PP" == 0) ? 0 : "_lc_ge_Fbl_PP" - 1;
    "_Fbl_PP_LIMIT" = "_lc_ge_Fbl_PP";

    "_PresencePatternGroup_ALL_START" = "_Fbl_PP_START";
    "_PresencePatternGroup_ALL_END" = "_Fbl_PP_END";
    "_PresencePatternGroup_ALL_LIMIT" = "_Fbl_PP_LIMIT";
  }

  group RamConstGroup_ROM_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:FblRomArea)
  {
    group FblRamConstSection_ROM (ordered, contiguous, fill, align = 4)
    {
      section "FblRamConstSection_ROM_SEC" (fill, blocksize = 1, attributes = rx)
      {
        group (load_addr)
        {
          select "[.]rodata.RamConstSection";
        }
      }
    }
    "_FblRamConstSection_ROM_START" = "_lc_gb_FblRamConstSection_ROM";
    "_FblRamConstSection_ROM_LIMIT" = "_lc_ge_FblRamConstSection_ROM";

  }

  group RamConstGroup_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:DefaultRamArea_DSPR0)
  {
    group FblRamConstSection_ALIGN (align = 4)
    {
      reserved "FblRamConstSection_ALIGN" (size = 4);
    }
    group FblRamConstSection (ordered, contiguous, fill, align = 1, copy)
    {
      /* Due to a Linker issue: 'COPY_TO_RAM' const groups cannot be created with inner output section */
      select "[.]rodata.RamConstSection";
    }
    group FblRamConstSection_PAD (align = 4)
    {
      reserved "FblRamConstSection_PAD" (size = 0);
    }
    "_FblRamConstSection_START" = "_lc_gb_FblRamConstSection";
    "_FblRamConstSection_END" = ("_lc_ge_FblRamConstSection" == 0) ? 0 : "_lc_ge_FblRamConstSection" - 1;
    "_FblRamConstSection_LIMIT" = "_lc_ge_FblRamConstSection";

    "_RamConstGroup_ALL_START" = "_FblRamConstSection_START";
    "_RamConstGroup_ALL_END" = "_FblRamConstSection_END";
    "_RamConstGroup_ALL_LIMIT" = "_FblRamConstSection_LIMIT";
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

  group StartupGroup_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:FblRom_Startup)
  {
    group FblStartup (ordered, contiguous, fill)
    {
      section "FblStartup_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]text.brsResetLabel";
        select "[.]text.brsStartup";
        select "[.]text.brsStartupEntry";
      }
    }
    "_FblStartup_START" = "_lc_gb_FblStartup";
    "_FblStartup_END" = ("_lc_ge_FblStartup" == 0) ? 0 : "_lc_ge_FblStartup" - 1;
    "_FblStartup_LIMIT" = "_lc_ge_FblStartup";

    "_StartupGroup_ALL_START" = "_FblStartup_START";
    "_StartupGroup_ALL_END" = "_FblStartup_END";
    "_StartupGroup_ALL_LIMIT" = "_FblStartup_LIMIT";
  }

  group DataDefaultGroup_ROM_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:FblRomArea)
  {
    group FblDataDefault_ROM (ordered, contiguous, fill, align = 16)
    {
      section "FblDataDefault_ROM_SEC" (fill, blocksize = 2, attributes = rx)
      {
        group (load_addr)
        {
          select "[.]data*";
          select "[.]zdata*";
        }
      }
    }
    "_FblDataDefault_ROM_START" = "_lc_gb_FblDataDefault_ROM";
    "_FblDataDefault_ROM_LIMIT" = "_lc_ge_FblDataDefault_ROM";

  }

  group DataDefaultGroup_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:DefaultRamArea_DSPR0)
  {
    group FblDataDefault (ordered, contiguous, fill, align = 16)
    {
      section "FblDataDefault_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]data*";
        select "[.]zdata*";
      }
    }
    group FblDataDefault_PAD (align = 4)
    {
      reserved "FblDataDefault_PAD" (size = 0);
    }
    "_FblDataDefault_START" = "_lc_gb_FblDataDefault";
    "_FblDataDefault_END" = ("_lc_ge_FblDataDefault" == 0) ? 0 : "_lc_ge_FblDataDefault" - 1;
    "_FblDataDefault_LIMIT" = "_lc_ge_FblDataDefault";

    "_DataDefaultGroup_ALL_START" = "_FblDataDefault_START";
    "_DataDefaultGroup_ALL_END" = "_FblDataDefault_END";
    "_DataDefaultGroup_ALL_LIMIT" = "_FblDataDefault_LIMIT";
  }

  group RamCodeGroup_DSPR0_ROM_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:FblRomArea)
  {
    group FblRamCodeSection_ROM (ordered, contiguous, fill, align = 4)
    {
      section "FblRamCodeSection_ROM_SEC" (fill, blocksize = 1, attributes = rx)
      {
        group (load_addr)
        {
          select "[.]text.RamCodeSection";
        }
      }
    }
    "_FblRamCodeSection_ROM_START" = "_lc_gb_FblRamCodeSection_ROM";
    "_FblRamCodeSection_ROM_LIMIT" = "_lc_ge_FblRamCodeSection_ROM";

  }

  group RamCodeGroup_DSPR0_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:DefaultRamArea_DSPR0)
  {
    group FblRamCodeSection_ALIGN (align = 4)
    {
      reserved "FblRamCodeSection_ALIGN" (size = 4);
    }
    group FblRamCodeSection (ordered, contiguous, fill, align = 1, copy)
    {
      /* Due to a Linker issue: 'COPY_TO_RAM' const groups cannot be created with inner output section */
      select "[.]text.RamCodeSection";
    }
    group FblRamCodeSection_PAD (align = 4)
    {
      reserved "FblRamCodeSection_PAD" (size = 0);
    }
    "_FblRamCodeSection_START" = "_lc_gb_FblRamCodeSection";
    "_FblRamCodeSection_END" = ("_lc_ge_FblRamCodeSection" == 0) ? 0 : "_lc_ge_FblRamCodeSection" - 1;
    "_FblRamCodeSection_LIMIT" = "_lc_ge_FblRamCodeSection";

    "_RamCodeGroup_DSPR0_ALL_START" = "_FblRamCodeSection_START";
    "_RamCodeGroup_DSPR0_ALL_END" = "_FblRamCodeSection_END";
    "_RamCodeGroup_DSPR0_ALL_LIMIT" = "_FblRamCodeSection_LIMIT";
  }

  group brsExcVect_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:FblRom_ExceptionTable)
  {
    group brsExcVect (ordered, contiguous, fill, align = 256)
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

  group FblSW_Versions_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:FblRom_SW_Versions)
  {
    group FblSW_Versions (ordered, contiguous, fill)
    {
      section "FblSW_Versions_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]rodata.FblSW_Versions";
      }
    }
    "_FblSW_Versions_START" = "_lc_gb_FblSW_Versions";
    "_FblSW_Versions_END" = ("_lc_ge_FblSW_Versions" == 0) ? 0 : "_lc_ge_FblSW_Versions" - 1;
    "_FblSW_Versions_LIMIT" = "_lc_ge_FblSW_Versions";

    "_FblSW_Versions_ALL_START" = "_FblSW_Versions_START";
    "_FblSW_Versions_ALL_END" = "_FblSW_Versions_END";
    "_FblSW_Versions_ALL_LIMIT" = "_FblSW_Versions_LIMIT";
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

  group RomDefaultGroup_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:FblRomArea)
  {
    group Fbl_Rom (ordered, contiguous, fill)
    {
      section "Fbl_Rom_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]rodata*";
        select "[.]text*";
        select "[.]zrodata*";
      }
    }
    "_Fbl_Rom_START" = "_lc_gb_Fbl_Rom";
    "_Fbl_Rom_END" = ("_lc_ge_Fbl_Rom" == 0) ? 0 : "_lc_ge_Fbl_Rom" - 1;
    "_Fbl_Rom_LIMIT" = "_lc_ge_Fbl_Rom";

    "_RomDefaultGroup_ALL_START" = "_Fbl_Rom_START";
    "_RomDefaultGroup_ALL_END" = "_Fbl_Rom_END";
    "_RomDefaultGroup_ALL_LIMIT" = "_Fbl_Rom_LIMIT";
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
      reserved "STACK_C0" (size = 1024);
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


