/* 
 * Benchmark Sample ID : devign_9679
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ef397e88e96d4a798bd190bcd0c43865c3725ae2
 */

void ppc40x_chip_reset (CPUState *env)

{

    target_ulong dbsr;



    printf("Reset PowerPC chip\n");

    cpu_ppc_reset(env);

    /* XXX: TODO reset all internal peripherals */

    dbsr = env->spr[SPR_40x_DBSR];

    dbsr &= ~0x00000300;

    dbsr |= 0x00000200;

    env->spr[SPR_40x_DBSR] = dbsr;

    cpu_loop_exit();

}
