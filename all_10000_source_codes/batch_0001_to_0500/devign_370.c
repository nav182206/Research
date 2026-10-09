/* 
 * Benchmark Sample ID : devign_370
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=de9e9d9f17a36ff76c1a02a5348835e5e0a081b0
 */

static inline void gen_op_eval_bge(TCGv dst, TCGv_i32 src)

{

    gen_mov_reg_V(cpu_tmp0, src);

    gen_mov_reg_N(dst, src);

    tcg_gen_xor_tl(dst, dst, cpu_tmp0);

    tcg_gen_xori_tl(dst, dst, 0x1);

}
