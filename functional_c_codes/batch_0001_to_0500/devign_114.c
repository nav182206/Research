/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_114
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0fcec41eec0432c77645b4a407d3a3e030c4abc4
 */

target_ulong helper_udiv(target_ulong a, target_ulong b)

{

    uint64_t x0;

    uint32_t x1;



    x0 = (a & 0xffffffff) | ((int64_t) (env->y) << 32);

    x1 = (b & 0xffffffff);



    if (x1 == 0) {

        raise_exception(TT_DIV_ZERO);

    }



    x0 = x0 / x1;

    if (x0 > 0xffffffff) {

        env->cc_src2 = 1;

        return 0xffffffff;

    } else {

        env->cc_src2 = 0;

        return x0;

    }

}
