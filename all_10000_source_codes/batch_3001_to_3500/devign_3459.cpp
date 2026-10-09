/* 
 * Benchmark Sample ID : devign_3459
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9d7a4c6690ef9962a3b20034f65008f1ea15c1d6
 */

void *g_try_realloc(void *mem, size_t n_bytes)

{

    __coverity_negative_sink__(n_bytes);

    return realloc(mem, n_bytes == 0 ? 1 : n_bytes);

}
