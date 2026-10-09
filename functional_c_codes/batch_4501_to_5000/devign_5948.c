/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5948
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3ff91d7e85176f8b4b131163d7fd801757a2c949
 */

void tcg_gen_ld8s_i64(TCGv_i64 ret, TCGv_ptr arg2, tcg_target_long offset)

{

    tcg_gen_ld8s_i32(TCGV_LOW(ret), arg2, offset);

    tcg_gen_sari_i32(TCGV_HIGH(ret), TCGV_HIGH(ret), 31);

}
