/* 
 * Benchmark Sample ID : devign_5815
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3b4fefd6e65a7bdb994d10a9fa36c19b5749b502
 */

static void gen_mtpr(int rb, int regno)

{

    TCGv tmp;

    int data;



    if (rb == 31) {

        tmp = tcg_const_i64(0);

    } else {

        tmp = cpu_ir[rb];

    }



    /* The basic registers are data only, and unknown registers

       are read-zero, write-ignore.  */

    data = cpu_pr_data(regno);

    if (data != 0) {

        if (data & PR_BYTE) {

            tcg_gen_st8_i64(tmp, cpu_env, data & ~PR_BYTE);

        } else if (data & PR_LONG) {

            tcg_gen_st32_i64(tmp, cpu_env, data & ~PR_LONG);

        } else {

            tcg_gen_st_i64(tmp, cpu_env, data);

        }

    }



    if (rb == 31) {

        tcg_temp_free(tmp);

    }

}
