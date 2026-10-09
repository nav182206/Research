/* 
 * Benchmark Sample ID : devign_7910
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f02ca5cbeaf86038834c1953247a1579d7921927
 */

static inline void tcg_out_addi(TCGContext *s, int reg, tcg_target_long val)

{

    if (val != 0) {

        if (val == (val & 0xfff))

            tcg_out_arithi(s, reg, reg, val, ARITH_ADD);

        else

            fprintf(stderr, "unimplemented addi %ld\n", (long)val);

    }

}
