/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8680
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e41029b378b4a65a0b89b5a8dc087aca6b5d012d
 */

static void gen_stswx(DisasContext *ctx)

{

    TCGv t0;

    TCGv_i32 t1, t2;

    gen_set_access_type(ctx, ACCESS_INT);

    /* NIP cannot be restored if the memory exception comes from an helper */

    gen_update_nip(ctx, ctx->nip - 4);

    t0 = tcg_temp_new();

    gen_addr_reg_index(ctx, t0);

    t1 = tcg_temp_new_i32();

    tcg_gen_trunc_tl_i32(t1, cpu_xer);

    tcg_gen_andi_i32(t1, t1, 0x7F);

    t2 = tcg_const_i32(rS(ctx->opcode));

    gen_helper_stsw(cpu_env, t0, t1, t2);

    tcg_temp_free(t0);

    tcg_temp_free_i32(t1);

    tcg_temp_free_i32(t2);

}
