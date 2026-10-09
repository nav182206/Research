/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9741
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bec1631100323fac0900aea71043d5c4e22fc2fa
 */

static inline void tcg_out_goto_label(TCGContext *s, int cond, int label_index)

{

    TCGLabel *l = &s->labels[label_index];



    if (l->has_value) {

        tcg_out_goto(s, cond, l->u.value_ptr);

    } else {

        tcg_out_reloc(s, s->code_ptr, R_ARM_PC24, label_index, 0);

        tcg_out_b_noaddr(s, cond);

    }

}
