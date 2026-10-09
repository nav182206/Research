/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8456
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=de9e9d9f17a36ff76c1a02a5348835e5e0a081b0
 */

static inline void gen_op_eval_bg(TCGv dst, TCGv_i32 src)

{

    gen_mov_reg_N(cpu_tmp0, src);

    gen_mov_reg_V(dst, src);

    tcg_gen_xor_tl(dst, dst, cpu_tmp0);

    gen_mov_reg_Z(cpu_tmp0, src);

    tcg_gen_or_tl(dst, dst, cpu_tmp0);

    tcg_gen_xori_tl(dst, dst, 0x1);

}
