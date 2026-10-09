/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_895
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=185698715dfb18c82ad2a5dbc169908602d43e81
 */

static inline uint32_t efsctsiz(uint32_t val)

{

    CPU_FloatU u;



    u.l = val;

    /* NaN are not treated the same way IEEE 754 does */

    if (unlikely(float32_is_nan(u.f)))

        return 0;



    return float32_to_int32_round_to_zero(u.f, &env->vec_status);

}
