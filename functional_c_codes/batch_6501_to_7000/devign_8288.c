/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8288
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a7812ae412311d7d47f8aa85656faadac9d64b56
 */

static always_inline void gen_farith3 (void *helper,

                                       int ra, int rb, int rc)

{

    if (unlikely(rc == 31))

        return;



    if (ra != 31) {

        if (rb != 31)

            tcg_gen_helper_1_2(helper, cpu_fir[rc], cpu_fir[ra], cpu_fir[rb]);

        else {

            TCGv tmp = tcg_const_i64(0);

            tcg_gen_helper_1_2(helper, cpu_fir[rc], cpu_fir[ra], tmp);

            tcg_temp_free(tmp);

        }

    } else {

        TCGv tmp = tcg_const_i64(0);

        if (rb != 31)

            tcg_gen_helper_1_2(helper, cpu_fir[rc], tmp, cpu_fir[rb]);

        else

            tcg_gen_helper_1_2(helper, cpu_fir[rc], tmp, tmp);

        tcg_temp_free(tmp);

    }

}
