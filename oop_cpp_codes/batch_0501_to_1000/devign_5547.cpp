/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_5547
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9d7a4c6690ef9962a3b20034f65008f1ea15c1d6
 */

void *g_try_malloc0(size_t n_bytes)

{

    __coverity_negative_sink__(n_bytes);

    return calloc(1, n_bytes == 0 ? 1 : n_bytes);

}
