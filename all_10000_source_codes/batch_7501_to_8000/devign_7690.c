/* 
 * Benchmark Sample ID : devign_7690
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6ef228fc0de1d5fb43ebfef039563d39a3a37067
 */

static void ratelimit_set_speed(RateLimit *limit, uint64_t speed)

{

    limit->slice_quota = speed / (1000000000ULL / SLICE_TIME);

}
