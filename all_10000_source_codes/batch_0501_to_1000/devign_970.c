/* 
 * Benchmark Sample ID : devign_970
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f682e9c244af7166225f4a50cc18ff296bb9d43e
 */

static hwaddr vfio_container_granularity(VFIOContainer *container)

{

    return (hwaddr)1 << ctz64(container->iova_pgsizes);

}
