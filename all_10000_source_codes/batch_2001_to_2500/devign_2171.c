/* 
 * Benchmark Sample ID : devign_2171
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b3a62939561e07bc34493444fa926b6137cba4e8
 */

static inline void tcg_reg_sync(TCGContext *s, int reg)

{

    TCGTemp *ts;

    int temp;



    temp = s->reg_to_temp[reg];

    ts = &s->temps[temp];

    assert(ts->val_type == TEMP_VAL_REG);

    if (!ts->mem_coherent && !ts->fixed_reg) {

        if (!ts->mem_allocated) {

            temp_allocate_frame(s, temp);

        }

        tcg_out_st(s, ts->type, reg, ts->mem_reg, ts->mem_offset);

    }

    ts->mem_coherent = 1;

}
