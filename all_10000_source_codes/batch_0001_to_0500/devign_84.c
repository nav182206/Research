/* 
 * Benchmark Sample ID : devign_84
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=90e496386fe7fd32c189561f846b7913f95b8cf4
 */

static void read_vec_element_i32(DisasContext *s, TCGv_i32 tcg_dest, int srcidx,

                                 int element, TCGMemOp memop)

{

    int vect_off = vec_reg_offset(srcidx, element, memop & MO_SIZE);

    switch (memop) {

    case MO_8:

        tcg_gen_ld8u_i32(tcg_dest, cpu_env, vect_off);

        break;

    case MO_16:

        tcg_gen_ld16u_i32(tcg_dest, cpu_env, vect_off);

        break;

    case MO_8|MO_SIGN:

        tcg_gen_ld8s_i32(tcg_dest, cpu_env, vect_off);

        break;

    case MO_16|MO_SIGN:

        tcg_gen_ld16s_i32(tcg_dest, cpu_env, vect_off);

        break;

    case MO_32:

    case MO_32|MO_SIGN:

        tcg_gen_ld_i32(tcg_dest, cpu_env, vect_off);

        break;

    default:

        g_assert_not_reached();

    }

}
