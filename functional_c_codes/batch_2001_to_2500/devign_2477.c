/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2477
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static void slow_bar_writew(void *opaque, target_phys_addr_t addr, uint32_t val)

{

    AssignedDevRegion *d = opaque;

    uint16_t *out = (uint16_t *)(d->u.r_virtbase + addr);



    DEBUG("slow_bar_writew addr=0x" TARGET_FMT_plx " val=0x%04x\n", addr, val);

    *out = val;

}
