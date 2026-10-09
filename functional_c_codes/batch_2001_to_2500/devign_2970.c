/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2970
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7ec1e5ea4bd0700fa48da86bffa2fcc6146c410a
 */

static TCGv_i32 gen_get_asi(DisasContext *dc, int insn)

{

    int asi;



    if (IS_IMM) {

#ifdef TARGET_SPARC64

        asi = dc->asi;

#else

        gen_exception(dc, TT_ILL_INSN);

        asi = 0;

#endif

    } else {

        asi = GET_FIELD(insn, 19, 26);

    }

    return tcg_const_i32(asi);

}
