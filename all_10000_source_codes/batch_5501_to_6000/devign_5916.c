/* 
 * Benchmark Sample ID : devign_5916
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4d9ad7f793605abd9806fc932b3e04e028894565
 */

uint64_t HELPER(neon_abdl_u64)(uint32_t a, uint32_t b)

{

    uint64_t result;

    DO_ABD(result, a, b, uint32_t);

    return result;

}
