/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9235
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4e17eae9f2ee49833698aae2753c5bb041510870
 */

void tcg_target_qemu_prologue(TCGContext *s)

{

    /* stmdb sp!, { r9 - r11, lr } */

    tcg_out32(s, (COND_AL << 28) | 0x092d4e00);



    tcg_out_bx(s, COND_AL, TCG_REG_R0);

    tb_ret_addr = s->code_ptr;



    /* ldmia sp!, { r9 - r11, pc } */

    tcg_out32(s, (COND_AL << 28) | 0x08bd8e00);

}
