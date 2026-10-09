/* 
 * Benchmark Sample ID : devign_2193
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=306ab3e86a94b7547883ca9dac0c86122bb8622c
 */

void do_ddiv (void)

{

    if (T1 != 0) {

        lldiv_t res = lldiv((int64_t)T0, (int64_t)T1);

        env->LO[0][env->current_tc] = res.quot;

        env->HI[0][env->current_tc] = res.rem;

    }

}
