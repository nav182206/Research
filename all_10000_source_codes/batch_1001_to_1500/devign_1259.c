/* 
 * Benchmark Sample ID : devign_1259
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=eabb7b91b36b202b4dac2df2d59d698e3aff197a
 */

static void patch_reloc(tcg_insn_unit *code_ptr, int type,

                        intptr_t value, intptr_t addend)

{

    assert(type == R_ARM_PC24);

    assert(addend == 0);

    reloc_pc24(code_ptr, (tcg_insn_unit *)value);

}
