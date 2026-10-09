/* 
 * Benchmark Sample ID : devign_5271
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ad96090a01d848df67d70c5259ed8aa321fa8716
 */

uint64_t ram_bytes_transferred(void)

{

    return bytes_transferred;

}
