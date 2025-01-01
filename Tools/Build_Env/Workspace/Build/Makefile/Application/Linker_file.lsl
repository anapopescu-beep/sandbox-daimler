/**********************************************************************************************************************
 *  EXAMPLE CODE ONLY
 *  -------------------------------------------------------------------------------------------------------------------
 *  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW configuration.
 *  The Example Code has not passed any quality control measures and may be incomplete. The Example Code is neither
 *  intended nor qualified for use in series production. The Example Code as well as any of its modifications and/or
 *  implementations must be tested with diligent care and must comply with all quality requirements which are necessary
 *  according to the state of the art before their use.
 *********************************************************************************************************************/
/* COVERS: ARCH_SW_CIL_9997; ARCH_SW_CIL_9998; ARCH_SW_DIA_9997; ARCH_SW_DIA_9998; ARCH_SW_MMG_9997; ARCH_SW_MMG_9998; ARCH_SW_NVP_9997; ARCH_SW_NVP_9998; ARCH_SW_PAL_9997; ARCH_SW_PAL_9998; ARCH_SW_PMP_9997; ARCH_SW_PMP_9998; ARCH_SW_EOL_9997; ARCH_SW_EOL_9998; ARCH_SW_ATM_9997; ARCH_SW_ATM_9998; ARCH_SW_BMM_9997; ARCH_SW_BMM_9998; ARCH_SW_ERH_9997; ARCH_SW_ERH_9998 */

