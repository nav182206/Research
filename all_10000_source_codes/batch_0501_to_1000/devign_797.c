/* 
 * Benchmark Sample ID : devign_797
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6f2d8978728c48ca46f5c01835438508aace5c64
 */

void do_POWER_div (void)

{

    uint64_t tmp;



    if (((int32_t)T0 == INT32_MIN && (int32_t)T1 == -1) || (int32_t)T1 == 0) {

        T0 = (long)((-1) * (T0 >> 31));

        env->spr[SPR_MQ] = 0;

    } else {

        tmp = ((uint64_t)T0 << 32) | env->spr[SPR_MQ];

        env->spr[SPR_MQ] = tmp % T1;

        T0 = tmp / (int32_t)T1;

    }

}
