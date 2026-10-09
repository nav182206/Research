/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2199
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=159d2e39a8602c369542a92573a52acb5f5f58f2
 */

static long getrampagesize(void)

{

    long hpsize = LONG_MAX;

    Object *memdev_root;



    if (mem_path) {

        return gethugepagesize(mem_path);

    }



    /* it's possible we have memory-backend objects with

     * hugepage-backed RAM. these may get mapped into system

     * address space via -numa parameters or memory hotplug

     * hooks. we want to take these into account, but we

     * also want to make sure these supported hugepage

     * sizes are applicable across the entire range of memory

     * we may boot from, so we take the min across all

     * backends, and assume normal pages in cases where a

     * backend isn't backed by hugepages.

     */

    memdev_root = object_resolve_path("/objects", NULL);

    if (!memdev_root) {

        return getpagesize();

    }



    object_child_foreach(memdev_root, find_max_supported_pagesize, &hpsize);



    if (hpsize == LONG_MAX) {

        return getpagesize();

    }



    if (nb_numa_nodes == 0 && hpsize > getpagesize()) {

        /* No NUMA nodes and normal RAM without -mem-path ==> no huge pages! */

        static bool warned;

        if (!warned) {

            error_report("Huge page support disabled (n/a for main memory).");

            warned = true;

        }

        return getpagesize();

    }



    return hpsize;

}
