/* 
 * Benchmark Sample ID : devign_2701
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a7812ae412311d7d47f8aa85656faadac9d64b56
 */

static always_inline void gen_arith3 (void *helper,

                                      int ra, int rb, int rc,

                                      int islit, uint8_t lit)

{

    if (unlikely(rc == 31))

        return;



    if (ra != 31) {

        if (islit) {

            TCGv tmp = tcg_const_i64(lit);

            tcg_gen_helper_1_2(helper, cpu_ir[rc], cpu_ir[ra], tmp);

            tcg_temp_free(tmp);

        } else

            tcg_gen_helper_1_2(helper, cpu_ir[rc], cpu_ir[ra], cpu_ir[rb]);

    } else {

        TCGv tmp1 = tcg_const_i64(0);

        if (islit) {

            TCGv tmp2 = tcg_const_i64(lit);

            tcg_gen_helper_1_2(helper, cpu_ir[rc], tmp1, tmp2);

            tcg_temp_free(tmp2);

        } else

            tcg_gen_helper_1_2(helper, cpu_ir[rc], tmp1, cpu_ir[rb]);

        tcg_temp_free(tmp1);

    }

}
