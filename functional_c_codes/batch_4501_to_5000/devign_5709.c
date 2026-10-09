/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5709
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static uint32_t slow_bar_readb(void *opaque, target_phys_addr_t addr)

{

    AssignedDevRegion *d = opaque;

    uint8_t *in = d->u.r_virtbase + addr;

    uint32_t r;



    r = *in;

    DEBUG("slow_bar_readl addr=0x" TARGET_FMT_plx " val=0x%08x\n", addr, r);



    return r;

}
