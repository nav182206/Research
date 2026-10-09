/* 
 * Benchmark Sample ID : devign_975
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static void omap_pin_cfg_init(MemoryRegion *system_memory,

                target_phys_addr_t base,

                struct omap_mpu_state_s *mpu)

{

    memory_region_init_io(&mpu->pin_cfg_iomem, &omap_pin_cfg_ops, mpu,

                          "omap-pin-cfg", 0x800);

    memory_region_add_subregion(system_memory, base, &mpu->pin_cfg_iomem);

    omap_pin_cfg_reset(mpu);

}
