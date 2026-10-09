/* 
 * Benchmark Sample ID : devign_3712
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static uint64_t lance_mem_read(void *opaque, target_phys_addr_t addr,

                               unsigned size)

{

    SysBusPCNetState *d = opaque;

    uint32_t val;



    val = pcnet_ioport_readw(&d->state, addr);

    trace_lance_mem_readw(addr, val & 0xffff);

    return val & 0xffff;

}
