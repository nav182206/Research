/* 
 * Benchmark Sample ID : devign_8376
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7d1b0095bff7157e856d1d0e6c4295641ced2752
 */

static void shifter_out_im(TCGv var, int shift)

{

    TCGv tmp = new_tmp();

    if (shift == 0) {

        tcg_gen_andi_i32(tmp, var, 1);

    } else {

        tcg_gen_shri_i32(tmp, var, shift);

        if (shift != 31)

            tcg_gen_andi_i32(tmp, tmp, 1);

    }

    gen_set_CF(tmp);

    dead_tmp(tmp);

}
