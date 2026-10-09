/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_381
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static uint64_t bonito_cop_readl(void *opaque, target_phys_addr_t addr,

                                 unsigned size)

{

    uint32_t val;

    PCIBonitoState *s = opaque;



    val = ((uint32_t *)(&s->boncop))[addr/sizeof(uint32_t)];



    return val;

}
