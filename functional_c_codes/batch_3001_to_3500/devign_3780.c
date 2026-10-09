/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3780
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3debbb5af5f63440b170b71bf3aecc0e778f5691
 */

target_ulong helper_msub32_suov(CPUTriCoreState *env, target_ulong r1,

                                target_ulong r2, target_ulong r3)

{

    int64_t t1 = extract64(r1, 0, 32);

    int64_t t2 = extract64(r2, 0, 32);

    int64_t t3 = extract64(r3, 0, 32);

    int64_t result;



    result = t2 - (t1 * t3);

    return suov32_neg(env, result);

}
