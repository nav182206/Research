/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8038
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=eabb7b91b36b202b4dac2df2d59d698e3aff197a
 */

static void tci_out_label(TCGContext *s, TCGLabel *label)

{

    if (label->has_value) {

        tcg_out_i(s, label->u.value);

        assert(label->u.value);

    } else {

        tcg_out_reloc(s, s->code_ptr, sizeof(tcg_target_ulong), label, 0);

        s->code_ptr += sizeof(tcg_target_ulong);

    }

}
