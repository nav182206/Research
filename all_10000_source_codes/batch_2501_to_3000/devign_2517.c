/* 
 * Benchmark Sample ID : devign_2517
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e8ede0a8bb5298a6979bcf7ed84ef64a64a4e3fe
 */

static inline uint64_t ucf64_dtoi(float64 d)

{

    union {

        uint64_t i;

        float64 d;

    } v;



    v.d = d;

    return v.i;

}
