/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2459
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ad96090a01d848df67d70c5259ed8aa321fa8716
 */

uint64_t ram_bytes_total(void)

{

    return last_ram_offset;

}
