/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7038
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a7812ae412311d7d47f8aa85656faadac9d64b56
 */

static inline void gen_neon_narrow_sats(int size, TCGv dest, TCGv src)

{

    switch (size) {

    case 0: gen_helper_neon_narrow_sat_s8(dest, cpu_env, src); break;

    case 1: gen_helper_neon_narrow_sat_s16(dest, cpu_env, src); break;

    case 2: gen_helper_neon_narrow_sat_s32(dest, cpu_env, src); break;

    default: abort();

    }

}
