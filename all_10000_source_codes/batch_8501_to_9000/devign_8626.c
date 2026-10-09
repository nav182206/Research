/* 
 * Benchmark Sample ID : devign_8626
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2c21d34ea44d38835f85b90de3cbbf54abb894be
 */

void av_free(void *ptr)

{

#if CONFIG_MEMALIGN_HACK

    if (ptr)

        free((char *)ptr - ((char *)ptr)[-1]);

#elif HAVE_ALIGNED_MALLOC

    _aligned_free(ptr);

#else

    free(ptr);

#endif

}
