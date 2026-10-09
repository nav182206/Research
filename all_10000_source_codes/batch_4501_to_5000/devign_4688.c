/* 
 * Benchmark Sample ID : devign_4688
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b3a62939561e07bc34493444fa926b6137cba4e8
 */

TCGv_i32 tcg_global_reg_new_i32(int reg, const char *name)

{

    int idx;



    idx = tcg_global_reg_new_internal(TCG_TYPE_I32, reg, name);

    return MAKE_TCGV_I32(idx);

}
