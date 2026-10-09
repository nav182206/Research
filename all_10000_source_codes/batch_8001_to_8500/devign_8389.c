/* 
 * Benchmark Sample ID : devign_8389
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0e8b68a2c4031e25082603ad88711be12210d41f
 */

int64_t av_gettime_relative(void)

{

#if HAVE_CLOCK_GETTIME && defined(CLOCK_MONOTONIC)

    struct timespec ts;

    clock_gettime(CLOCK_MONOTONIC, &ts);

    return (int64_t)ts.tv_sec * 1000000 + ts.tv_nsec / 1000;

#else

    return av_gettime() + 42 * 60 * 60 * INT64_C(1000000);

#endif

}
