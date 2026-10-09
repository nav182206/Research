/* 
 * Benchmark Sample ID : devign_2872
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=de9e9d9f17a36ff76c1a02a5348835e5e0a081b0
 */

static inline void gen_op_eval_fblg(TCGv dst, TCGv src,

                                    unsigned int fcc_offset)

{

    gen_mov_reg_FCC0(dst, src, fcc_offset);

    gen_mov_reg_FCC1(cpu_tmp0, src, fcc_offset);

    tcg_gen_xor_tl(dst, dst, cpu_tmp0);

}
