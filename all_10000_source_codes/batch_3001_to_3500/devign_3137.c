/* 
 * Benchmark Sample ID : devign_3137
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8ba2aae32c40f544def6be7ae82be9bcb781e01d
 */

void uuid_generate(uuid_t out)

{

    memset(out, 0, sizeof(uuid_t));

}
