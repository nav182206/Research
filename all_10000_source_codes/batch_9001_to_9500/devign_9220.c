/* 
 * Benchmark Sample ID : devign_9220
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=85d604af5f96c32734af9974ec6ddb625b6716a2
 */

target_ulong helper_madd32_suov(CPUTriCoreState *env, target_ulong r1,

                                target_ulong r2, target_ulong r3)

{

    uint64_t t1 = extract64(r1, 0, 32);

    uint64_t t2 = extract64(r2, 0, 32);

    uint64_t t3 = extract64(r3, 0, 32);

    int64_t result;



    result = t2 + (t1 * t3);

    return suov32(env, result);

}
