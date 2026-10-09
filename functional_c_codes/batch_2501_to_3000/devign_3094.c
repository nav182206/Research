/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3094
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=49a661910c1374858602a3002b67115893673c25
 */

static uint64_t read_raw_cp_reg(CPUARMState *env, const ARMCPRegInfo *ri)

{

    /* Raw read of a coprocessor register (as needed for migration, etc). */

    if (ri->type & ARM_CP_CONST) {

        return ri->resetvalue;

    } else if (ri->raw_readfn) {

        return ri->raw_readfn(env, ri);

    } else if (ri->readfn) {

        return ri->readfn(env, ri);

    } else {

        return raw_read(env, ri);

    }

}
