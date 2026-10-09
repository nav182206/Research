/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2204
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=58d479786b11a7e982419c1e0905b8490ef9a787
 */

static uint64_t bonito_cop_readl(void *opaque, hwaddr addr,
                                 unsigned size)
{
    uint32_t val;
    PCIBonitoState *s = opaque;
    val = ((uint32_t *)(&s->boncop))[addr/sizeof(uint32_t)];
    return val;
