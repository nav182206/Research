/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2758
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=58d479786b11a7e982419c1e0905b8490ef9a787
 */

static void bonito_cop_writel(void *opaque, hwaddr addr,
                              uint64_t val, unsigned size)
{
    PCIBonitoState *s = opaque;
    ((uint32_t *)(&s->boncop))[addr/sizeof(uint32_t)] = val & 0xffffffff;
