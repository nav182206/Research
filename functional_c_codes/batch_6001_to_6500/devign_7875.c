/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7875
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=425532d71d5d295cc9c649500e4969ac621ce51d
 */

static inline int check_fit_tl(tcg_target_long val, unsigned int bits)

{

    return (val << ((sizeof(tcg_target_long) * 8 - bits))

            >> (sizeof(tcg_target_long) * 8 - bits)) == val;

}
