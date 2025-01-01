/**********************************************************************************************************************
 *  EXAMPLE CODE ONLY
 *  -------------------------------------------------------------------------------------------------------------------
 *  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW configuration.
 *  The Example Code has not passed any quality control measures and may be incomplete. The Example Code is neither
 *  intended nor qualified for use in series production. The Example Code as well as any of its modifications and/or
 *  implementations must be tested with diligent care and must comply with all quality requirements which are necessary
 *  according to the state of the art before their use.
 *********************************************************************************************************************/

#define FLASHDRV_START_ADDRESS   0x70100000
#define FLASHDRV_SIZE            0x00000800
/* make sure that this is within the flashdrv area */
#define FLASHDRV_TRAPTAB_ADDRESS 0x70100700

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
    copytable_space = vtc:linear;
  }
  bus local_bus
  {
    mau = 8;
    width = 32;
    map (dest = bus:vtc:local_bus, dest_offset = 0, size = 4G);
  }
  section_setup :vtc:linear
  {
    copytable (align = 4, dest = linear);
  }
  memory FlashDrvArea_Rom
  {
    mau = 8;
    type = rom;
    size = 0x800;
    map (dest=bus:local_bus, dest_offset = FLASHDRV_START_ADDRESS, size = FLASHDRV_SIZE);
  }
}

section_layout mpe:vtc:linear
{
  group FlashDrv_TrapTab (ordered, fill)
  {
    group (run_addr=(FLASHDRV_TRAPTAB_ADDRESS)+0x0000) select ".text.traptab0.trapvec.000";
    group (run_addr=(FLASHDRV_TRAPTAB_ADDRESS)+0x0020) select ".text.traptab0.trapvec.001";
    group (run_addr=(FLASHDRV_TRAPTAB_ADDRESS)+0x0040) select ".text.traptab0.trapvec.002";
    group (run_addr=(FLASHDRV_TRAPTAB_ADDRESS)+0x0060) select ".text.traptab0.trapvec.003";
    group (run_addr=(FLASHDRV_TRAPTAB_ADDRESS)+0x0080) select ".text.traptab0.trapvec.004";
    group (run_addr=(FLASHDRV_TRAPTAB_ADDRESS)+0x00a0) select ".text.traptab0.trapvec.005";
    group (run_addr=(FLASHDRV_TRAPTAB_ADDRESS)+0x00c0) select ".text.traptab0.trapvec.006";
    group (run_addr=(FLASHDRV_TRAPTAB_ADDRESS)+0x00e0) select ".text.traptab0.trapvec.007";
    "_lc_u_trap_tab_tc0" = (FLASHDRV_TRAPTAB_ADDRESS);
  }
  
  group FlashDrv_RomSpecificGroup_GROUP (ordered, run_addr = mem:mpe:FlashDrvArea_Rom)
  {
    group FlsDriver_AllSectionGroup (ordered, contiguous, fill)
    {
      section "FlsDriver_AllSectionGroup_SEC" (fill, blocksize = 2, attributes = rx)
      {
        select "[.]rodata*";
        select "[.]text*";
      }
    }
  }
}


