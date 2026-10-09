/* 
 * Benchmark Sample ID : devign_9858
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d9bce9d99f4656ae0b0127f7472db9067b8f84ab
 */

void OPPROTO op_POWER_sre (void)

{

    T1 &= 0x1FUL;

    env->spr[SPR_MQ] = rotl32(T0, 32 - T1);

    T0 = Ts0 >> T1;

    RETURN();

}
