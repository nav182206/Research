/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8681
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4d9ad7f793605abd9806fc932b3e04e028894565
 */

uint64_t HELPER(neon_abdl_s64)(uint32_t a, uint32_t b)

{

    uint64_t result;

    DO_ABD(result, a, b, int32_t);

    return result;

}
