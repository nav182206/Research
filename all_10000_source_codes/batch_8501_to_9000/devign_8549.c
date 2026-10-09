/* 
 * Benchmark Sample ID : devign_8549
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4d9ad7f793605abd9806fc932b3e04e028894565
 */

uint64_t HELPER(neon_abdl_s32)(uint32_t a, uint32_t b)

{

    uint64_t tmp;

    uint64_t result;

    DO_ABD(result, a, b, int16_t);

    DO_ABD(tmp, a >> 16, b >> 16, int16_t);

    return result | (tmp << 32);

}
