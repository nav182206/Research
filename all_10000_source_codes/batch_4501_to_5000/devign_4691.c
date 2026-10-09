/* 
 * Benchmark Sample ID : devign_4691
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=62698be3bac2e4c969205f3849c48922e0e76e88
 */

static inline int gen_neon_add(int size, TCGv t0, TCGv t1)

{

    switch (size) {

    case 0: gen_helper_neon_add_u8(t0, t0, t1); break;

    case 1: gen_helper_neon_add_u16(t0, t0, t1); break;

    case 2: tcg_gen_add_i32(t0, t0, t1); break;

    default: return 1;

    }

    return 0;

}
