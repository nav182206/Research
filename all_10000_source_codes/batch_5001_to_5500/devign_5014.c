/* 
 * Benchmark Sample ID : devign_5014
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a7812ae412311d7d47f8aa85656faadac9d64b56
 */

static inline void gen_neon_negl(TCGv var, int size)

{

    switch (size) {

    case 0: gen_helper_neon_negl_u16(var, var); break;

    case 1: gen_helper_neon_negl_u32(var, var); break;

    case 2: gen_helper_neon_negl_u64(var, var); break;

    default: abort();

    }

}
