/* 
 * Benchmark Sample ID : devign_5292
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=030ffe39dd4128eb90483af82a5b23b23054a466
 */

static void patch_reloc(tcg_insn_unit *code_ptr, int type,

                        intptr_t value, intptr_t addend)

{

    tcg_insn_unit *target;

    tcg_insn_unit old;



    value += addend;

    target = (tcg_insn_unit *)value;



    switch (type) {

    case R_PPC_REL14:

        reloc_pc14(code_ptr, target);

        break;

    case R_PPC_REL24:

        reloc_pc24(code_ptr, target);

        break;

    case R_PPC_ADDR16:

        assert(value == (int16_t)value);

        old = *code_ptr;

        old = deposit32(old, 0, 16, value);

        *code_ptr = old;

        break;

    default:

        tcg_abort();

    }

}
