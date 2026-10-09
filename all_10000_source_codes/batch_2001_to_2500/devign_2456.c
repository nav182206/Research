/* 
 * Benchmark Sample ID : devign_2456
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=45416789e8ccced568a4984af61974adfbfa0f62
 */

static int omap_validate_local_addr(struct omap_mpu_state_s *s,

                target_phys_addr_t addr)

{

    return addr >= OMAP_LOCALBUS_BASE && addr < OMAP_LOCALBUS_BASE + 0x1000000;

}
