/* 
 * Benchmark Sample ID : devign_8794
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=eabb7b91b36b202b4dac2df2d59d698e3aff197a
 */

static inline void reloc_pc19(tcg_insn_unit *code_ptr, tcg_insn_unit *target)

{

    ptrdiff_t offset = target - code_ptr;

    assert(offset == sextract64(offset, 0, 19));

    *code_ptr = deposit32(*code_ptr, 5, 19, offset);

}