#define BM_HEADER_MAGIC_FLAG 				0xECE9654A
#define BM_HEADER_APPLICATION_START_ADDRESS 		0xA006C000
#define BM_HEADER_TARGET 				0x00000002
#define BM_HEADER_APPLICATION_JUMP_POINT		0xA006C000
#define BM_HEADER_APPLICATION_SIZE 			0x00093FFF
#define BM_HEADER_HEADER_ADDRESS			0xA006C0E0

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
  memory RegionBlock_0_DSPR_Core0
  {
    mau = 8;
    type = ram;
    size = 95488; /* 93 KiB */
    map (dest=bus:local_bus, dest_offset = 0x70000000, size = 95488);
  }
  memory RegionBlock_0_DSPR_NVP
  {
    mau = 8;
    type = ram;
    size = 2560; /* 2 KiB */
    map (dest=bus:local_bus, dest_offset = 0x70017500, size = 2560);
  }
  memory RegionBlock_0_PSPR_Core0
  {
    mau = 8;
    type = ram;
    size = 8192; /* 8 KiB */
    map (dest=bus:local_bus, dest_offset = 0x70100000, size = 8192);
  }
  memory RegionBlock_PFlash0_Cached_1
  {
    mau = 8;
    type = rom;
    size = 4096; /* 4 KiB */
    map (dest=bus:local_bus, dest_offset = 0x8006C200, size = 4096);
  }
  memory RegionBlock_Startup_Cached
  {
    mau = 8;
    type = rom;
    size = 32; /* 32 Byte */
    map (dest=bus:local_bus, dest_offset = 0x8006D200, size = 32);
  }
  memory RegionBlock_PFlash0_Cached_2
  {
    mau = 8;
    type = rom;
    size = 597504; /* 584 KiB */
    map (dest=bus:local_bus, dest_offset = 0x8006D220, size = 597504);
  }
  memory RegionBlock_PFlash0_Cached_NVP
  {
    mau = 8;
    type = rom;
    size = 2560; /* 2 KiB */
    map (dest=bus:local_bus, dest_offset = 0x800FF020, size = 2560);
  }
  memory RegionBlock_PFlash0_Cached_CALIBRATION
  {
    mau = 8;
    type = rom;
    size = 1024; /* 1024 Byte */
    map (dest=bus:local_bus, dest_offset = 0x800FFA20, size = 1024);
  }
  memory RegionBlock_PFlash0_Cached_SW_Versions
  {
    mau = 8;
    type = rom;
    size = 80; /* 80 Byte */
    map (dest=bus:local_bus, dest_offset = 0x800FFF00, size = 80);
  }
  memory ApplStartup
  {
    mau = 8;
    type = rom;
    size = 512; /* 512 Byte */
    map (dest=bus:local_bus, dest_offset = 0xA006C000, size = 512);
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
  group CSA_CORE0_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:RegionBlock_0_DSPR_Core0)
  {
    group CSA_CORE0 (ordered, contiguous, fill, align = 64)
    {
      reserved "CSA_CORE0" (size = 8192);
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

  group OS_EXCVEC_CORE0_CODE_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:RegionBlock_PFlash0_Cached_2)
  {
    group OS_EXCVEC_CORE0_CODE (ordered, contiguous, fill, align = 256)
    {
      section "OS_EXCVEC_CORE0_CODE_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]text.OS_EXCVEC_CORE0_CODE";
      }
    }
    group OS_EXCVEC_CORE0_CODE_PAD (align = 8)
    {
      reserved "OS_EXCVEC_CORE0_CODE_PAD" (size = 16);
    }
    "_OS_EXCVEC_CORE0_CODE_START" = "_lc_gb_OS_EXCVEC_CORE0_CODE";
    "_OS_EXCVEC_CORE0_CODE_END" = ("_lc_gb_OS_EXCVEC_CORE0_CODE_PAD" == 0) ? 0 : "_lc_gb_OS_EXCVEC_CORE0_CODE_PAD" - 1;
    "_OS_EXCVEC_CORE0_CODE_LIMIT" = "_lc_gb_OS_EXCVEC_CORE0_CODE_PAD";

    "_OS_EXCVEC_CORE0_CODE_ALL_START" = "_OS_EXCVEC_CORE0_CODE_START";
    "_OS_EXCVEC_CORE0_CODE_ALL_END" = "_OS_EXCVEC_CORE0_CODE_END";
    "_OS_EXCVEC_CORE0_CODE_ALL_LIMIT" = "_OS_EXCVEC_CORE0_CODE_LIMIT";
  }

  group OS_EXCVEC_CORE0_CONST_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:RegionBlock_PFlash0_Cached_2)
  {
    group OS_EXCVEC_CORE0_CONST (ordered, contiguous, fill, align = 256)
    {
      section "OS_EXCVEC_CORE0_CONST_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]rodata.OS_EXCVEC_CORE0_CONST";
      }
    }
    group OS_EXCVEC_CORE0_CONST_PAD (align = 8)
    {
      reserved "OS_EXCVEC_CORE0_CONST_PAD" (size = 16);
    }
    "_OS_EXCVEC_CORE0_CONST_START" = "_lc_gb_OS_EXCVEC_CORE0_CONST";
    "_OS_EXCVEC_CORE0_CONST_END" = ("_lc_gb_OS_EXCVEC_CORE0_CONST_PAD" == 0) ? 0 : "_lc_gb_OS_EXCVEC_CORE0_CONST_PAD" - 1;
    "_OS_EXCVEC_CORE0_CONST_LIMIT" = "_lc_gb_OS_EXCVEC_CORE0_CONST_PAD";

    "_OS_EXCVEC_CORE0_CONST_ALL_START" = "_OS_EXCVEC_CORE0_CONST_START";
    "_OS_EXCVEC_CORE0_CONST_ALL_END" = "_OS_EXCVEC_CORE0_CONST_END";
    "_OS_EXCVEC_CORE0_CONST_ALL_LIMIT" = "_OS_EXCVEC_CORE0_CONST_LIMIT";
  }

  group OS_INTVEC_CODE_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:RegionBlock_PFlash0_Cached_2)
  {
    group OS_INTVEC_CODE (ordered, contiguous, fill, align = 8192)
    {
      section "OS_INTVEC_CODE_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]text.OS_INTVEC_CODE";
      }
    }
    group OS_INTVEC_CODE_PAD (align = 8)
    {
      reserved "OS_INTVEC_CODE_PAD" (size = 16);
    }
    "_OS_INTVEC_CODE_START" = "_lc_gb_OS_INTVEC_CODE";
    "_OS_INTVEC_CODE_END" = ("_lc_gb_OS_INTVEC_CODE_PAD" == 0) ? 0 : "_lc_gb_OS_INTVEC_CODE_PAD" - 1;
    "_OS_INTVEC_CODE_LIMIT" = "_lc_gb_OS_INTVEC_CODE_PAD";

    "_OS_INTVEC_CODE_ALL_START" = "_OS_INTVEC_CODE_START";
    "_OS_INTVEC_CODE_ALL_END" = "_OS_INTVEC_CODE_END";
    "_OS_INTVEC_CODE_ALL_LIMIT" = "_OS_INTVEC_CODE_LIMIT";
  }

  group OS_INTVEC_CONST_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:RegionBlock_PFlash0_Cached_2)
  {
    group OS_INTVEC_CONST (ordered, contiguous, fill, align = 8192)
    {
      section "OS_INTVEC_CONST_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]rodata.OS_INTVEC_CONST";
      }
    }
    group OS_INTVEC_CONST_PAD (align = 8)
    {
      reserved "OS_INTVEC_CONST_PAD" (size = 16);
    }
    "_OS_INTVEC_CONST_START" = "_lc_gb_OS_INTVEC_CONST";
    "_OS_INTVEC_CONST_END" = ("_lc_gb_OS_INTVEC_CONST_PAD" == 0) ? 0 : "_lc_gb_OS_INTVEC_CONST_PAD" - 1;
    "_OS_INTVEC_CONST_LIMIT" = "_lc_gb_OS_INTVEC_CONST_PAD";

    "_OS_INTVEC_CONST_ALL_START" = "_OS_INTVEC_CONST_START";
    "_OS_INTVEC_CONST_ALL_END" = "_OS_INTVEC_CONST_END";
    "_OS_INTVEC_CONST_ALL_LIMIT" = "_OS_INTVEC_CONST_LIMIT";
  }

  group OS_INTVEC_CORE0_CODE_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:RegionBlock_PFlash0_Cached_2)
  {
    group OS_INTVEC_CORE0_CODE (ordered, contiguous, fill, align = 8192)
    {
      section "OS_INTVEC_CORE0_CODE_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]text.OS_INTVEC_CORE0_CODE";
      }
    }
    group OS_INTVEC_CORE0_CODE_PAD (align = 8)
    {
      reserved "OS_INTVEC_CORE0_CODE_PAD" (size = 16);
    }
    "_OS_INTVEC_CORE0_CODE_START" = "_lc_gb_OS_INTVEC_CORE0_CODE";
    "_OS_INTVEC_CORE0_CODE_END" = ("_lc_gb_OS_INTVEC_CORE0_CODE_PAD" == 0) ? 0 : "_lc_gb_OS_INTVEC_CORE0_CODE_PAD" - 1;
    "_OS_INTVEC_CORE0_CODE_LIMIT" = "_lc_gb_OS_INTVEC_CORE0_CODE_PAD";

    "_OS_INTVEC_CORE0_CODE_ALL_START" = "_OS_INTVEC_CORE0_CODE_START";
    "_OS_INTVEC_CORE0_CODE_ALL_END" = "_OS_INTVEC_CORE0_CODE_END";
    "_OS_INTVEC_CORE0_CODE_ALL_LIMIT" = "_OS_INTVEC_CORE0_CODE_LIMIT";
  }

  group OS_INTVEC_CORE0_CONST_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:RegionBlock_PFlash0_Cached_2)
  {
    group OS_INTVEC_CORE0_CONST (ordered, contiguous, fill, align = 8192)
    {
      section "OS_INTVEC_CORE0_CONST_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]rodata.OS_INTVEC_CORE0_CONST";
      }
    }
    group OS_INTVEC_CORE0_CONST_PAD (align = 8)
    {
      reserved "OS_INTVEC_CORE0_CONST_PAD" (size = 16);
    }
    "_OS_INTVEC_CORE0_CONST_START" = "_lc_gb_OS_INTVEC_CORE0_CONST";
    "_OS_INTVEC_CORE0_CONST_END" = ("_lc_gb_OS_INTVEC_CORE0_CONST_PAD" == 0) ? 0 : "_lc_gb_OS_INTVEC_CORE0_CONST_PAD" - 1;
    "_OS_INTVEC_CORE0_CONST_LIMIT" = "_lc_gb_OS_INTVEC_CORE0_CONST_PAD";

    "_OS_INTVEC_CORE0_CONST_ALL_START" = "_OS_INTVEC_CORE0_CONST_START";
    "_OS_INTVEC_CORE0_CONST_ALL_END" = "_OS_INTVEC_CORE0_CONST_END";
    "_OS_INTVEC_CORE0_CONST_ALL_LIMIT" = "_OS_INTVEC_CORE0_CONST_LIMIT";
  }

  group STACK_C0_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:RegionBlock_0_DSPR_Core0)
  {
    group STACK_C0 (ordered, contiguous, fill, align = 4)
    {
      reserved "STACK_C0" (size = 1024);
    }
    group STACK_C0_PAD (align = 4)
    {
      reserved "STACK_C0_PAD" (size = 0);
    }
    "_STACK_C0_START" = "_lc_gb_STACK_C0";
    "_STACK_C0_END" = ("_lc_ge_STACK_C0" == 0) ? 0 : "_lc_ge_STACK_C0" - 1;
    "_STACK_C0_LIMIT" = "_lc_ge_STACK_C0";

    "_STACK_C0_ALL_START" = "_STACK_C0_START";
    "_STACK_C0_ALL_END" = "_STACK_C0_END";
    "_STACK_C0_ALL_LIMIT" = "_STACK_C0_LIMIT";
  }

  group Startup_Code_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:RegionBlock_PFlash0_Cached_1)
  {
    group Startup_Code (ordered, contiguous, fill)
    {
      section "Startup_Code_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]text.brsStartup";
      }
    }
    "_Startup_Code_START" = "_lc_gb_Startup_Code";
    "_Startup_Code_END" = ("_lc_ge_Startup_Code" == 0) ? 0 : "_lc_ge_Startup_Code" - 1;
    "_Startup_Code_LIMIT" = "_lc_ge_Startup_Code";

    "_Startup_Code_ALL_START" = "_Startup_Code_START";
    "_Startup_Code_ALL_END" = "_Startup_Code_END";
    "_Startup_Code_ALL_LIMIT" = "_Startup_Code_LIMIT";
  }

  group Startup_Entry_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:ApplStartup)
  {
    group Startup_Entry (ordered, contiguous, fill)
    {
      section "Startup_Entry_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]text.brsStartupEntry";
      }
    }
    "_Startup_Entry_START" = "_lc_gb_Startup_Entry";
    "_Startup_Entry_END" = ("_lc_ge_Startup_Entry" == 0) ? 0 : "_lc_ge_Startup_Entry" - 1;
    "_Startup_Entry_LIMIT" = "_lc_ge_Startup_Entry";

    "_Startup_Entry_ALL_START" = "_Startup_Entry_START";
    "_Startup_Entry_ALL_END" = "_Startup_Entry_END";
    "_Startup_Entry_ALL_LIMIT" = "_Startup_Entry_LIMIT";
  }

   group App_bmHeader (ordered, contiguous, run_addr=BM_HEADER_HEADER_ADDRESS)
  {
	  struct "bmHeaderApplication"
	  {
		  BM_HEADER_MAGIC_FLAG	:4;
		  BM_HEADER_APPLICATION_START_ADDRESS	:4;
		  BM_HEADER_TARGET	:4;
		  BM_HEADER_APPLICATION_JUMP_POINT	:4;
		  BM_HEADER_APPLICATION_SIZE	:4;
		  BM_HEADER_HEADER_ADDRESS	:4;
	  }
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

  group NVP_CALIB_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:RegionBlock_PFlash0_Cached_CALIBRATION)
  {
    group NVP_CALIB (ordered, contiguous, fill)
    {
      section "NVP_CALIB_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]rodata.NVP_CALIB";
      }
    }
    "_NVP_CALIB_START" = "_lc_gb_NVP_CALIB";
    "_NVP_CALIB_END" = ("_lc_ge_NVP_CALIB" == 0) ? 0 : "_lc_ge_NVP_CALIB" - 1;
    "_NVP_CALIB_LIMIT" = "_lc_ge_NVP_CALIB";

    "_NVP_CALIB_ALL_START" = "_NVP_CALIB_START";
    "_NVP_CALIB_ALL_END" = "_NVP_CALIB_END";
    "_NVP_CALIB_ALL_LIMIT" = "_NVP_CALIB_LIMIT";
  }

  group NVP_CONST_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:RegionBlock_PFlash0_Cached_NVP)
  {
    group NVP_CONST (ordered, contiguous, fill, align = 16)
    {
      section "NVP_CONST_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]rodata.NVP_CONST";
      }
    }
    "_NVP_CONST_START" = "_lc_gb_NVP_CONST";
    "_NVP_CONST_END" = ("_lc_ge_NVP_CONST" == 0) ? 0 : "_lc_ge_NVP_CONST" - 1;
    "_NVP_CONST_LIMIT" = "_lc_ge_NVP_CONST";

    "_NVP_CONST_ALL_START" = "_NVP_CONST_START";
    "_NVP_CONST_ALL_END" = "_NVP_CONST_END";
    "_NVP_CONST_ALL_LIMIT" = "_NVP_CONST_LIMIT";
  }

  group NVP_RamData_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:RegionBlock_0_DSPR_NVP)
  {
    group NVP_GlobalRamBufffer (ordered, contiguous, fill, align = 16)
    {
      section "NVP_GlobalRamBufffer_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]bss.NVP_GlobalRamBufferSection";
      }
    }
    "_NVP_GlobalRamBufffer_START" = "_lc_gb_NVP_GlobalRamBufffer";
    "_NVP_GlobalRamBufffer_END" = ("_lc_ge_NVP_GlobalRamBufffer" == 0) ? 0 : "_lc_ge_NVP_GlobalRamBufffer" - 1;
    "_NVP_GlobalRamBufffer_LIMIT" = "_lc_ge_NVP_GlobalRamBufffer";

    "_NVP_RamData_ALL_START" = "_NVP_GlobalRamBufffer_START";
    "_NVP_RamData_ALL_END" = "_NVP_GlobalRamBufffer_END";
    "_NVP_RamData_ALL_LIMIT" = "_NVP_GlobalRamBufffer_LIMIT";
  }

  group OS_DATA_CORE0_VAR_ROM_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:RegionBlock_PFlash0_Cached_2)
  {
    group OS_DATA_CORE0_VAR_FAST_INIT_ROM (ordered, contiguous, fill, align = 16)
    {
      section "OS_DATA_CORE0_VAR_FAST_INIT_ROM_SEC" (fill, blocksize = 2, attributes = rx)
      {
        group (load_addr)
        {
          select "[.]zdata.OS_CORE0_VAR_FAST";
          select "[.]zdata.OS_CORE0_VAR_FAST_NOCACHE";
          select "[.]zdata.OS_SystemApplication_OsCore0_VAR_FAST";
          select "[.]zdata.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE";
          select "[.]zdata.OS_SystemApplication_OsCore0_VAR_FAST_SAVED_ZONE";
        }
      }
    }
    "_OS_DATA_CORE0_VAR_FAST_INIT_ROM_START" = "_lc_gb_OS_DATA_CORE0_VAR_FAST_INIT_ROM";
    "_OS_DATA_CORE0_VAR_FAST_INIT_ROM_LIMIT" = "_lc_ge_OS_DATA_CORE0_VAR_FAST_INIT_ROM";

    group OS_DATA_CORE0_VAR_INIT_ROM (ordered, contiguous, fill, align = 16)
    {
      section "OS_DATA_CORE0_VAR_INIT_ROM_SEC" (fill, blocksize = 2, attributes = rx)
      {
        group (load_addr)
        {
          select "[.]data.OS_CORE0_VAR";
          select "[.]data.OS_CORE0_VAR_NOCACHE";
          select "[.]data.OS_SystemApplication_OsCore0_VAR";
          select "[.]data.OS_SystemApplication_OsCore0_VAR_NOCACHE";
          select "[.]data.OS_SystemApplication_OsCore0_VAR_SAVED_ZONE";
        }
      }
    }
    "_OS_DATA_CORE0_VAR_INIT_ROM_START" = "_lc_gb_OS_DATA_CORE0_VAR_INIT_ROM";
    "_OS_DATA_CORE0_VAR_INIT_ROM_LIMIT" = "_lc_ge_OS_DATA_CORE0_VAR_INIT_ROM";

  }

  group OS_DATA_CORE0_VAR_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:RegionBlock_0_DSPR_Core0)
  {
    group OS_DATA_CORE0_VAR_FAST_INIT (ordered, contiguous, fill, align = 16)
    {
      section "OS_DATA_CORE0_VAR_FAST_INIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]zdata.OS_CORE0_VAR_FAST";
        select "[.]zdata.OS_CORE0_VAR_FAST_NOCACHE";
        select "[.]zdata.OS_SystemApplication_OsCore0_VAR_FAST";
        select "[.]zdata.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE";
        select "[.]zdata.OS_SystemApplication_OsCore0_VAR_FAST_SAVED_ZONE";
      }
    }
    group OS_DATA_CORE0_VAR_FAST_INIT_PAD (align = 4)
    {
      reserved "OS_DATA_CORE0_VAR_FAST_INIT_PAD" (size = 16);
    }
    "_OS_DATA_CORE0_VAR_FAST_INIT_START" = "_lc_gb_OS_DATA_CORE0_VAR_FAST_INIT";
    "_OS_DATA_CORE0_VAR_FAST_INIT_END" = ("_lc_gb_OS_DATA_CORE0_VAR_FAST_INIT_PAD" == 0) ? 0 : "_lc_gb_OS_DATA_CORE0_VAR_FAST_INIT_PAD" - 1;
    "_OS_DATA_CORE0_VAR_FAST_INIT_LIMIT" = "_lc_gb_OS_DATA_CORE0_VAR_FAST_INIT_PAD";

    group OS_DATA_CORE0_VAR_FAST_NOINIT (ordered, contiguous, fill, align = 16)
    {
      section "OS_DATA_CORE0_VAR_FAST_NOINIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]zbss.OS_CORE0_VAR_FAST_NOCACHE_NOINIT";
        select "[.]zbss.OS_CORE0_VAR_FAST_NOINIT";
        select "[.]zbss.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT";
        select "[.]zbss.OS_SystemApplication_OsCore0_VAR_FAST_NOINIT";
        select "[.]zbss.OS_SystemApplication_OsCore0_VAR_FAST_SAVED_ZONE_NOINIT";
      }
    }
    group OS_DATA_CORE0_VAR_FAST_NOINIT_PAD (align = 1)
    {
      reserved "OS_DATA_CORE0_VAR_FAST_NOINIT_PAD" (size = 16);
    }
    "_OS_DATA_CORE0_VAR_FAST_NOINIT_START" = "_lc_gb_OS_DATA_CORE0_VAR_FAST_NOINIT";
    "_OS_DATA_CORE0_VAR_FAST_NOINIT_END" = ("_lc_gb_OS_DATA_CORE0_VAR_FAST_NOINIT_PAD" == 0) ? 0 : "_lc_gb_OS_DATA_CORE0_VAR_FAST_NOINIT_PAD" - 1;
    "_OS_DATA_CORE0_VAR_FAST_NOINIT_LIMIT" = "_lc_gb_OS_DATA_CORE0_VAR_FAST_NOINIT_PAD";

    group OS_DATA_CORE0_VAR_FAST_ZERO_INIT (ordered, contiguous, fill, align = 16)
    {
      section "OS_DATA_CORE0_VAR_FAST_ZERO_INIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]*.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT";
        select "[.]*.OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT";
      }
    }
    group OS_DATA_CORE0_VAR_FAST_ZERO_INIT_PAD (align = 4)
    {
      reserved "OS_DATA_CORE0_VAR_FAST_ZERO_INIT_PAD" (size = 16);
    }
    "_OS_DATA_CORE0_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_DATA_CORE0_VAR_FAST_ZERO_INIT";
    "_OS_DATA_CORE0_VAR_FAST_ZERO_INIT_END" = ("_lc_gb_OS_DATA_CORE0_VAR_FAST_ZERO_INIT_PAD" == 0) ? 0 : "_lc_gb_OS_DATA_CORE0_VAR_FAST_ZERO_INIT_PAD" - 1;
    "_OS_DATA_CORE0_VAR_FAST_ZERO_INIT_LIMIT" = "_lc_gb_OS_DATA_CORE0_VAR_FAST_ZERO_INIT_PAD";

    group OS_DATA_CORE0_VAR_FAST_ZERO_INIT_bss (ordered, contiguous, fill, align = 16)
    {
      section "OS_DATA_CORE0_VAR_FAST_ZERO_INIT_bss_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]*.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_bss";
        select "[.]*.OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_bss";
      }
    }
    group OS_DATA_CORE0_VAR_FAST_ZERO_INIT_bss_PAD (align = 4)
    {
      reserved "OS_DATA_CORE0_VAR_FAST_ZERO_INIT_bss_PAD" (size = 16);
    }
    "_OS_DATA_CORE0_VAR_FAST_ZERO_INIT_bss_START" = "_lc_gb_OS_DATA_CORE0_VAR_FAST_ZERO_INIT_bss";
    "_OS_DATA_CORE0_VAR_FAST_ZERO_INIT_bss_END" = ("_lc_gb_OS_DATA_CORE0_VAR_FAST_ZERO_INIT_bss_PAD" == 0) ? 0 : "_lc_gb_OS_DATA_CORE0_VAR_FAST_ZERO_INIT_bss_PAD" - 1;
    "_OS_DATA_CORE0_VAR_FAST_ZERO_INIT_bss_LIMIT" = "_lc_gb_OS_DATA_CORE0_VAR_FAST_ZERO_INIT_bss_PAD";

    group OS_DATA_CORE0_VAR_INIT (ordered, contiguous, fill, align = 16)
    {
      section "OS_DATA_CORE0_VAR_INIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]data.OS_CORE0_VAR";
        select "[.]data.OS_CORE0_VAR_NOCACHE";
        select "[.]data.OS_SystemApplication_OsCore0_VAR";
        select "[.]data.OS_SystemApplication_OsCore0_VAR_NOCACHE";
        select "[.]data.OS_SystemApplication_OsCore0_VAR_SAVED_ZONE";
      }
    }
    group OS_DATA_CORE0_VAR_INIT_PAD (align = 4)
    {
      reserved "OS_DATA_CORE0_VAR_INIT_PAD" (size = 16);
    }
    "_OS_DATA_CORE0_VAR_INIT_START" = "_lc_gb_OS_DATA_CORE0_VAR_INIT";
    "_OS_DATA_CORE0_VAR_INIT_END" = ("_lc_gb_OS_DATA_CORE0_VAR_INIT_PAD" == 0) ? 0 : "_lc_gb_OS_DATA_CORE0_VAR_INIT_PAD" - 1;
    "_OS_DATA_CORE0_VAR_INIT_LIMIT" = "_lc_gb_OS_DATA_CORE0_VAR_INIT_PAD";

    group OS_DATA_CORE0_VAR_NOINIT (ordered, contiguous, fill, align = 16)
    {
      section "OS_DATA_CORE0_VAR_NOINIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]bss.OS_CORE0_VAR_NOCACHE_NOINIT";
        select "[.]bss.OS_CORE0_VAR_NOINIT";
        select "[.]bss.OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT";
        select "[.]bss.OS_SystemApplication_OsCore0_VAR_NOINIT";
        select "[.]bss.OS_SystemApplication_OsCore0_VAR_SAVED_ZONE_NOINIT";
      }
    }
    group OS_DATA_CORE0_VAR_NOINIT_PAD (align = 1)
    {
      reserved "OS_DATA_CORE0_VAR_NOINIT_PAD" (size = 16);
    }
    "_OS_DATA_CORE0_VAR_NOINIT_START" = "_lc_gb_OS_DATA_CORE0_VAR_NOINIT";
    "_OS_DATA_CORE0_VAR_NOINIT_END" = ("_lc_gb_OS_DATA_CORE0_VAR_NOINIT_PAD" == 0) ? 0 : "_lc_gb_OS_DATA_CORE0_VAR_NOINIT_PAD" - 1;
    "_OS_DATA_CORE0_VAR_NOINIT_LIMIT" = "_lc_gb_OS_DATA_CORE0_VAR_NOINIT_PAD";

    group OS_DATA_CORE0_VAR_ZERO_INIT (ordered, contiguous, fill, align = 16)
    {
      section "OS_DATA_CORE0_VAR_ZERO_INIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]*.OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT";
        select "[.]*.OS_SystemApplication_OsCore0_VAR_ZERO_INIT";
      }
    }
    group OS_DATA_CORE0_VAR_ZERO_INIT_PAD (align = 4)
    {
      reserved "OS_DATA_CORE0_VAR_ZERO_INIT_PAD" (size = 16);
    }
    "_OS_DATA_CORE0_VAR_ZERO_INIT_START" = "_lc_gb_OS_DATA_CORE0_VAR_ZERO_INIT";
    "_OS_DATA_CORE0_VAR_ZERO_INIT_END" = ("_lc_gb_OS_DATA_CORE0_VAR_ZERO_INIT_PAD" == 0) ? 0 : "_lc_gb_OS_DATA_CORE0_VAR_ZERO_INIT_PAD" - 1;
    "_OS_DATA_CORE0_VAR_ZERO_INIT_LIMIT" = "_lc_gb_OS_DATA_CORE0_VAR_ZERO_INIT_PAD";

    group OS_DATA_CORE0_VAR_ZERO_INIT_bss (ordered, contiguous, fill, align = 16)
    {
      section "OS_DATA_CORE0_VAR_ZERO_INIT_bss_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]*.OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_bss";
        select "[.]*.OS_SystemApplication_OsCore0_VAR_ZERO_INIT_bss";
      }
    }
    group OS_DATA_CORE0_VAR_ZERO_INIT_bss_PAD (align = 4)
    {
      reserved "OS_DATA_CORE0_VAR_ZERO_INIT_bss_PAD" (size = 16);
    }
    "_OS_DATA_CORE0_VAR_ZERO_INIT_bss_START" = "_lc_gb_OS_DATA_CORE0_VAR_ZERO_INIT_bss";
    "_OS_DATA_CORE0_VAR_ZERO_INIT_bss_END" = ("_lc_gb_OS_DATA_CORE0_VAR_ZERO_INIT_bss_PAD" == 0) ? 0 : "_lc_gb_OS_DATA_CORE0_VAR_ZERO_INIT_bss_PAD" - 1;
    "_OS_DATA_CORE0_VAR_ZERO_INIT_bss_LIMIT" = "_lc_gb_OS_DATA_CORE0_VAR_ZERO_INIT_bss_PAD";

    "_OS_DATA_CORE0_VAR_ALL_START" = "_OS_DATA_CORE0_VAR_FAST_INIT_START";
    "_OS_DATA_CORE0_VAR_ALL_END" = "_OS_DATA_CORE0_VAR_ZERO_INIT_bss_END";
    "_OS_DATA_CORE0_VAR_ALL_LIMIT" = "_OS_DATA_CORE0_VAR_ZERO_INIT_bss_LIMIT";
  }

  group OS_DATA_SHARED_VAR_ROM_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:RegionBlock_PFlash0_Cached_2)
  {
    group OS_DATA_SHARED_VAR_FAST_INIT_ROM (ordered, contiguous, fill, align = 16)
    {
      section "OS_DATA_SHARED_VAR_FAST_INIT_ROM_SEC" (fill, blocksize = 2, attributes = rx)
      {
        group (load_addr)
        {
          select "[.]zdata.OS_VAR_FAST_NOCACHE";
        }
      }
    }
    "_OS_DATA_SHARED_VAR_FAST_INIT_ROM_START" = "_lc_gb_OS_DATA_SHARED_VAR_FAST_INIT_ROM";
    "_OS_DATA_SHARED_VAR_FAST_INIT_ROM_LIMIT" = "_lc_ge_OS_DATA_SHARED_VAR_FAST_INIT_ROM";

    group OS_DATA_SHARED_VAR_INIT_ROM (ordered, contiguous, fill, align = 16)
    {
      section "OS_DATA_SHARED_VAR_INIT_ROM_SEC" (fill, blocksize = 2, attributes = rx)
      {
        group (load_addr)
        {
          select "[.]data.OS_VAR_NOCACHE";
        }
      }
    }
    "_OS_DATA_SHARED_VAR_INIT_ROM_START" = "_lc_gb_OS_DATA_SHARED_VAR_INIT_ROM";
    "_OS_DATA_SHARED_VAR_INIT_ROM_LIMIT" = "_lc_ge_OS_DATA_SHARED_VAR_INIT_ROM";

  }

  group OS_DATA_SHARED_VAR_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:RegionBlock_0_DSPR_Core0)
  {
    group OS_DATA_SHARED_VAR_FAST_INIT (ordered, contiguous, fill, align = 16)
    {
      section "OS_DATA_SHARED_VAR_FAST_INIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]zdata.OS_VAR_FAST_NOCACHE";
      }
    }
    group OS_DATA_SHARED_VAR_FAST_INIT_PAD (align = 4)
    {
      reserved "OS_DATA_SHARED_VAR_FAST_INIT_PAD" (size = 16);
    }
    "_OS_DATA_SHARED_VAR_FAST_INIT_START" = "_lc_gb_OS_DATA_SHARED_VAR_FAST_INIT";
    "_OS_DATA_SHARED_VAR_FAST_INIT_END" = ("_lc_gb_OS_DATA_SHARED_VAR_FAST_INIT_PAD" == 0) ? 0 : "_lc_gb_OS_DATA_SHARED_VAR_FAST_INIT_PAD" - 1;
    "_OS_DATA_SHARED_VAR_FAST_INIT_LIMIT" = "_lc_gb_OS_DATA_SHARED_VAR_FAST_INIT_PAD";

    group OS_DATA_SHARED_VAR_FAST_NOINIT (ordered, contiguous, fill, align = 16)
    {
      section "OS_DATA_SHARED_VAR_FAST_NOINIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]zbss.OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT";
        select "[.]zbss.OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT";
        select "[.]zbss.OS_PUBLIC_CORE0_VAR_FAST_NOINIT";
        select "[.]zbss.OS_VAR_FAST_NOCACHE_NOINIT";
      }
    }
    group OS_DATA_SHARED_VAR_FAST_NOINIT_PAD (align = 1)
    {
      reserved "OS_DATA_SHARED_VAR_FAST_NOINIT_PAD" (size = 16);
    }
    "_OS_DATA_SHARED_VAR_FAST_NOINIT_START" = "_lc_gb_OS_DATA_SHARED_VAR_FAST_NOINIT";
    "_OS_DATA_SHARED_VAR_FAST_NOINIT_END" = ("_lc_gb_OS_DATA_SHARED_VAR_FAST_NOINIT_PAD" == 0) ? 0 : "_lc_gb_OS_DATA_SHARED_VAR_FAST_NOINIT_PAD" - 1;
    "_OS_DATA_SHARED_VAR_FAST_NOINIT_LIMIT" = "_lc_gb_OS_DATA_SHARED_VAR_FAST_NOINIT_PAD";

    group OS_DATA_SHARED_VAR_INIT (ordered, contiguous, fill, align = 16)
    {
      section "OS_DATA_SHARED_VAR_INIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]data.OS_VAR_NOCACHE";
      }
    }
    group OS_DATA_SHARED_VAR_INIT_PAD (align = 4)
    {
      reserved "OS_DATA_SHARED_VAR_INIT_PAD" (size = 16);
    }
    "_OS_DATA_SHARED_VAR_INIT_START" = "_lc_gb_OS_DATA_SHARED_VAR_INIT";
    "_OS_DATA_SHARED_VAR_INIT_END" = ("_lc_gb_OS_DATA_SHARED_VAR_INIT_PAD" == 0) ? 0 : "_lc_gb_OS_DATA_SHARED_VAR_INIT_PAD" - 1;
    "_OS_DATA_SHARED_VAR_INIT_LIMIT" = "_lc_gb_OS_DATA_SHARED_VAR_INIT_PAD";

    group OS_DATA_SHARED_VAR_NOINIT (ordered, contiguous, fill, align = 16)
    {
      section "OS_DATA_SHARED_VAR_NOINIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]bss.OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT";
        select "[.]bss.OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT";
        select "[.]bss.OS_PUBLIC_CORE0_VAR_NOINIT";
        select "[.]bss.OS_VAR_NOCACHE_NOINIT";
      }
    }
    group OS_DATA_SHARED_VAR_NOINIT_PAD (align = 1)
    {
      reserved "OS_DATA_SHARED_VAR_NOINIT_PAD" (size = 16);
    }
    "_OS_DATA_SHARED_VAR_NOINIT_START" = "_lc_gb_OS_DATA_SHARED_VAR_NOINIT";
    "_OS_DATA_SHARED_VAR_NOINIT_END" = ("_lc_gb_OS_DATA_SHARED_VAR_NOINIT_PAD" == 0) ? 0 : "_lc_gb_OS_DATA_SHARED_VAR_NOINIT_PAD" - 1;
    "_OS_DATA_SHARED_VAR_NOINIT_LIMIT" = "_lc_gb_OS_DATA_SHARED_VAR_NOINIT_PAD";

    "_OS_DATA_SHARED_VAR_ALL_START" = "_OS_DATA_SHARED_VAR_FAST_INIT_START";
    "_OS_DATA_SHARED_VAR_ALL_END" = "_OS_DATA_SHARED_VAR_NOINIT_END";
    "_OS_DATA_SHARED_VAR_ALL_LIMIT" = "_OS_DATA_SHARED_VAR_NOINIT_LIMIT";
  }

  group OS_GLOBALSHARED_CONST_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:RegionBlock_PFlash0_Cached_2)
  {
    group OS_GLOBALSHARED_CONST (ordered, contiguous, fill)
    {
      section "OS_GLOBALSHARED_CONST_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]rodata.OS_GLOBALSHARED_CONST";
        select "[.]zrodata.OS_GLOBALSHARED_CONST_FAST";
      }
    }
    group OS_GLOBALSHARED_CONST_PAD (align = 1)
    {
      reserved "OS_GLOBALSHARED_CONST_PAD" (size = 16);
    }
    "_OS_GLOBALSHARED_CONST_START" = "_lc_gb_OS_GLOBALSHARED_CONST";
    "_OS_GLOBALSHARED_CONST_END" = ("_lc_gb_OS_GLOBALSHARED_CONST_PAD" == 0) ? 0 : "_lc_gb_OS_GLOBALSHARED_CONST_PAD" - 1;
    "_OS_GLOBALSHARED_CONST_LIMIT" = "_lc_gb_OS_GLOBALSHARED_CONST_PAD";

    "_OS_GLOBALSHARED_CONST_ALL_START" = "_OS_GLOBALSHARED_CONST_START";
    "_OS_GLOBALSHARED_CONST_ALL_END" = "_OS_GLOBALSHARED_CONST_END";
    "_OS_GLOBALSHARED_CONST_ALL_LIMIT" = "_OS_GLOBALSHARED_CONST_LIMIT";
  }

  group OS_GLOBALSHARED_VAR_ROM_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:RegionBlock_PFlash0_Cached_2)
  {
    group OS_GLOBALSHARED_VAR_FAST_INIT_ROM (ordered, contiguous, fill, align = 16)
    {
      section "OS_GLOBALSHARED_VAR_FAST_INIT_ROM_SEC" (fill, blocksize = 2, attributes = rx)
      {
        group (load_addr)
        {
          select "[.]zdata.OS_GLOBALSHARED_VAR_FAST";
          select "[.]zdata.OS_GLOBALSHARED_VAR_FAST_NOCACHE";
        }
      }
    }
    "_OS_GLOBALSHARED_VAR_FAST_INIT_ROM_START" = "_lc_gb_OS_GLOBALSHARED_VAR_FAST_INIT_ROM";
    "_OS_GLOBALSHARED_VAR_FAST_INIT_ROM_LIMIT" = "_lc_ge_OS_GLOBALSHARED_VAR_FAST_INIT_ROM";

    group OS_GLOBALSHARED_VAR_INIT_ROM (ordered, contiguous, fill, align = 16)
    {
      section "OS_GLOBALSHARED_VAR_INIT_ROM_SEC" (fill, blocksize = 2, attributes = rx)
      {
        group (load_addr)
        {
          select "[.]data.OS_GLOBALSHARED_VAR";
          select "[.]data.OS_GLOBALSHARED_VAR_NOCACHE";
        }
      }
    }
    "_OS_GLOBALSHARED_VAR_INIT_ROM_START" = "_lc_gb_OS_GLOBALSHARED_VAR_INIT_ROM";
    "_OS_GLOBALSHARED_VAR_INIT_ROM_LIMIT" = "_lc_ge_OS_GLOBALSHARED_VAR_INIT_ROM";

  }

  group OS_GLOBALSHARED_VAR_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:RegionBlock_0_DSPR_Core0)
  {
    group OS_GLOBALSHARED_VAR_FAST_INIT (ordered, contiguous, fill, align = 16)
    {
      section "OS_GLOBALSHARED_VAR_FAST_INIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]zdata.OS_GLOBALSHARED_VAR_FAST";
        select "[.]zdata.OS_GLOBALSHARED_VAR_FAST_NOCACHE";
      }
    }
    group OS_GLOBALSHARED_VAR_FAST_INIT_PAD (align = 4)
    {
      reserved "OS_GLOBALSHARED_VAR_FAST_INIT_PAD" (size = 16);
    }
    "_OS_GLOBALSHARED_VAR_FAST_INIT_START" = "_lc_gb_OS_GLOBALSHARED_VAR_FAST_INIT";
    "_OS_GLOBALSHARED_VAR_FAST_INIT_END" = ("_lc_gb_OS_GLOBALSHARED_VAR_FAST_INIT_PAD" == 0) ? 0 : "_lc_gb_OS_GLOBALSHARED_VAR_FAST_INIT_PAD" - 1;
    "_OS_GLOBALSHARED_VAR_FAST_INIT_LIMIT" = "_lc_gb_OS_GLOBALSHARED_VAR_FAST_INIT_PAD";

    group OS_GLOBALSHARED_VAR_FAST_NOINIT (ordered, contiguous, fill, align = 16)
    {
      section "OS_GLOBALSHARED_VAR_FAST_NOINIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]zbss.OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT";
        select "[.]zbss.OS_GLOBALSHARED_VAR_FAST_NOINIT";
      }
    }
    group OS_GLOBALSHARED_VAR_FAST_NOINIT_PAD (align = 1)
    {
      reserved "OS_GLOBALSHARED_VAR_FAST_NOINIT_PAD" (size = 16);
    }
    "_OS_GLOBALSHARED_VAR_FAST_NOINIT_START" = "_lc_gb_OS_GLOBALSHARED_VAR_FAST_NOINIT";
    "_OS_GLOBALSHARED_VAR_FAST_NOINIT_END" = ("_lc_gb_OS_GLOBALSHARED_VAR_FAST_NOINIT_PAD" == 0) ? 0 : "_lc_gb_OS_GLOBALSHARED_VAR_FAST_NOINIT_PAD" - 1;
    "_OS_GLOBALSHARED_VAR_FAST_NOINIT_LIMIT" = "_lc_gb_OS_GLOBALSHARED_VAR_FAST_NOINIT_PAD";

    group OS_GLOBALSHARED_VAR_FAST_ZERO_INIT (ordered, contiguous, fill, align = 16)
    {
      section "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]*.OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT";
        select "[.]*.OS_GLOBALSHARED_VAR_FAST_ZERO_INIT";
      }
    }
    group OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_PAD (align = 4)
    {
      reserved "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_PAD" (size = 16);
    }
    "_OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_GLOBALSHARED_VAR_FAST_ZERO_INIT";
    "_OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_END" = ("_lc_gb_OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_PAD" == 0) ? 0 : "_lc_gb_OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_PAD" - 1;
    "_OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_LIMIT" = "_lc_gb_OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_PAD";

    group OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss (ordered, contiguous, fill, align = 16)
    {
      section "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]*.OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT_bss";
        select "[.]*.OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss";
      }
    }
    group OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss_PAD (align = 4)
    {
      reserved "OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss_PAD" (size = 16);
    }
    "_OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss_START" = "_lc_gb_OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss";
    "_OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss_END" = ("_lc_gb_OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss_PAD" == 0) ? 0 : "_lc_gb_OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss_PAD" - 1;
    "_OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss_LIMIT" = "_lc_gb_OS_GLOBALSHARED_VAR_FAST_ZERO_INIT_bss_PAD";

    group OS_GLOBALSHARED_VAR_INIT (ordered, contiguous, fill, align = 16)
    {
      section "OS_GLOBALSHARED_VAR_INIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]data.OS_GLOBALSHARED_VAR";
        select "[.]data.OS_GLOBALSHARED_VAR_NOCACHE";
      }
    }
    group OS_GLOBALSHARED_VAR_INIT_PAD (align = 4)
    {
      reserved "OS_GLOBALSHARED_VAR_INIT_PAD" (size = 16);
    }
    "_OS_GLOBALSHARED_VAR_INIT_START" = "_lc_gb_OS_GLOBALSHARED_VAR_INIT";
    "_OS_GLOBALSHARED_VAR_INIT_END" = ("_lc_gb_OS_GLOBALSHARED_VAR_INIT_PAD" == 0) ? 0 : "_lc_gb_OS_GLOBALSHARED_VAR_INIT_PAD" - 1;
    "_OS_GLOBALSHARED_VAR_INIT_LIMIT" = "_lc_gb_OS_GLOBALSHARED_VAR_INIT_PAD";

    group OS_GLOBALSHARED_VAR_NOINIT (ordered, contiguous, fill, align = 16)
    {
      section "OS_GLOBALSHARED_VAR_NOINIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]bss.OS_GLOBALSHARED_VAR_NOCACHE_NOINIT";
        select "[.]bss.OS_GLOBALSHARED_VAR_NOINIT";
      }
    }
    group OS_GLOBALSHARED_VAR_NOINIT_PAD (align = 1)
    {
      reserved "OS_GLOBALSHARED_VAR_NOINIT_PAD" (size = 16);
    }
    "_OS_GLOBALSHARED_VAR_NOINIT_START" = "_lc_gb_OS_GLOBALSHARED_VAR_NOINIT";
    "_OS_GLOBALSHARED_VAR_NOINIT_END" = ("_lc_gb_OS_GLOBALSHARED_VAR_NOINIT_PAD" == 0) ? 0 : "_lc_gb_OS_GLOBALSHARED_VAR_NOINIT_PAD" - 1;
    "_OS_GLOBALSHARED_VAR_NOINIT_LIMIT" = "_lc_gb_OS_GLOBALSHARED_VAR_NOINIT_PAD";

    group OS_GLOBALSHARED_VAR_ZERO_INIT (ordered, contiguous, fill, align = 16)
    {
      section "OS_GLOBALSHARED_VAR_ZERO_INIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]*.OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT";
        select "[.]*.OS_GLOBALSHARED_VAR_ZERO_INIT";
      }
    }
    group OS_GLOBALSHARED_VAR_ZERO_INIT_PAD (align = 4)
    {
      reserved "OS_GLOBALSHARED_VAR_ZERO_INIT_PAD" (size = 16);
    }
    "_OS_GLOBALSHARED_VAR_ZERO_INIT_START" = "_lc_gb_OS_GLOBALSHARED_VAR_ZERO_INIT";
    "_OS_GLOBALSHARED_VAR_ZERO_INIT_END" = ("_lc_gb_OS_GLOBALSHARED_VAR_ZERO_INIT_PAD" == 0) ? 0 : "_lc_gb_OS_GLOBALSHARED_VAR_ZERO_INIT_PAD" - 1;
    "_OS_GLOBALSHARED_VAR_ZERO_INIT_LIMIT" = "_lc_gb_OS_GLOBALSHARED_VAR_ZERO_INIT_PAD";

    group OS_GLOBALSHARED_VAR_ZERO_INIT_bss (ordered, contiguous, fill, align = 16)
    {
      section "OS_GLOBALSHARED_VAR_ZERO_INIT_bss_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]*.OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_bss";
        select "[.]*.OS_GLOBALSHARED_VAR_ZERO_INIT_bss";
      }
    }
    group OS_GLOBALSHARED_VAR_ZERO_INIT_bss_PAD (align = 4)
    {
      reserved "OS_GLOBALSHARED_VAR_ZERO_INIT_bss_PAD" (size = 16);
    }
    "_OS_GLOBALSHARED_VAR_ZERO_INIT_bss_START" = "_lc_gb_OS_GLOBALSHARED_VAR_ZERO_INIT_bss";
    "_OS_GLOBALSHARED_VAR_ZERO_INIT_bss_END" = ("_lc_gb_OS_GLOBALSHARED_VAR_ZERO_INIT_bss_PAD" == 0) ? 0 : "_lc_gb_OS_GLOBALSHARED_VAR_ZERO_INIT_bss_PAD" - 1;
    "_OS_GLOBALSHARED_VAR_ZERO_INIT_bss_LIMIT" = "_lc_gb_OS_GLOBALSHARED_VAR_ZERO_INIT_bss_PAD";

    "_OS_GLOBALSHARED_VAR_ALL_START" = "_OS_GLOBALSHARED_VAR_FAST_INIT_START";
    "_OS_GLOBALSHARED_VAR_ALL_END" = "_OS_GLOBALSHARED_VAR_ZERO_INIT_bss_END";
    "_OS_GLOBALSHARED_VAR_ALL_LIMIT" = "_OS_GLOBALSHARED_VAR_ZERO_INIT_bss_LIMIT";
  }

  group OS_GLOBALSHARED_VAR_SAVED_ZONE_ROM_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:RegionBlock_PFlash0_Cached_1)
  {
    group OS_GLOBALSHARED_VAR_SAVED_ZONE_FAST_INIT_ROM (ordered, contiguous, fill, align = 16)
    {
      section "OS_GLOBALSHARED_VAR_SAVED_ZONE_FAST_INIT_ROM_SEC" (fill, blocksize = 2, attributes = rx)
      {
        group (load_addr)
        {
          select "[.]zdata.OS_GLOBALSHARED_VAR_FAST_SAVED_ZONE";
        }
      }
    }
    "_OS_GLOBALSHARED_VAR_SAVED_ZONE_FAST_INIT_ROM_START" = "_lc_gb_OS_GLOBALSHARED_VAR_SAVED_ZONE_FAST_INIT_ROM";
    "_OS_GLOBALSHARED_VAR_SAVED_ZONE_FAST_INIT_ROM_LIMIT" = "_lc_ge_OS_GLOBALSHARED_VAR_SAVED_ZONE_FAST_INIT_ROM";

    group OS_GLOBALSHARED_VAR_SAVED_ZONE_INIT_ROM (ordered, contiguous, fill, align = 16)
    {
      section "OS_GLOBALSHARED_VAR_SAVED_ZONE_INIT_ROM_SEC" (fill, blocksize = 2, attributes = rx)
      {
        group (load_addr)
        {
          select "[.]data.OS_GLOBALSHARED_VAR_SAVED_ZONE";
        }
      }
    }
    "_OS_GLOBALSHARED_VAR_SAVED_ZONE_INIT_ROM_START" = "_lc_gb_OS_GLOBALSHARED_VAR_SAVED_ZONE_INIT_ROM";
    "_OS_GLOBALSHARED_VAR_SAVED_ZONE_INIT_ROM_LIMIT" = "_lc_ge_OS_GLOBALSHARED_VAR_SAVED_ZONE_INIT_ROM";

  }

  group OS_GLOBALSHARED_VAR_SAVED_ZONE_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:RegionBlock_0_DSPR_Core0)
  {
    group OS_GLOBALSHARED_VAR_SAVED_ZONE_FAST_INIT (ordered, contiguous, fill, align = 16)
    {
      section "OS_GLOBALSHARED_VAR_SAVED_ZONE_FAST_INIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]zdata.OS_GLOBALSHARED_VAR_FAST_SAVED_ZONE";
      }
    }
    group OS_GLOBALSHARED_VAR_SAVED_ZONE_FAST_INIT_PAD (align = 4)
    {
      reserved "OS_GLOBALSHARED_VAR_SAVED_ZONE_FAST_INIT_PAD" (size = 16);
    }
    "_OS_GLOBALSHARED_VAR_SAVED_ZONE_FAST_INIT_START" = "_lc_gb_OS_GLOBALSHARED_VAR_SAVED_ZONE_FAST_INIT";
    "_OS_GLOBALSHARED_VAR_SAVED_ZONE_FAST_INIT_END" = ("_lc_gb_OS_GLOBALSHARED_VAR_SAVED_ZONE_FAST_INIT_PAD" == 0) ? 0 : "_lc_gb_OS_GLOBALSHARED_VAR_SAVED_ZONE_FAST_INIT_PAD" - 1;
    "_OS_GLOBALSHARED_VAR_SAVED_ZONE_FAST_INIT_LIMIT" = "_lc_gb_OS_GLOBALSHARED_VAR_SAVED_ZONE_FAST_INIT_PAD";

    group OS_GLOBALSHARED_VAR_SAVED_ZONE_FAST_NOINIT (ordered, contiguous, fill, align = 16)
    {
      section "OS_GLOBALSHARED_VAR_SAVED_ZONE_FAST_NOINIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]zbss.OS_GLOBALSHARED_VAR_FAST_SAVED_ZONE_NOINIT";
      }
    }
    group OS_GLOBALSHARED_VAR_SAVED_ZONE_FAST_NOINIT_PAD (align = 1)
    {
      reserved "OS_GLOBALSHARED_VAR_SAVED_ZONE_FAST_NOINIT_PAD" (size = 16);
    }
    "_OS_GLOBALSHARED_VAR_SAVED_ZONE_FAST_NOINIT_START" = "_lc_gb_OS_GLOBALSHARED_VAR_SAVED_ZONE_FAST_NOINIT";
    "_OS_GLOBALSHARED_VAR_SAVED_ZONE_FAST_NOINIT_END" = ("_lc_gb_OS_GLOBALSHARED_VAR_SAVED_ZONE_FAST_NOINIT_PAD" == 0) ? 0 : "_lc_gb_OS_GLOBALSHARED_VAR_SAVED_ZONE_FAST_NOINIT_PAD" - 1;
    "_OS_GLOBALSHARED_VAR_SAVED_ZONE_FAST_NOINIT_LIMIT" = "_lc_gb_OS_GLOBALSHARED_VAR_SAVED_ZONE_FAST_NOINIT_PAD";

    group OS_GLOBALSHARED_VAR_SAVED_ZONE_INIT (ordered, contiguous, fill, align = 16)
    {
      section "OS_GLOBALSHARED_VAR_SAVED_ZONE_INIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]data.OS_GLOBALSHARED_VAR_SAVED_ZONE";
      }
    }
    group OS_GLOBALSHARED_VAR_SAVED_ZONE_INIT_PAD (align = 4)
    {
      reserved "OS_GLOBALSHARED_VAR_SAVED_ZONE_INIT_PAD" (size = 16);
    }
    "_OS_GLOBALSHARED_VAR_SAVED_ZONE_INIT_START" = "_lc_gb_OS_GLOBALSHARED_VAR_SAVED_ZONE_INIT";
    "_OS_GLOBALSHARED_VAR_SAVED_ZONE_INIT_END" = ("_lc_gb_OS_GLOBALSHARED_VAR_SAVED_ZONE_INIT_PAD" == 0) ? 0 : "_lc_gb_OS_GLOBALSHARED_VAR_SAVED_ZONE_INIT_PAD" - 1;
    "_OS_GLOBALSHARED_VAR_SAVED_ZONE_INIT_LIMIT" = "_lc_gb_OS_GLOBALSHARED_VAR_SAVED_ZONE_INIT_PAD";

    group OS_GLOBALSHARED_VAR_SAVED_ZONE_NOINIT (ordered, contiguous, fill, align = 16)
    {
      section "OS_GLOBALSHARED_VAR_SAVED_ZONE_NOINIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]bss.OS_GLOBALSHARED_VAR_SAVED_ZONE_NOINIT";
      }
    }
    group OS_GLOBALSHARED_VAR_SAVED_ZONE_NOINIT_PAD (align = 1)
    {
      reserved "OS_GLOBALSHARED_VAR_SAVED_ZONE_NOINIT_PAD" (size = 16);
    }
    "_OS_GLOBALSHARED_VAR_SAVED_ZONE_NOINIT_START" = "_lc_gb_OS_GLOBALSHARED_VAR_SAVED_ZONE_NOINIT";
    "_OS_GLOBALSHARED_VAR_SAVED_ZONE_NOINIT_END" = ("_lc_gb_OS_GLOBALSHARED_VAR_SAVED_ZONE_NOINIT_PAD" == 0) ? 0 : "_lc_gb_OS_GLOBALSHARED_VAR_SAVED_ZONE_NOINIT_PAD" - 1;
    "_OS_GLOBALSHARED_VAR_SAVED_ZONE_NOINIT_LIMIT" = "_lc_gb_OS_GLOBALSHARED_VAR_SAVED_ZONE_NOINIT_PAD";

    "_OS_GLOBALSHARED_VAR_SAVED_ZONE_ALL_START" = "_OS_GLOBALSHARED_VAR_SAVED_ZONE_FAST_INIT_START";
    "_OS_GLOBALSHARED_VAR_SAVED_ZONE_ALL_END" = "_OS_GLOBALSHARED_VAR_SAVED_ZONE_NOINIT_END";
    "_OS_GLOBALSHARED_VAR_SAVED_ZONE_ALL_LIMIT" = "_OS_GLOBALSHARED_VAR_SAVED_ZONE_NOINIT_LIMIT";
  }

  group OS_OsApplication_Trusted_Core0_VAR_ROM_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:RegionBlock_PFlash0_Cached_1)
  {
    group OS_OsApplication_Trusted_Core0_VAR_FAST_INIT_ROM (ordered, contiguous, fill, align = 16)
    {
      section "OS_OsApplication_Trusted_Core0_VAR_FAST_INIT_ROM_SEC" (fill, blocksize = 2, attributes = rx)
      {
        group (load_addr)
        {
          select "[.]zdata.OS_OsApplication_Trusted_Core0_VAR_FAST";
          select "[.]zdata.OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE";
        }
      }
    }
    "_OS_OsApplication_Trusted_Core0_VAR_FAST_INIT_ROM_START" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_FAST_INIT_ROM";
    "_OS_OsApplication_Trusted_Core0_VAR_FAST_INIT_ROM_LIMIT" = "_lc_ge_OS_OsApplication_Trusted_Core0_VAR_FAST_INIT_ROM";

    group OS_OsApplication_Trusted_Core0_VAR_INIT_ROM (ordered, contiguous, fill, align = 16)
    {
      section "OS_OsApplication_Trusted_Core0_VAR_INIT_ROM_SEC" (fill, blocksize = 2, attributes = rx)
      {
        group (load_addr)
        {
          select "[.]data.OS_OsApplication_Trusted_Core0_VAR";
          select "[.]data.OS_OsApplication_Trusted_Core0_VAR_NOCACHE";
        }
      }
    }
    "_OS_OsApplication_Trusted_Core0_VAR_INIT_ROM_START" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_INIT_ROM";
    "_OS_OsApplication_Trusted_Core0_VAR_INIT_ROM_LIMIT" = "_lc_ge_OS_OsApplication_Trusted_Core0_VAR_INIT_ROM";

  }

  group OS_OsApplication_Trusted_Core0_VAR_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:RegionBlock_0_DSPR_Core0)
  {
    group OS_OsApplication_Trusted_Core0_VAR_FAST_INIT (ordered, contiguous, fill, align = 16)
    {
      section "OS_OsApplication_Trusted_Core0_VAR_FAST_INIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]zdata.OS_OsApplication_Trusted_Core0_VAR_FAST";
        select "[.]zdata.OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE";
      }
    }
    group OS_OsApplication_Trusted_Core0_VAR_FAST_INIT_PAD (align = 4)
    {
      reserved "OS_OsApplication_Trusted_Core0_VAR_FAST_INIT_PAD" (size = 16);
    }
    "_OS_OsApplication_Trusted_Core0_VAR_FAST_INIT_START" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_FAST_INIT";
    "_OS_OsApplication_Trusted_Core0_VAR_FAST_INIT_END" = ("_lc_gb_OS_OsApplication_Trusted_Core0_VAR_FAST_INIT_PAD" == 0) ? 0 : "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_FAST_INIT_PAD" - 1;
    "_OS_OsApplication_Trusted_Core0_VAR_FAST_INIT_LIMIT" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_FAST_INIT_PAD";

    group OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT (ordered, contiguous, fill, align = 16)
    {
      section "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]zbss.OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_NOINIT";
        select "[.]zbss.OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT";
      }
    }
    group OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_PAD (align = 1)
    {
      reserved "OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_PAD" (size = 16);
    }
    "_OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_START" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT";
    "_OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_END" = ("_lc_gb_OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_PAD" == 0) ? 0 : "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_PAD" - 1;
    "_OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_LIMIT" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_FAST_NOINIT_PAD";

    group OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT (ordered, contiguous, fill, align = 16)
    {
      section "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]*.OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_ZERO_INIT";
        select "[.]*.OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT";
      }
    }
    group OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_PAD (align = 4)
    {
      reserved "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_PAD" (size = 16);
    }
    "_OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT";
    "_OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_END" = ("_lc_gb_OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_PAD" == 0) ? 0 : "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_PAD" - 1;
    "_OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_LIMIT" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_PAD";

    group OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_bss (ordered, contiguous, fill, align = 16)
    {
      section "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_bss_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]*.OS_OsApplication_Trusted_Core0_VAR_FAST_NOCACHE_ZERO_INIT_bss";
        select "[.]*.OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_bss";
      }
    }
    group OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_bss_PAD (align = 4)
    {
      reserved "OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_bss_PAD" (size = 16);
    }
    "_OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_bss_START" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_bss";
    "_OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_bss_END" = ("_lc_gb_OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_bss_PAD" == 0) ? 0 : "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_bss_PAD" - 1;
    "_OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_bss_LIMIT" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_FAST_ZERO_INIT_bss_PAD";

    group OS_OsApplication_Trusted_Core0_VAR_INIT (ordered, contiguous, fill, align = 16)
    {
      section "OS_OsApplication_Trusted_Core0_VAR_INIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]data.OS_OsApplication_Trusted_Core0_VAR";
        select "[.]data.OS_OsApplication_Trusted_Core0_VAR_NOCACHE";
      }
    }
    group OS_OsApplication_Trusted_Core0_VAR_INIT_PAD (align = 4)
    {
      reserved "OS_OsApplication_Trusted_Core0_VAR_INIT_PAD" (size = 16);
    }
    "_OS_OsApplication_Trusted_Core0_VAR_INIT_START" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_INIT";
    "_OS_OsApplication_Trusted_Core0_VAR_INIT_END" = ("_lc_gb_OS_OsApplication_Trusted_Core0_VAR_INIT_PAD" == 0) ? 0 : "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_INIT_PAD" - 1;
    "_OS_OsApplication_Trusted_Core0_VAR_INIT_LIMIT" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_INIT_PAD";

    group OS_OsApplication_Trusted_Core0_VAR_NOINIT (ordered, contiguous, fill, align = 16)
    {
      section "OS_OsApplication_Trusted_Core0_VAR_NOINIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]bss.OS_OsApplication_Trusted_Core0_VAR_NOCACHE_NOINIT";
        select "[.]bss.OS_OsApplication_Trusted_Core0_VAR_NOINIT";
      }
    }
    group OS_OsApplication_Trusted_Core0_VAR_NOINIT_PAD (align = 1)
    {
      reserved "OS_OsApplication_Trusted_Core0_VAR_NOINIT_PAD" (size = 16);
    }
    "_OS_OsApplication_Trusted_Core0_VAR_NOINIT_START" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_NOINIT";
    "_OS_OsApplication_Trusted_Core0_VAR_NOINIT_END" = ("_lc_gb_OS_OsApplication_Trusted_Core0_VAR_NOINIT_PAD" == 0) ? 0 : "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_NOINIT_PAD" - 1;
    "_OS_OsApplication_Trusted_Core0_VAR_NOINIT_LIMIT" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_NOINIT_PAD";

    group OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT (ordered, contiguous, fill, align = 16)
    {
      section "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]*.OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT";
        select "[.]*.OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT";
      }
    }
    group OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_PAD (align = 4)
    {
      reserved "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_PAD" (size = 16);
    }
    "_OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_START" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT";
    "_OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_END" = ("_lc_gb_OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_PAD" == 0) ? 0 : "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_PAD" - 1;
    "_OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_LIMIT" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_PAD";

    group OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_bss (ordered, contiguous, fill, align = 16)
    {
      section "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_bss_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]*.OS_OsApplication_Trusted_Core0_VAR_NOCACHE_ZERO_INIT_bss";
        select "[.]*.OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_bss";
      }
    }
    group OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_bss_PAD (align = 4)
    {
      reserved "OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_bss_PAD" (size = 16);
    }
    "_OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_bss_START" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_bss";
    "_OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_bss_END" = ("_lc_gb_OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_bss_PAD" == 0) ? 0 : "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_bss_PAD" - 1;
    "_OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_bss_LIMIT" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_bss_PAD";

    "_OS_OsApplication_Trusted_Core0_VAR_ALL_START" = "_OS_OsApplication_Trusted_Core0_VAR_FAST_INIT_START";
    "_OS_OsApplication_Trusted_Core0_VAR_ALL_END" = "_OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_bss_END";
    "_OS_OsApplication_Trusted_Core0_VAR_ALL_LIMIT" = "_OS_OsApplication_Trusted_Core0_VAR_ZERO_INIT_bss_LIMIT";
  }

  group OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_ROM_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:RegionBlock_PFlash0_Cached_1)
  {
    group OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_FAST_INIT_ROM (ordered, contiguous, fill, align = 16)
    {
      section "OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_FAST_INIT_ROM_SEC" (fill, blocksize = 2, attributes = rx)
      {
        group (load_addr)
        {
          select "[.]zdata.OS_OsApplication_Trusted_Core0_VAR_FAST_SAVED_ZONE";
        }
      }
    }
    "_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_FAST_INIT_ROM_START" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_FAST_INIT_ROM";
    "_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_FAST_INIT_ROM_LIMIT" = "_lc_ge_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_FAST_INIT_ROM";

    group OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_INIT_ROM (ordered, contiguous, fill, align = 16)
    {
      section "OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_INIT_ROM_SEC" (fill, blocksize = 2, attributes = rx)
      {
        group (load_addr)
        {
          select "[.]data.OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE";
        }
      }
    }
    "_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_INIT_ROM_START" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_INIT_ROM";
    "_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_INIT_ROM_LIMIT" = "_lc_ge_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_INIT_ROM";

  }

  group OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:RegionBlock_0_DSPR_Core0)
  {
    group OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_FAST_INIT (ordered, contiguous, fill, align = 16)
    {
      section "OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_FAST_INIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]zdata.OS_OsApplication_Trusted_Core0_VAR_FAST_SAVED_ZONE";
      }
    }
    group OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_FAST_INIT_PAD (align = 4)
    {
      reserved "OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_FAST_INIT_PAD" (size = 16);
    }
    "_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_FAST_INIT_START" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_FAST_INIT";
    "_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_FAST_INIT_END" = ("_lc_gb_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_FAST_INIT_PAD" == 0) ? 0 : "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_FAST_INIT_PAD" - 1;
    "_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_FAST_INIT_LIMIT" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_FAST_INIT_PAD";

    group OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_FAST_NOINIT (ordered, contiguous, fill, align = 16)
    {
      section "OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_FAST_NOINIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]zbss.OS_OsApplication_Trusted_Core0_VAR_FAST_SAVED_ZONE_NOINIT";
      }
    }
    group OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_FAST_NOINIT_PAD (align = 1)
    {
      reserved "OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_FAST_NOINIT_PAD" (size = 16);
    }
    "_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_FAST_NOINIT_START" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_FAST_NOINIT";
    "_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_FAST_NOINIT_END" = ("_lc_gb_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_FAST_NOINIT_PAD" == 0) ? 0 : "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_FAST_NOINIT_PAD" - 1;
    "_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_FAST_NOINIT_LIMIT" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_FAST_NOINIT_PAD";

    group OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_INIT (ordered, contiguous, fill, align = 16)
    {
      section "OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_INIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]data.OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE";
      }
    }
    group OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_INIT_PAD (align = 4)
    {
      reserved "OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_INIT_PAD" (size = 16);
    }
    "_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_INIT_START" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_INIT";
    "_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_INIT_END" = ("_lc_gb_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_INIT_PAD" == 0) ? 0 : "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_INIT_PAD" - 1;
    "_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_INIT_LIMIT" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_INIT_PAD";

    group OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_NOINIT (ordered, contiguous, fill, align = 16)
    {
      section "OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_NOINIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]bss.OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_NOINIT";
      }
    }
    group OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_NOINIT_PAD (align = 1)
    {
      reserved "OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_NOINIT_PAD" (size = 16);
    }
    "_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_NOINIT_START" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_NOINIT";
    "_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_NOINIT_END" = ("_lc_gb_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_NOINIT_PAD" == 0) ? 0 : "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_NOINIT_PAD" - 1;
    "_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_NOINIT_LIMIT" = "_lc_gb_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_NOINIT_PAD";

    "_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_ALL_START" = "_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_FAST_INIT_START";
    "_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_ALL_END" = "_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_NOINIT_END";
    "_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_ALL_LIMIT" = "_OS_OsApplication_Trusted_Core0_VAR_SAVED_ZONE_NOINIT_LIMIT";
  }

  group OS_STACKS_CORE0_VAR_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:RegionBlock_0_DSPR_Core0)
  {
    group OS_STACKS_CORE0_VAR_NOINIT (ordered, contiguous, fill, align = 16)
    {
      section "OS_STACKS_CORE0_VAR_NOINIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]bss.OS_STACK_APPLTASK_CORE0_HIGHPRIO_VAR_NOINIT";
        select "[.]bss.OS_STACK_APPLTASK_CORE0_LOWPRIO_VAR_NOINIT";
        select "[.]bss.OS_STACK_BSWTASK_CORE0_HIGHPRIO_VAR_NOINIT";
        select "[.]bss.OS_STACK_BSWTASK_CORE0_LOWPRIO_VAR_NOINIT";
        select "[.]bss.OS_STACK_OSCORE0_ERROR_VAR_NOINIT";
        select "[.]bss.OS_STACK_OSCORE0_INIT_VAR_NOINIT";
        select "[.]bss.OS_STACK_OSCORE0_ISR_CORE_VAR_NOINIT";
        select "[.]bss.OS_STACK_OSCORE0_KERNEL_VAR_NOINIT";
        select "[.]bss.OS_STACK_OSCORE0_SHUTDOWN_VAR_NOINIT";
        select "[.]bss.OS_STACK_OSCORE0_TASK_PRIO0_VAR_NOINIT";
        select "[.]bss.OS_STACK_OSCORE0_TASK_PRIO100_VAR_NOINIT";
        select "[.]bss.OS_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT";
        select "[.]bss.OS_STACK_OSCORE0_TASK_PRIO5_VAR_NOINIT";
        select "[.]bss.OS_STACK_OSCORE0_TASK_PRIO90_VAR_NOINIT";
        select "[.]bss.OS_STACK_OSCORE0_TASK_PRIO99_VAR_NOINIT";
        select "[.]bss.OS_STACK_OSTASK_ALV_BELTFUNCTIONALGO_VAR_NOINIT";
      }
    }
    group OS_STACKS_CORE0_VAR_NOINIT_PAD (align = 1)
    {
      reserved "OS_STACKS_CORE0_VAR_NOINIT_PAD" (size = 16);
    }
    "_OS_STACKS_CORE0_VAR_NOINIT_START" = "_lc_gb_OS_STACKS_CORE0_VAR_NOINIT";
    "_OS_STACKS_CORE0_VAR_NOINIT_END" = ("_lc_gb_OS_STACKS_CORE0_VAR_NOINIT_PAD" == 0) ? 0 : "_lc_gb_OS_STACKS_CORE0_VAR_NOINIT_PAD" - 1;
    "_OS_STACKS_CORE0_VAR_NOINIT_LIMIT" = "_lc_gb_OS_STACKS_CORE0_VAR_NOINIT_PAD";

    "_OS_STACKS_CORE0_VAR_ALL_START" = "_OS_STACKS_CORE0_VAR_NOINIT_START";
    "_OS_STACKS_CORE0_VAR_ALL_END" = "_OS_STACKS_CORE0_VAR_NOINIT_END";
    "_OS_STACKS_CORE0_VAR_ALL_LIMIT" = "_OS_STACKS_CORE0_VAR_NOINIT_LIMIT";
  }

  group OS_USER_CODE_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:RegionBlock_PFlash0_Cached_2)
  {
    group OS_USER_CODE (ordered, contiguous, fill)
    {
      section "OS_USER_CODE_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]text.OS_ApplBackgroundTask_Core0_CODE";
        select "[.]text.OS_ApplInitTask_Core0_CODE";
        select "[.]text.OS_ApplTask_Core0_HighPrio_CODE";
        select "[.]text.OS_ApplTask_Core0_LowPrio_CODE";
        select "[.]text.OS_BackgroundTask_Core0_CODE";
        select "[.]text.OS_BswTask_Core0_HighPrio_CODE";
        select "[.]text.OS_BswTask_Core0_LowPrio_CODE";
        select "[.]text.OS_CanIsr_1_CODE";
        select "[.]text.OS_Default_Init_Task_CODE";
        select "[.]text.OS_Default_Init_Task_Trusted_CODE";
        select "[.]text.OS_ERRORHOOK_CODE";
        select "[.]text.OS_OsTask_ALV_BeltFunctionAlgo_CODE";
        select "[.]text.OS_PRETASKHOOK_CODE";
        select "[.]text.OS_RCM_PFlashEccFailure_Notification_CODE";
        select "[.]text.OS_RCM_SRamEccFailure_Notification_CODE";
        select "[.]text.OS_SHUTDOWNHOOK_CODE";
        select "[.]text.OS_vHsmResponseIsr_CODE";
      }
    }
    group OS_USER_CODE_PAD (align = 1)
    {
      reserved "OS_USER_CODE_PAD" (size = 16);
    }
    "_OS_USER_CODE_START" = "_lc_gb_OS_USER_CODE";
    "_OS_USER_CODE_END" = ("_lc_gb_OS_USER_CODE_PAD" == 0) ? 0 : "_lc_gb_OS_USER_CODE_PAD" - 1;
    "_OS_USER_CODE_LIMIT" = "_lc_gb_OS_USER_CODE_PAD";

    "_OS_USER_CODE_ALL_START" = "_OS_USER_CODE_START";
    "_OS_USER_CODE_ALL_END" = "_OS_USER_CODE_END";
    "_OS_USER_CODE_ALL_LIMIT" = "_OS_USER_CODE_LIMIT";
  }

  group OS_USER_CONST_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:RegionBlock_PFlash0_Cached_2)
  {
    group OS_USER_CONST (ordered, contiguous, fill)
    {
      section "OS_USER_CONST_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]rodata.OS_OsApplication_Trusted_Core0_CONST";
        select "[.]zrodata.OS_OsApplication_Trusted_Core0_CONST_FAST";
      }
    }
    group OS_USER_CONST_PAD (align = 1)
    {
      reserved "OS_USER_CONST_PAD" (size = 16);
    }
    "_OS_USER_CONST_START" = "_lc_gb_OS_USER_CONST";
    "_OS_USER_CONST_END" = ("_lc_gb_OS_USER_CONST_PAD" == 0) ? 0 : "_lc_gb_OS_USER_CONST_PAD" - 1;
    "_OS_USER_CONST_LIMIT" = "_lc_gb_OS_USER_CONST_PAD";

    "_OS_USER_CONST_ALL_START" = "_OS_USER_CONST_START";
    "_OS_USER_CONST_ALL_END" = "_OS_USER_CONST_END";
    "_OS_USER_CONST_ALL_LIMIT" = "_OS_USER_CONST_LIMIT";
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

    group ResetNotificationSection (ordered, contiguous, fill)
    {
      section "ResetNotificationSection_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]bss.ResetNotificationSection";
      }
    }
    "_ResetNotificationSection_START" = "_lc_gb_ResetNotificationSection";
    "_ResetNotificationSection_END" = ("_lc_ge_ResetNotificationSection" == 0) ? 0 : "_lc_ge_ResetNotificationSection" - 1;
    "_ResetNotificationSection_LIMIT" = "_lc_ge_ResetNotificationSection";

    "_SharedData_ReprogrammingData_ALL_START" = "_MagicFlag_START";
    "_SharedData_ReprogrammingData_ALL_END" = "_ResetNotificationSection_END";
    "_SharedData_ReprogrammingData_ALL_LIMIT" = "_ResetNotificationSection_LIMIT";
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

  group SW_Versions_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:RegionBlock_PFlash0_Cached_SW_Versions)
  {
    group SW_Versions (ordered, contiguous, fill)
    {
      section "SW_Versions_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]rodata.SW_Versions";
      }
    }
    "_SW_Versions_START" = "_lc_gb_SW_Versions";
    "_SW_Versions_END" = ("_lc_ge_SW_Versions" == 0) ? 0 : "_lc_ge_SW_Versions" - 1;
    "_SW_Versions_LIMIT" = "_lc_ge_SW_Versions";

    "_SW_Versions_ALL_START" = "_SW_Versions_START";
    "_SW_Versions_ALL_END" = "_SW_Versions_END";
    "_SW_Versions_ALL_LIMIT" = "_SW_Versions_LIMIT";
  }

  group OS_CODE_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:RegionBlock_PFlash0_Cached_2)
  {
    group OS_CODE (ordered, contiguous, fill)
    {
      section "OS_CODE_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]text.OS_CODE";
        select "[.]text.OS_OS_COREINITHOOK_CODE";
      }
    }
    group OS_CODE_PAD (align = 1)
    {
      reserved "OS_CODE_PAD" (size = 16);
    }
    "_OS_CODE_START" = "_lc_gb_OS_CODE";
    "_OS_CODE_END" = ("_lc_gb_OS_CODE_PAD" == 0) ? 0 : "_lc_gb_OS_CODE_PAD" - 1;
    "_OS_CODE_LIMIT" = "_lc_gb_OS_CODE_PAD";

    "_OS_CODE_ALL_START" = "_OS_CODE_START";
    "_OS_CODE_ALL_END" = "_OS_CODE_END";
    "_OS_CODE_ALL_LIMIT" = "_OS_CODE_LIMIT";
  }

  group OS_CONST_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:RegionBlock_PFlash0_Cached_2)
  {
    group OS_CONST (ordered, contiguous, fill)
    {
      section "OS_CONST_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]rodata.OS_CONST";
        select "[.]zrodata.OS_CONST_FAST";
        select "[.]rodata.OS_CORE0_CONST";
        select "[.]zrodata.OS_CORE0_CONST_FAST";
        select "[.]rodata.OS_SystemApplication_OsCore0_CONST";
        select "[.]zrodata.OS_SystemApplication_OsCore0_CONST_FAST";
      }
    }
    group OS_CONST_PAD (align = 1)
    {
      reserved "OS_CONST_PAD" (size = 16);
    }
    "_OS_CONST_START" = "_lc_gb_OS_CONST";
    "_OS_CONST_END" = ("_lc_gb_OS_CONST_PAD" == 0) ? 0 : "_lc_gb_OS_CONST_PAD" - 1;
    "_OS_CONST_LIMIT" = "_lc_gb_OS_CONST_PAD";

    "_OS_CONST_ALL_START" = "_OS_CONST_START";
    "_OS_CONST_ALL_END" = "_OS_CONST_END";
    "_OS_CONST_ALL_LIMIT" = "_OS_CONST_LIMIT";
  }

  group Const_Default_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:RegionBlock_PFlash0_Cached_2)
  {
    group rodata (ordered, contiguous, fill)
    {
      section "rodata_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]rodata*";
      }
    }
    "_rodata_START" = "_lc_gb_rodata";
    "_rodata_END" = ("_lc_ge_rodata" == 0) ? 0 : "_lc_ge_rodata" - 1;
    "_rodata_LIMIT" = "_lc_ge_rodata";

    group text (ordered, contiguous, fill)
    {
      section "text_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]text*";
      }
    }
    "_text_START" = "_lc_gb_text";
    "_text_END" = ("_lc_ge_text" == 0) ? 0 : "_lc_ge_text" - 1;
    "_text_LIMIT" = "_lc_ge_text";

    group zrodata (ordered, contiguous, fill)
    {
      section "zrodata_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]zrodata*";
      }
    }
    "_zrodata_START" = "_lc_gb_zrodata";
    "_zrodata_END" = ("_lc_ge_zrodata" == 0) ? 0 : "_lc_ge_zrodata" - 1;
    "_zrodata_LIMIT" = "_lc_ge_zrodata";

    "_Const_Default_ALL_START" = "_rodata_START";
    "_Const_Default_ALL_END" = "_zrodata_END";
    "_Const_Default_ALL_LIMIT" = "_zrodata_LIMIT";
  }

  group Data_Default_ROM_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:RegionBlock_PFlash0_Cached_2)
  {
    group data_ROM (ordered, contiguous, fill, align = 16)
    {
      section "data_ROM_SEC" (fill, blocksize = 2, attributes = rx)
      {
        group (load_addr)
        {
          select "[.]data*";
        }
      }
    }
    "_data_ROM_START" = "_lc_gb_data_ROM";
    "_data_ROM_LIMIT" = "_lc_ge_data_ROM";

    group zdata_ROM (ordered, contiguous, fill, align = 16)
    {
      section "zdata_ROM_SEC" (fill, blocksize = 2, attributes = rx)
      {
        group (load_addr)
        {
          select "[.]zdata*";
        }
      }
    }
    "_zdata_ROM_START" = "_lc_gb_zdata_ROM";
    "_zdata_ROM_LIMIT" = "_lc_ge_zdata_ROM";

  }

  group Data_Default_GROUP (ordered, contiguous, fill, run_addr = mem:mpe:RegionBlock_0_DSPR_Core0)
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

    group data (ordered, contiguous, fill, align = 16)
    {
      section "data_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]data*";
      }
    }
    group data_PAD (align = 4)
    {
      reserved "data_PAD" (size = 0);
    }
    "_data_START" = "_lc_gb_data";
    "_data_END" = ("_lc_ge_data" == 0) ? 0 : "_lc_ge_data" - 1;
    "_data_LIMIT" = "_lc_ge_data";

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

    group zdata (ordered, contiguous, fill, align = 16)
    {
      section "zdata_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]zdata*";
      }
    }
    group zdata_PAD (align = 4)
    {
      reserved "zdata_PAD" (size = 0);
    }
    "_zdata_START" = "_lc_gb_zdata";
    "_zdata_END" = ("_lc_ge_zdata" == 0) ? 0 : "_lc_ge_zdata" - 1;
    "_zdata_LIMIT" = "_lc_ge_zdata";

    "_Data_Default_ALL_START" = "_bss_START";
    "_Data_Default_ALL_END" = "_zdata_END";
    "_Data_Default_ALL_LIMIT" = "_zdata_LIMIT";
  }

}


