/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5041
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static int omap_validate_tipb_mpui_addr(struct omap_mpu_state_s *s,

                target_phys_addr_t addr)

{

    return range_covers_byte(0xe1010000, 0xe1020004 - 0xe1010000, addr);

}
