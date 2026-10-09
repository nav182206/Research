/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_636
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4a9f9cb24de52e93aae7539a004dd20314ca1c0c
 */

uint32_t HELPER(neon_min_f32)(uint32_t a, uint32_t b)

{

    float32 f0 = make_float32(a);

    float32 f1 = make_float32(b);

    return (float32_compare_quiet(f0, f1, NFS) == -1) ? a : b;

}
