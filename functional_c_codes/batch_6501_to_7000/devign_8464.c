/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8464
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=62be4e3a5041e84304aa23637da623a205c53ecc
 */

ram_addr_t qemu_ram_alloc(ram_addr_t size, MemoryRegion *mr, Error **errp)

{

    return qemu_ram_alloc_from_ptr(size, NULL, mr, errp);

}
