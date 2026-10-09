/* 
 * Benchmark Sample ID : devign_894
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7a0e58fa648736a75f2a6943afd2ab08ea15b8e0
 */

static void count_cpreg(gpointer key, gpointer opaque)

{

    ARMCPU *cpu = opaque;

    uint64_t regidx;

    const ARMCPRegInfo *ri;



    regidx = *(uint32_t *)key;

    ri = get_arm_cp_reginfo(cpu->cp_regs, regidx);



    if (!(ri->type & ARM_CP_NO_MIGRATE)) {

        cpu->cpreg_array_len++;

    }

}
