/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8721
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d9bce9d99f4656ae0b0127f7472db9067b8f84ab
 */

void do_POWER_divs (void)

{

    if ((Ts0 == INT32_MIN && Ts1 == -1) || Ts1 == 0) {

        T0 = (long)((-1) * (T0 >> 31));

        env->spr[SPR_MQ] = 0;

    } else {

        env->spr[SPR_MQ] = T0 % T1;

        T0 = Ts0 / Ts1;

    }

}
