/* 
 * Benchmark Sample ID : devign_3919
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static int omap_validate_emifs_addr(struct omap_mpu_state_s *s,

                target_phys_addr_t addr)

{

    return range_covers_byte(OMAP_EMIFS_BASE, OMAP_EMIFF_BASE - OMAP_EMIFS_BASE,

                             addr);

}
