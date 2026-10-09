/* 
 * Benchmark Sample ID : devign_4909
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static uint32_t slow_bar_readl(void *opaque, target_phys_addr_t addr)

{

    AssignedDevRegion *d = opaque;

    uint32_t *in = (uint32_t *)(d->u.r_virtbase + addr);

    uint32_t r;



    r = *in;

    DEBUG("slow_bar_readl addr=0x" TARGET_FMT_plx " val=0x%08x\n", addr, r);



    return r;

}
