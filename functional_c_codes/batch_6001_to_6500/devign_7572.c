/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7572
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6f2d8978728c48ca46f5c01835438508aace5c64
 */

void OPPROTO op_POWER_sllq (void)

{

    uint32_t msk = -1;



    msk = msk << (T1 & 0x1FUL);

    if (T1 & 0x20UL)

        msk = ~msk;

    T1 &= 0x1FUL;

    T0 = (T0 << T1) & msk;

    T0 |= env->spr[SPR_MQ] & ~msk;

    RETURN();

}
