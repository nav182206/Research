/* 
 * Benchmark Sample ID : devign_6184
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4ae4b609ee2d5bcc9df6c03c21dc1fed527aada1
 */

static void br(DisasContext *dc, uint32_t code, uint32_t flags)

{

    I_TYPE(instr, code);



    gen_goto_tb(dc, 0, dc->pc + 4 + (instr.imm16s & -4));

    dc->is_jmp = DISAS_TB_JUMP;

}
