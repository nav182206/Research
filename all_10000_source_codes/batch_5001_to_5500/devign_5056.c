/* 
 * Benchmark Sample ID : devign_5056
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static void slow_bar_writeb(void *opaque, target_phys_addr_t addr, uint32_t val)

{

    AssignedDevRegion *d = opaque;

    uint8_t *out = d->u.r_virtbase + addr;



    DEBUG("slow_bar_writeb addr=0x" TARGET_FMT_plx " val=0x%02x\n", addr, val);

    *out = val;

}
