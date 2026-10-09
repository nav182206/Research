/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_94
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7c560456707bfe53eb1728fcde759be7d9418b62
 */

static void ecc_mem_writew(void *opaque, target_phys_addr_t addr, uint32_t val)

{

    printf("ECC: Unsupported write 0x" TARGET_FMT_plx " %04x\n",

           addr, val & 0xffff);

}
