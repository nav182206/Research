/* 
 * Benchmark Sample ID : devign_2130
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=433d33c555deeed375996e338df1a9510df401c6
 */

static void gen_jumpi(DisasContext *dc, uint32_t dest, int slot)

{

    TCGv_i32 tmp = tcg_const_i32(dest);

    if (((dc->pc ^ dest) & TARGET_PAGE_MASK) != 0) {

        slot = -1;

    }

    gen_jump_slot(dc, tmp, slot);

    tcg_temp_free(tmp);

}
