/* 
 * Benchmark Sample ID : devign_7102
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b3415e4c5f9205820fd6c9211ad50a4df2692a36
 */

static inline int ff_fast_malloc(void *ptr, unsigned int *size, size_t min_size, int zero_realloc)

{

    void *val;



    if (min_size < *size)

        return 0;

    min_size = FFMAX(17 * min_size / 16 + 32, min_size);

    av_freep(ptr);

    val = zero_realloc ? av_mallocz(min_size) : av_malloc(min_size);

    memcpy(ptr, &val, sizeof(val));

    if (!val)

        min_size = 0;

    *size = min_size;

    return 1;

}
