/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5427
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b29a0341d7ed7e7df4bf77a41db8e614f1ddb645
 */

void op_dmtc0_ebase (void)

{

    /* vectored interrupts not implemented */

    /* Multi-CPU not implemented */

    /* XXX: 64bit addressing broken */

    env->CP0_EBase = (int32_t)0x80000000 | (T0 & 0x3FFFF000);

    RETURN();

}
