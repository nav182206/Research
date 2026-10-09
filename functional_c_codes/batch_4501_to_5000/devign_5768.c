/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5768
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3e4f910c8d490a1490409a7e381dbbb229f9d272
 */

static uint32_t ehci_mem_readb(void *ptr, target_phys_addr_t addr)

{

    EHCIState *s = ptr;

    uint32_t val;



    val = s->mmio[addr];



    return val;

}
