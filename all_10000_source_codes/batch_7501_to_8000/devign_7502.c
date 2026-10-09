/* 
 * Benchmark Sample ID : devign_7502
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

uint32_t omap_badwidth_read16(void *opaque, target_phys_addr_t addr)

{

    uint16_t ret;



    OMAP_16B_REG(addr);

    cpu_physical_memory_read(addr, (void *) &ret, 2);

    return ret;

}
