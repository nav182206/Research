/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9975
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

void omap_badwidth_write8(void *opaque, target_phys_addr_t addr,

                uint32_t value)

{

    uint8_t val8 = value;



    OMAP_8B_REG(addr);

    cpu_physical_memory_write(addr, (void *) &val8, 1);

}
