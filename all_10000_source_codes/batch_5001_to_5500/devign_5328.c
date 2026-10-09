/* 
 * Benchmark Sample ID : devign_5328
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=fea7d77d3ea287d3b1878648f3049fc6bb4fd57b
 */

void helper_fcmp_eq_DT(CPUSH4State *env, float64 t0, float64 t1)

{

    int relation;



    set_float_exception_flags(0, &env->fp_status);

    relation = float64_compare(t0, t1, &env->fp_status);

    if (unlikely(relation == float_relation_unordered)) {

        update_fpscr(env, GETPC());

    } else {

        env->sr_t = (relation == float_relation_equal);

    }

}
