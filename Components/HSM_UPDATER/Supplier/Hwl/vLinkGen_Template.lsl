/**********************************************************************************************************************
 *  EXAMPLE CODE ONLY
 *  -------------------------------------------------------------------------------------------------------------------
 *  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW configuration.
 *  The Example Code has not passed any quality control measures and may be incomplete. The Example Code is neither
 *  intended nor qualified for use in series production. The Example Code as well as any of its modifications and/or
 *  implementations must be tested with diligent care and must comply with all quality requirements which are necessary
 *  according to the state of the art before their use.
 *********************************************************************************************************************/


architecture ARM
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
    architecture = ARM;
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
  memory RegionBlock_HSM_RAM
  {
    mau = 8;
    type = ram;
    size = 97920; /* 96 KiB */
    map (dest=bus:local_bus, dest_offset = 0x20000180, size = 97920);
  }
  memory RegionBlock_HSM_INTVEC_FLASH
  {
    mau = 8;
    type = rom;
    size = 2052; /* 2 KiB */
    map (dest=bus:local_bus, dest_offset = 0x80004000, size = 2052);
  }
  memory RegionBlock_HSM_FLASH_vHsmUpdEntryPoint
  {
    mau = 8;
    type = rom;
    size = 256; /* 256 Byte */
    map (dest=bus:local_bus, dest_offset = 0x80004804, size = 256);
  }
  memory RegionBlock_HSM_FLASH
  {
    mau = 8;
    type = rom;
    size = 243452; /* 238 KiB */
    map (dest=bus:local_bus, dest_offset = 0x80004904, size = 243452);
  }
}

