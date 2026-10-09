/* 
 * Benchmark Sample ID : devign_717
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e2a176dfda32f5cf80703c2921a19fe75850c38c
 */

static uint32_t taihu_cpld_readw (void *opaque, hwaddr addr)

{

    uint32_t ret;



    ret = taihu_cpld_readb(opaque, addr) << 8;

    ret |= taihu_cpld_readb(opaque, addr + 1);



    return ret;

}
