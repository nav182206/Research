/* 
 * Benchmark Sample ID : devign_4051
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=22d716c28e95e4640e2cd80553eb3f662db3fd50
 */

static ExitStatus gen_bcond(DisasContext *ctx, TCGCond cond, int ra,

                            int32_t disp, int mask)

{

    TCGv cmp_tmp;



    if (mask) {

        cmp_tmp = tcg_temp_new();

        tcg_gen_andi_i64(cmp_tmp, load_gpr(ctx, ra), 1);

    } else {

        cmp_tmp = load_gpr(ctx, ra);

    }



    return gen_bcond_internal(ctx, cond, cmp_tmp, disp);

}
