/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9457
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4b1b1c896fb38d435f3d350c44b1bdc8b56600a4
 */

uint32_t qemu_devtree_alloc_phandle(void *fdt)

{

    static int phandle = 0x8000;



    return phandle++;

}
