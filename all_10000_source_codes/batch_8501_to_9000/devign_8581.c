/* 
 * Benchmark Sample ID : devign_8581
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d9bce9d99f4656ae0b0127f7472db9067b8f84ab
 */

void do_rfi (void)

{

    env->nip = env->spr[SPR_SRR0] & ~0x00000003;

    T0 = env->spr[SPR_SRR1] & ~0xFFFF0000UL;

    do_store_msr(env, T0);

#if defined (DEBUG_OP)

    dump_rfi();

#endif

    env->interrupt_request |= CPU_INTERRUPT_EXITTB;

}
