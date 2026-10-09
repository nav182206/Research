/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8778
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7dfd8c6aa1d0691d03c5ccc9b0c5a93bcf00f768
 */

static void tcg_reg_alloc_start(TCGContext *s)

{

    int i;

    TCGTemp *ts;

    for(i = 0; i < s->nb_globals; i++) {

        ts = &s->temps[i];

        if (ts->fixed_reg) {

            ts->val_type = TEMP_VAL_REG;

        } else {

            ts->val_type = TEMP_VAL_MEM;

        }

    }

    for(i = s->nb_globals; i < s->nb_temps; i++) {

        ts = &s->temps[i];

        ts->val_type = TEMP_VAL_DEAD;

        ts->mem_allocated = 0;

        ts->fixed_reg = 0;

    }

    for(i = 0; i < TCG_TARGET_NB_REGS; i++) {

        s->reg_to_temp[i] = -1;

    }

}
