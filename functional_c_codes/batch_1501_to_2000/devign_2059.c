/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2059
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=185698715dfb18c82ad2a5dbc169908602d43e81
 */

static inline uint32_t efsctuf(uint32_t val)

{

    CPU_FloatU u;

    float32 tmp;



    u.l = val;

    /* NaN are not treated the same way IEEE 754 does */

    if (unlikely(float32_is_nan(u.f)))

        return 0;

    tmp = uint64_to_float32(1ULL << 32, &env->vec_status);

    u.f = float32_mul(u.f, tmp, &env->vec_status);



    return float32_to_uint32(u.f, &env->vec_status);

}
