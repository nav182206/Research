/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8063
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=dcfd14b3741983c466ad92fa2ae91eeafce3e5d5
 */

static void arm_cache_flush(abi_ulong start, abi_ulong last)

{

    abi_ulong addr, last1;



    if (last < start)

        return;

    addr = start;

    for(;;) {

        last1 = ((addr + TARGET_PAGE_SIZE) & TARGET_PAGE_MASK) - 1;

        if (last1 > last)

            last1 = last;

        tb_invalidate_page_range(addr, last1 + 1);

        if (last1 == last)

            break;

        addr = last1 + 1;

    }

}
