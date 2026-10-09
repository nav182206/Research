/* 
 * Benchmark Sample ID : devign_4382
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d9bce9d99f4656ae0b0127f7472db9067b8f84ab
 */

void do_POWER_divo (void)

{

    int64_t tmp;



    if ((Ts0 == INT32_MIN && Ts1 == -1) || Ts1 == 0) {

        T0 = (long)((-1) * (T0 >> 31));

        env->spr[SPR_MQ] = 0;

        xer_ov = 1;

        xer_so = 1;

    } else {

        tmp = ((uint64_t)T0 << 32) | env->spr[SPR_MQ];

        env->spr[SPR_MQ] = tmp % T1;

        tmp /= Ts1;

        if (tmp > (int64_t)INT32_MAX || tmp < (int64_t)INT32_MIN) {

            xer_ov = 1;

            xer_so = 1;

        } else {

            xer_ov = 0;

        }

        T0 = tmp;

    }

}
