/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3318
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4d9ad7f793605abd9806fc932b3e04e028894565
 */

uint64_t HELPER(neon_abdl_u32)(uint32_t a, uint32_t b)

{

    uint64_t tmp;

    uint64_t result;

    DO_ABD(result, a, b, uint16_t);

    DO_ABD(tmp, a >> 16, b >> 16, uint16_t);

    return result | (tmp << 32);

}
