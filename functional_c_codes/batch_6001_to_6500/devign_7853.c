/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7853
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d9bce9d99f4656ae0b0127f7472db9067b8f84ab
 */

void do_icbi (void)

{

    uint32_t tmp;

    /* Invalidate one cache line :

     * PowerPC specification says this is to be treated like a load

     * (not a fetch) by the MMU. To be sure it will be so,

     * do the load "by hand".

     */

#if defined(TARGET_PPC64)

    if (!msr_sf)

        T0 &= 0xFFFFFFFFULL;

#endif

    tmp = ldl_kernel(T0);

    T0 &= ~(ICACHE_LINE_SIZE - 1);

    tb_invalidate_page_range(T0, T0 + ICACHE_LINE_SIZE);

}
