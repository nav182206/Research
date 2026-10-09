/* 
 * Benchmark Sample ID : devign_9729
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static void bonito_cop_writel(void *opaque, target_phys_addr_t addr,

                              uint64_t val, unsigned size)

{

    PCIBonitoState *s = opaque;



    ((uint32_t *)(&s->boncop))[addr/sizeof(uint32_t)] = val & 0xffffffff;

}
