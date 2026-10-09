/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5699
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d68a6f3a6deb2f5eee198b6fa46877a20227d86e
 */

static void gen_neon_zip_u8(TCGv t0, TCGv t1)

{

    TCGv rd, rm, tmp;



    rd = new_tmp();

    rm = new_tmp();

    tmp = new_tmp();



    tcg_gen_andi_i32(rd, t0, 0xff);

    tcg_gen_shli_i32(tmp, t1, 8);

    tcg_gen_andi_i32(tmp, tmp, 0xff00);

    tcg_gen_or_i32(rd, rd, tmp);

    tcg_gen_shli_i32(tmp, t0, 16);

    tcg_gen_andi_i32(tmp, tmp, 0xff0000);

    tcg_gen_or_i32(rd, rd, tmp);

    tcg_gen_shli_i32(tmp, t1, 24);

    tcg_gen_andi_i32(tmp, tmp, 0xff000000);

    tcg_gen_or_i32(rd, rd, tmp);



    tcg_gen_andi_i32(rm, t1, 0xff000000);

    tcg_gen_shri_i32(tmp, t0, 8);

    tcg_gen_andi_i32(tmp, tmp, 0xff0000);

    tcg_gen_or_i32(rm, rm, tmp);

    tcg_gen_shri_i32(tmp, t1, 8);

    tcg_gen_andi_i32(tmp, tmp, 0xff00);

    tcg_gen_or_i32(rm, rm, tmp);

    tcg_gen_shri_i32(tmp, t0, 16);

    tcg_gen_andi_i32(tmp, tmp, 0xff);

    tcg_gen_or_i32(t1, rm, tmp);

    tcg_gen_mov_i32(t0, rd);



    dead_tmp(tmp);

    dead_tmp(rm);

    dead_tmp(rd);

}
