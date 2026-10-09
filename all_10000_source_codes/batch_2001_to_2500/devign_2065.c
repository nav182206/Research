/* 
 * Benchmark Sample ID : devign_2065
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e8ede0a8bb5298a6979bcf7ed84ef64a64a4e3fe
 */

static inline float32 ucf64_itos(uint32_t i)

{

    union {

        uint32_t i;

        float32 s;

    } v;



    v.i = i;

    return v.s;

}
