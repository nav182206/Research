/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7424
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=185698715dfb18c82ad2a5dbc169908602d43e81
 */

uint32_t helper_efdctsi (uint64_t val)

{

    CPU_DoubleU u;



    u.ll = val;

    /* NaN are not treated the same way IEEE 754 does */

    if (unlikely(float64_is_nan(u.d)))

        return 0;



    return float64_to_int32(u.d, &env->vec_status);

}