section_layout mpe:vtc:linear
{
  group vHsmEntryPoint_GROUP (ordered, contiguous, run_addr = mem:mpe:RegionBlock_HSM_FLASH_vHsmUpdEntryPoint)
  {
    group vHsmEntryPoint (ordered, contiguous, fill)
    {
      section "vHsmEntryPoint_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select ".text.vHsmEntryPoint";
      }
    }
    "_vHsmEntryPoint_START" = "_lc_gb_vHsmEntryPoint";
    "_vHsmEntryPoint_END" = ("_lc_ge_vHsmEntryPoint" == 0) ? 0 : "_lc_ge_vHsmEntryPoint" - 1;
    "_vHsmEntryPoint_LIMIT" = "_lc_ge_vHsmEntryPoint";

    "_vHsmEntryPoint_ALL_START" = "_vHsmEntryPoint_START";
    "_vHsmEntryPoint_ALL_END" = "_vHsmEntryPoint_END";
    "_vHsmEntryPoint_ALL_LIMIT" = "_vHsmEntryPoint_LIMIT";
  }

  group OS_DATA_CORE0_VAR_ROM_GROUP (ordered, contiguous, run_addr = mem:mpe:RegionBlock_HSM_FLASH)
  {
    group OS_DATA_CORE0_VAR_INIT_ROM (ordered, contiguous, fill, align = 4)
    {
      section "OS_DATA_CORE0_VAR_INIT_ROM_SEC" (fill, blocksize = 2, attributes = rx)
      {
        group (load_addr)
        {
          select "[.]data.OS_CORE0_VAR";
          select "[.]data.OS_CORE0_VAR_NOCACHE";
          select "[.]data.OS_SystemApplication_OsCore0_VAR";
          select "[.]data.OS_SystemApplication_OsCore0_VAR_NOCACHE";
        }
      }
    }
    "_OS_DATA_CORE0_VAR_INIT_ROM_START" = "_lc_gb_OS_DATA_CORE0_VAR_INIT_ROM";
    "_OS_DATA_CORE0_VAR_INIT_ROM_LIMIT" = "_lc_ge_OS_DATA_CORE0_VAR_INIT_ROM";

  }

  group OS_DATA_CORE0_VAR_GROUP (ordered, contiguous, run_addr = mem:mpe:RegionBlock_HSM_RAM)
  {
    group OS_DATA_CORE0_VAR_INIT (ordered, contiguous, fill, align = 4)
    {
      section "OS_DATA_CORE0_VAR_INIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]data.OS_CORE0_VAR";
        select "[.]data.OS_CORE0_VAR_NOCACHE";
        select "[.]data.OS_SystemApplication_OsCore0_VAR";
        select "[.]data.OS_SystemApplication_OsCore0_VAR_NOCACHE";
      }
    }
    group OS_DATA_CORE0_VAR_INIT_PAD (align = 4)
    {
      reserved "OS_DATA_CORE0_VAR_INIT_PAD" (size = 0);
    }
    "_OS_DATA_CORE0_VAR_INIT_START" = "_lc_gb_OS_DATA_CORE0_VAR_INIT";
    "_OS_DATA_CORE0_VAR_INIT_END" = ("_lc_ge_OS_DATA_CORE0_VAR_INIT" == 0) ? 0 : "_lc_ge_OS_DATA_CORE0_VAR_INIT" - 1;
    "_OS_DATA_CORE0_VAR_INIT_LIMIT" = "_lc_ge_OS_DATA_CORE0_VAR_INIT";

    group OS_DATA_CORE0_VAR_NOINIT (ordered, contiguous, fill)
    {
      section "OS_DATA_CORE0_VAR_NOINIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]bss.OS_CORE0_VAR_NOCACHE_NOINIT";
        select "[.]bss.OS_CORE0_VAR_NOINIT";
        select "[.]bss.OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT";
        select "[.]bss.OS_SystemApplication_OsCore0_VAR_NOINIT";
      }
    }
    "_OS_DATA_CORE0_VAR_NOINIT_START" = "_lc_gb_OS_DATA_CORE0_VAR_NOINIT";
    "_OS_DATA_CORE0_VAR_NOINIT_END" = ("_lc_ge_OS_DATA_CORE0_VAR_NOINIT" == 0) ? 0 : "_lc_ge_OS_DATA_CORE0_VAR_NOINIT" - 1;
    "_OS_DATA_CORE0_VAR_NOINIT_LIMIT" = "_lc_ge_OS_DATA_CORE0_VAR_NOINIT";

    group OS_DATA_CORE0_VAR_ZERO_INIT (ordered, contiguous, fill, align = 4)
    {
      section "OS_DATA_CORE0_VAR_ZERO_INIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]*.OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT";
        select "[.]*.OS_SystemApplication_OsCore0_VAR_ZERO_INIT";
      }
    }
    group OS_DATA_CORE0_VAR_ZERO_INIT_PAD (align = 4)
    {
      reserved "OS_DATA_CORE0_VAR_ZERO_INIT_PAD" (size = 0);
    }
    "_OS_DATA_CORE0_VAR_ZERO_INIT_START" = "_lc_gb_OS_DATA_CORE0_VAR_ZERO_INIT";
    "_OS_DATA_CORE0_VAR_ZERO_INIT_END" = ("_lc_ge_OS_DATA_CORE0_VAR_ZERO_INIT" == 0) ? 0 : "_lc_ge_OS_DATA_CORE0_VAR_ZERO_INIT" - 1;
    "_OS_DATA_CORE0_VAR_ZERO_INIT_LIMIT" = "_lc_ge_OS_DATA_CORE0_VAR_ZERO_INIT";

    group OS_DATA_CORE0_VAR_ZERO_INIT_bss (ordered, contiguous, fill, align = 4)
    {
      section "OS_DATA_CORE0_VAR_ZERO_INIT_bss_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]*.OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_bss";
        select "[.]*.OS_SystemApplication_OsCore0_VAR_ZERO_INIT_bss";
      }
    }
    group OS_DATA_CORE0_VAR_ZERO_INIT_bss_PAD (align = 4)
    {
      reserved "OS_DATA_CORE0_VAR_ZERO_INIT_bss_PAD" (size = 0);
    }
    "_OS_DATA_CORE0_VAR_ZERO_INIT_bss_START" = "_lc_gb_OS_DATA_CORE0_VAR_ZERO_INIT_bss";
    "_OS_DATA_CORE0_VAR_ZERO_INIT_bss_END" = ("_lc_ge_OS_DATA_CORE0_VAR_ZERO_INIT_bss" == 0) ? 0 : "_lc_ge_OS_DATA_CORE0_VAR_ZERO_INIT_bss" - 1;
    "_OS_DATA_CORE0_VAR_ZERO_INIT_bss_LIMIT" = "_lc_ge_OS_DATA_CORE0_VAR_ZERO_INIT_bss";

    "_OS_DATA_CORE0_VAR_ALL_START" = "_OS_DATA_CORE0_VAR_INIT_START";
    "_OS_DATA_CORE0_VAR_ALL_END" = "_OS_DATA_CORE0_VAR_ZERO_INIT_bss_END";
    "_OS_DATA_CORE0_VAR_ALL_LIMIT" = "_OS_DATA_CORE0_VAR_ZERO_INIT_bss_LIMIT";
  }

  group OS_DATA_SHARED_VAR_ROM_GROUP (ordered, contiguous, run_addr = mem:mpe:RegionBlock_HSM_FLASH)
  {
    group OS_DATA_SHARED_VAR_INIT_ROM (ordered, contiguous, fill, align = 4)
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

  group OS_DATA_SHARED_VAR_GROUP (ordered, contiguous, run_addr = mem:mpe:RegionBlock_HSM_RAM)
  {
    group OS_DATA_SHARED_VAR_INIT (ordered, contiguous, fill, align = 4)
    {
      section "OS_DATA_SHARED_VAR_INIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]data.OS_VAR_NOCACHE";
      }
    }
    group OS_DATA_SHARED_VAR_INIT_PAD (align = 4)
    {
      reserved "OS_DATA_SHARED_VAR_INIT_PAD" (size = 0);
    }
    "_OS_DATA_SHARED_VAR_INIT_START" = "_lc_gb_OS_DATA_SHARED_VAR_INIT";
    "_OS_DATA_SHARED_VAR_INIT_END" = ("_lc_ge_OS_DATA_SHARED_VAR_INIT" == 0) ? 0 : "_lc_ge_OS_DATA_SHARED_VAR_INIT" - 1;
    "_OS_DATA_SHARED_VAR_INIT_LIMIT" = "_lc_ge_OS_DATA_SHARED_VAR_INIT";

    group OS_DATA_SHARED_VAR_NOINIT (ordered, contiguous, fill)
    {
      section "OS_DATA_SHARED_VAR_NOINIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]bss.OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT";
        select "[.]bss.OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT";
        select "[.]bss.OS_PUBLIC_CORE0_VAR_NOINIT";
        select "[.]bss.OS_VAR_NOCACHE_NOINIT";
      }
    }
    "_OS_DATA_SHARED_VAR_NOINIT_START" = "_lc_gb_OS_DATA_SHARED_VAR_NOINIT";
    "_OS_DATA_SHARED_VAR_NOINIT_END" = ("_lc_ge_OS_DATA_SHARED_VAR_NOINIT" == 0) ? 0 : "_lc_ge_OS_DATA_SHARED_VAR_NOINIT" - 1;
    "_OS_DATA_SHARED_VAR_NOINIT_LIMIT" = "_lc_ge_OS_DATA_SHARED_VAR_NOINIT";

    "_OS_DATA_SHARED_VAR_ALL_START" = "_OS_DATA_SHARED_VAR_INIT_START";
    "_OS_DATA_SHARED_VAR_ALL_END" = "_OS_DATA_SHARED_VAR_NOINIT_END";
    "_OS_DATA_SHARED_VAR_ALL_LIMIT" = "_OS_DATA_SHARED_VAR_NOINIT_LIMIT";
  }

  group OS_EXCVEC_CORE0_CODE_GROUP (ordered, contiguous, run_addr = mem:mpe:RegionBlock_HSM_FLASH)
  {
    group OS_EXCVEC_CORE0_CODE (ordered, contiguous, fill)
    {
      section "OS_EXCVEC_CORE0_CODE_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]text.OS_EXCVEC_CORE0_CODE";
      }
    }
    "_OS_EXCVEC_CORE0_CODE_START" = "_lc_gb_OS_EXCVEC_CORE0_CODE";
    "_OS_EXCVEC_CORE0_CODE_END" = ("_lc_ge_OS_EXCVEC_CORE0_CODE" == 0) ? 0 : "_lc_ge_OS_EXCVEC_CORE0_CODE" - 1;
    "_OS_EXCVEC_CORE0_CODE_LIMIT" = "_lc_ge_OS_EXCVEC_CORE0_CODE";

    "_OS_EXCVEC_CORE0_CODE_ALL_START" = "_OS_EXCVEC_CORE0_CODE_START";
    "_OS_EXCVEC_CORE0_CODE_ALL_END" = "_OS_EXCVEC_CORE0_CODE_END";
    "_OS_EXCVEC_CORE0_CODE_ALL_LIMIT" = "_OS_EXCVEC_CORE0_CODE_LIMIT";
  }

  group OS_EXCVEC_CORE0_CONST_GROUP (ordered, contiguous, run_addr = mem:mpe:RegionBlock_HSM_FLASH)
  {
    group OS_EXCVEC_CORE0_CONST (ordered, contiguous, fill)
    {
      section "OS_EXCVEC_CORE0_CONST_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]rodata.OS_EXCVEC_CORE0_CONST";
      }
    }
    "_OS_EXCVEC_CORE0_CONST_START" = "_lc_gb_OS_EXCVEC_CORE0_CONST";
    "_OS_EXCVEC_CORE0_CONST_END" = ("_lc_ge_OS_EXCVEC_CORE0_CONST" == 0) ? 0 : "_lc_ge_OS_EXCVEC_CORE0_CONST" - 1;
    "_OS_EXCVEC_CORE0_CONST_LIMIT" = "_lc_ge_OS_EXCVEC_CORE0_CONST";

    "_OS_EXCVEC_CORE0_CONST_ALL_START" = "_OS_EXCVEC_CORE0_CONST_START";
    "_OS_EXCVEC_CORE0_CONST_ALL_END" = "_OS_EXCVEC_CORE0_CONST_END";
    "_OS_EXCVEC_CORE0_CONST_ALL_LIMIT" = "_OS_EXCVEC_CORE0_CONST_LIMIT";
  }

  group OS_GLOBALSHARED_CONST_GROUP (ordered, contiguous, run_addr = mem:mpe:RegionBlock_HSM_FLASH)
  {
    group OS_GLOBALSHARED_CONST (ordered, contiguous, fill)
    {
      section "OS_GLOBALSHARED_CONST_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]rodata.OS_GLOBALSHARED_CONST";
      }
    }
    "_OS_GLOBALSHARED_CONST_START" = "_lc_gb_OS_GLOBALSHARED_CONST";
    "_OS_GLOBALSHARED_CONST_END" = ("_lc_ge_OS_GLOBALSHARED_CONST" == 0) ? 0 : "_lc_ge_OS_GLOBALSHARED_CONST" - 1;
    "_OS_GLOBALSHARED_CONST_LIMIT" = "_lc_ge_OS_GLOBALSHARED_CONST";

    "_OS_GLOBALSHARED_CONST_ALL_START" = "_OS_GLOBALSHARED_CONST_START";
    "_OS_GLOBALSHARED_CONST_ALL_END" = "_OS_GLOBALSHARED_CONST_END";
    "_OS_GLOBALSHARED_CONST_ALL_LIMIT" = "_OS_GLOBALSHARED_CONST_LIMIT";
  }

  group OS_GLOBALSHARED_VAR_ROM_GROUP (ordered, contiguous, run_addr = mem:mpe:RegionBlock_HSM_FLASH)
  {
    group OS_GLOBALSHARED_VAR_INIT_ROM (ordered, contiguous, fill, align = 4)
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

  group OS_GLOBALSHARED_VAR_GROUP (ordered, contiguous, run_addr = mem:mpe:RegionBlock_HSM_RAM)
  {
    group OS_GLOBALSHARED_VAR_INIT (ordered, contiguous, fill, align = 4)
    {
      section "OS_GLOBALSHARED_VAR_INIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]data.OS_GLOBALSHARED_VAR";
        select "[.]data.OS_GLOBALSHARED_VAR_NOCACHE";
      }
    }
    group OS_GLOBALSHARED_VAR_INIT_PAD (align = 4)
    {
      reserved "OS_GLOBALSHARED_VAR_INIT_PAD" (size = 0);
    }
    "_OS_GLOBALSHARED_VAR_INIT_START" = "_lc_gb_OS_GLOBALSHARED_VAR_INIT";
    "_OS_GLOBALSHARED_VAR_INIT_END" = ("_lc_ge_OS_GLOBALSHARED_VAR_INIT" == 0) ? 0 : "_lc_ge_OS_GLOBALSHARED_VAR_INIT" - 1;
    "_OS_GLOBALSHARED_VAR_INIT_LIMIT" = "_lc_ge_OS_GLOBALSHARED_VAR_INIT";

    group OS_GLOBALSHARED_VAR_NOINIT (ordered, contiguous, fill)
    {
      section "OS_GLOBALSHARED_VAR_NOINIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]bss.OS_GLOBALSHARED_VAR_NOCACHE_NOINIT";
        select "[.]bss.OS_GLOBALSHARED_VAR_NOINIT";
      }
    }
    "_OS_GLOBALSHARED_VAR_NOINIT_START" = "_lc_gb_OS_GLOBALSHARED_VAR_NOINIT";
    "_OS_GLOBALSHARED_VAR_NOINIT_END" = ("_lc_ge_OS_GLOBALSHARED_VAR_NOINIT" == 0) ? 0 : "_lc_ge_OS_GLOBALSHARED_VAR_NOINIT" - 1;
    "_OS_GLOBALSHARED_VAR_NOINIT_LIMIT" = "_lc_ge_OS_GLOBALSHARED_VAR_NOINIT";

    group OS_GLOBALSHARED_VAR_ZERO_INIT (ordered, contiguous, fill, align = 4)
    {
      section "OS_GLOBALSHARED_VAR_ZERO_INIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]*.OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT";
        select "[.]*.OS_GLOBALSHARED_VAR_ZERO_INIT";
      }
    }
    group OS_GLOBALSHARED_VAR_ZERO_INIT_PAD (align = 4)
    {
      reserved "OS_GLOBALSHARED_VAR_ZERO_INIT_PAD" (size = 0);
    }
    "_OS_GLOBALSHARED_VAR_ZERO_INIT_START" = "_lc_gb_OS_GLOBALSHARED_VAR_ZERO_INIT";
    "_OS_GLOBALSHARED_VAR_ZERO_INIT_END" = ("_lc_ge_OS_GLOBALSHARED_VAR_ZERO_INIT" == 0) ? 0 : "_lc_ge_OS_GLOBALSHARED_VAR_ZERO_INIT" - 1;
    "_OS_GLOBALSHARED_VAR_ZERO_INIT_LIMIT" = "_lc_ge_OS_GLOBALSHARED_VAR_ZERO_INIT";

    group OS_GLOBALSHARED_VAR_ZERO_INIT_bss (ordered, contiguous, fill, align = 4)
    {
      section "OS_GLOBALSHARED_VAR_ZERO_INIT_bss_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]*.OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT_bss";
        select "[.]*.OS_GLOBALSHARED_VAR_ZERO_INIT_bss";
      }
    }
    group OS_GLOBALSHARED_VAR_ZERO_INIT_bss_PAD (align = 4)
    {
      reserved "OS_GLOBALSHARED_VAR_ZERO_INIT_bss_PAD" (size = 0);
    }
    "_OS_GLOBALSHARED_VAR_ZERO_INIT_bss_START" = "_lc_gb_OS_GLOBALSHARED_VAR_ZERO_INIT_bss";
    "_OS_GLOBALSHARED_VAR_ZERO_INIT_bss_END" = ("_lc_ge_OS_GLOBALSHARED_VAR_ZERO_INIT_bss" == 0) ? 0 : "_lc_ge_OS_GLOBALSHARED_VAR_ZERO_INIT_bss" - 1;
    "_OS_GLOBALSHARED_VAR_ZERO_INIT_bss_LIMIT" = "_lc_ge_OS_GLOBALSHARED_VAR_ZERO_INIT_bss";

    "_OS_GLOBALSHARED_VAR_ALL_START" = "_OS_GLOBALSHARED_VAR_INIT_START";
    "_OS_GLOBALSHARED_VAR_ALL_END" = "_OS_GLOBALSHARED_VAR_ZERO_INIT_bss_END";
    "_OS_GLOBALSHARED_VAR_ALL_LIMIT" = "_OS_GLOBALSHARED_VAR_ZERO_INIT_bss_LIMIT";
  }

  group OS_INTVEC_CODE_GROUP (ordered, contiguous, run_addr = mem:mpe:RegionBlock_HSM_FLASH)
  {
    group OS_INTVEC_CODE (ordered, contiguous, fill, align = 2048)
    {
      section "OS_INTVEC_CODE_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]text.OS_INTVEC_CODE";
      }
    }
    "_OS_INTVEC_CODE_START" = "_lc_gb_OS_INTVEC_CODE";
    "_OS_INTVEC_CODE_END" = ("_lc_ge_OS_INTVEC_CODE" == 0) ? 0 : "_lc_ge_OS_INTVEC_CODE" - 1;
    "_OS_INTVEC_CODE_LIMIT" = "_lc_ge_OS_INTVEC_CODE";

    "_OS_INTVEC_CODE_ALL_START" = "_OS_INTVEC_CODE_START";
    "_OS_INTVEC_CODE_ALL_END" = "_OS_INTVEC_CODE_END";
    "_OS_INTVEC_CODE_ALL_LIMIT" = "_OS_INTVEC_CODE_LIMIT";
  }

  group OS_INTVEC_CONST_GROUP (ordered, contiguous, run_addr = mem:mpe:RegionBlock_HSM_FLASH)
  {
    group OS_INTVEC_CONST (ordered, contiguous, fill, align = 2048)
    {
      section "OS_INTVEC_CONST_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]rodata.OS_INTVEC_CONST";
      }
    }
    "_OS_INTVEC_CONST_START" = "_lc_gb_OS_INTVEC_CONST";
    "_OS_INTVEC_CONST_END" = ("_lc_ge_OS_INTVEC_CONST" == 0) ? 0 : "_lc_ge_OS_INTVEC_CONST" - 1;
    "_OS_INTVEC_CONST_LIMIT" = "_lc_ge_OS_INTVEC_CONST";

    "_OS_INTVEC_CONST_ALL_START" = "_OS_INTVEC_CONST_START";
    "_OS_INTVEC_CONST_ALL_END" = "_OS_INTVEC_CONST_END";
    "_OS_INTVEC_CONST_ALL_LIMIT" = "_OS_INTVEC_CONST_LIMIT";
  }

  group OS_INTVEC_CORE0_CODE_GROUP (ordered, contiguous, run_addr = mem:mpe:RegionBlock_HSM_FLASH)
  {
    group OS_INTVEC_CORE0_CODE (ordered, contiguous, fill, align = 2048)
    {
      section "OS_INTVEC_CORE0_CODE_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]text.OS_INTVEC_CORE0_CODE";
      }
    }
    "_OS_INTVEC_CORE0_CODE_START" = "_lc_gb_OS_INTVEC_CORE0_CODE";
    "_OS_INTVEC_CORE0_CODE_END" = ("_lc_ge_OS_INTVEC_CORE0_CODE" == 0) ? 0 : "_lc_ge_OS_INTVEC_CORE0_CODE" - 1;
    "_OS_INTVEC_CORE0_CODE_LIMIT" = "_lc_ge_OS_INTVEC_CORE0_CODE";

    "_OS_INTVEC_CORE0_CODE_ALL_START" = "_OS_INTVEC_CORE0_CODE_START";
    "_OS_INTVEC_CORE0_CODE_ALL_END" = "_OS_INTVEC_CORE0_CODE_END";
    "_OS_INTVEC_CORE0_CODE_ALL_LIMIT" = "_OS_INTVEC_CORE0_CODE_LIMIT";
  }

  group OS_INTVEC_CORE0_CONST_GROUP (ordered, contiguous, run_addr = mem:mpe:RegionBlock_HSM_INTVEC_FLASH)
  {
    group OS_INTVEC_CORE0_CONST (ordered, contiguous, fill, align = 2048)
    {
      section "OS_INTVEC_CORE0_CONST_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]rodata.OS_INTVEC_CORE0_CONST";
      }
    }
    "_OS_INTVEC_CORE0_CONST_START" = "_lc_gb_OS_INTVEC_CORE0_CONST";
    "_OS_INTVEC_CORE0_CONST_END" = ("_lc_ge_OS_INTVEC_CORE0_CONST" == 0) ? 0 : "_lc_ge_OS_INTVEC_CORE0_CONST" - 1;
    "_OS_INTVEC_CORE0_CONST_LIMIT" = "_lc_ge_OS_INTVEC_CORE0_CONST";

    "_OS_INTVEC_CORE0_CONST_ALL_START" = "_OS_INTVEC_CORE0_CONST_START";
    "_OS_INTVEC_CORE0_CONST_ALL_END" = "_OS_INTVEC_CORE0_CONST_END";
    "_OS_INTVEC_CORE0_CONST_ALL_LIMIT" = "_OS_INTVEC_CORE0_CONST_LIMIT";
  }

  group OS_STACKS_CORE0_VAR_GROUP (ordered, contiguous, run_addr = mem:mpe:RegionBlock_HSM_RAM)
  {
    group OS_STACKS_CORE0_VAR_NOINIT (ordered, contiguous, fill)
    {
      section "OS_STACKS_CORE0_VAR_NOINIT_SEC" (blocksize = 2, attributes = rw)
      {
        select "[.]bss.OS_STACK_OSCORE0_ERROR_VAR_NOINIT";
        select "[.]bss.OS_STACK_OSCORE0_INIT_VAR_NOINIT";
        select "[.]bss.OS_STACK_OSCORE0_ISR_CORE_VAR_NOINIT";
        select "[.]bss.OS_STACK_OSCORE0_KERNEL_VAR_NOINIT";
      }
    }
    "_OS_STACKS_CORE0_VAR_NOINIT_START" = "_lc_gb_OS_STACKS_CORE0_VAR_NOINIT";
    "_OS_STACKS_CORE0_VAR_NOINIT_END" = ("_lc_ge_OS_STACKS_CORE0_VAR_NOINIT" == 0) ? 0 : "_lc_ge_OS_STACKS_CORE0_VAR_NOINIT" - 1;
    "_OS_STACKS_CORE0_VAR_NOINIT_LIMIT" = "_lc_ge_OS_STACKS_CORE0_VAR_NOINIT";

    "_OS_STACKS_CORE0_VAR_ALL_START" = "_OS_STACKS_CORE0_VAR_NOINIT_START";
    "_OS_STACKS_CORE0_VAR_ALL_END" = "_OS_STACKS_CORE0_VAR_NOINIT_END";
    "_OS_STACKS_CORE0_VAR_ALL_LIMIT" = "_OS_STACKS_CORE0_VAR_NOINIT_LIMIT";
  }

  group OS_USER_CODE_GROUP (ordered, contiguous, run_addr = mem:mpe:RegionBlock_HSM_FLASH)
  {
    group OS_USER_CODE (ordered, contiguous, fill)
    {
      section "OS_USER_CODE_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]text.OS_ERRORHOOK_CODE";
        select "[.]text.OS_vHsm_Hal_ExternalRequestIsr_CODE";
      }
    }
    "_OS_USER_CODE_START" = "_lc_gb_OS_USER_CODE";
    "_OS_USER_CODE_END" = ("_lc_ge_OS_USER_CODE" == 0) ? 0 : "_lc_ge_OS_USER_CODE" - 1;
    "_OS_USER_CODE_LIMIT" = "_lc_ge_OS_USER_CODE";

    "_OS_USER_CODE_ALL_START" = "_OS_USER_CODE_START";
    "_OS_USER_CODE_ALL_END" = "_OS_USER_CODE_END";
    "_OS_USER_CODE_ALL_LIMIT" = "_OS_USER_CODE_LIMIT";
  }

  group STACK_C0_GROUP (ordered, contiguous, run_addr = mem:mpe:RegionBlock_HSM_RAM)
  {
    group STACK_C0 (ordered, contiguous, fill, align = 4)
    {
      reserved "STACK_C0" (size = 4024);
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

  group Startup_Code_GROUP (ordered, contiguous, run_addr = mem:mpe:RegionBlock_HSM_FLASH)
  {
    group Startup_Code (ordered, contiguous, fill, align = 4)
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

  "_RESET" = "brsStartupEntry";
  "_start" = "brsStartupEntry";
  "StartupEntry" = "brsStartupEntry";
  "_StartupEntry" = "brsStartupEntry";
  "Reset_Handler" = "brsStartupEntry";
  "vHsmUpd_FirmwareStart" = 0x80008061;

  "__section_stack_c0_end" = "_STACK_C0_LIMIT";

  group vHsmRamCode_ROM_GROUP (ordered, contiguous, run_addr = mem:mpe:RegionBlock_HSM_FLASH)
  {
    group vHsmRamCode_ROM (ordered, contiguous, fill, align = 4)
    {
      section "vHsmRamCode_ROM_SEC" (fill, blocksize = 1, attributes = rx)
      {
        group (load_addr)
        {
          select "[.]text.vHsmRamCode";
          select "[.]rodata.vHsmRamCode";
        }
      }
    }
    "_vHsmRamCode_ROM_START" = "_lc_gb_vHsmRamCode_ROM";
    "_vHsmRamCode_ROM_LIMIT" = "_lc_ge_vHsmRamCode_ROM";

  }

  group vHsmRamCode_GROUP (ordered, contiguous, run_addr = mem:mpe:RegionBlock_HSM_RAM)
  {
    group vHsmRamCode_ALIGN (align = 4)
    {
      reserved "vHsmRamCode_ALIGN" (size = 4);
    }
    group vHsmRamCode (ordered, contiguous, fill, align = 1, copy)
    {
      /* Due to a Linker issue: 'COPY_TO_RAM' const groups cannot be created with inner output section */
      select "[.]text.vHsmRamCode";
      select "[.]rodata.vHsmRamCode";
    }
    group vHsmRamCode_PAD (align = 4)
    {
      reserved "vHsmRamCode_PAD" (size = 0);
    }
    "_vHsmRamCode_START" = "_lc_gb_vHsmRamCode";
    "_vHsmRamCode_END" = ("_lc_ge_vHsmRamCode" == 0) ? 0 : "_lc_ge_vHsmRamCode" - 1;
    "_vHsmRamCode_LIMIT" = "_lc_ge_vHsmRamCode";

    "_vHsmRamCode_ALL_START" = "_vHsmRamCode_START";
    "_vHsmRamCode_ALL_END" = "_vHsmRamCode_END";
    "_vHsmRamCode_ALL_LIMIT" = "_vHsmRamCode_LIMIT";
  }

  group OS_CODE_GROUP (ordered, contiguous, run_addr = mem:mpe:RegionBlock_HSM_FLASH)
  {
    group OS_CODE (ordered, contiguous, fill)
    {
      section "OS_CODE_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]text.OS_CODE";
        select "[.]text.OS_OS_COREINITHOOK_CODE";
      }
    }
    "_OS_CODE_START" = "_lc_gb_OS_CODE";
    "_OS_CODE_END" = ("_lc_ge_OS_CODE" == 0) ? 0 : "_lc_ge_OS_CODE" - 1;
    "_OS_CODE_LIMIT" = "_lc_ge_OS_CODE";

    "_OS_CODE_ALL_START" = "_OS_CODE_START";
    "_OS_CODE_ALL_END" = "_OS_CODE_END";
    "_OS_CODE_ALL_LIMIT" = "_OS_CODE_LIMIT";
  }

  group OS_CONST_GROUP (ordered, contiguous, run_addr = mem:mpe:RegionBlock_HSM_FLASH)
  {
    group OS_CONST (ordered, contiguous, fill)
    {
      section "OS_CONST_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]rodata.OS_CONST";
        select "[.]rodata.OS_CORE0_CONST";
        select "[.]rodata.OS_SystemApplication_OsCore0_CONST";
      }
    }
    "_OS_CONST_START" = "_lc_gb_OS_CONST";
    "_OS_CONST_END" = ("_lc_ge_OS_CONST" == 0) ? 0 : "_lc_ge_OS_CONST" - 1;
    "_OS_CONST_LIMIT" = "_lc_ge_OS_CONST";

    "_OS_CONST_ALL_START" = "_OS_CONST_START";
    "_OS_CONST_ALL_END" = "_OS_CONST_END";
    "_OS_CONST_ALL_LIMIT" = "_OS_CONST_LIMIT";
  }

  group Const_Default_GROUP (ordered, contiguous, run_addr = mem:mpe:RegionBlock_HSM_FLASH)
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

  group Data_Default_ROM_GROUP (ordered, contiguous, run_addr = mem:mpe:RegionBlock_HSM_FLASH)
  {
    group data_ROM (ordered, contiguous, fill, align = 4)
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

    group zdata_ROM (ordered, contiguous, fill, align = 4)
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

  group Data_Default_GROUP (ordered, contiguous, run_addr = mem:mpe:RegionBlock_HSM_RAM)
  {
    group bss (ordered, contiguous, fill, align = 4)
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

    group data (ordered, contiguous, fill, align = 4)
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

    group zbss (ordered, contiguous, fill, align = 4)
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

    group zdata (ordered, contiguous, fill, align = 4)
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


