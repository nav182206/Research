/* 
 * Benchmark Sample ID : devign_8962
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3b55429d5692dd782d8b3ce6a19819305157d1b8
 */

void av_fast_malloc(void *ptr, unsigned int *size, size_t min_size)

{

    void **p = ptr;

    if (min_size < *size)

        return;

    min_size= FFMAX(17*min_size/16 + 32, min_size);

    av_free(*p);

    *p = av_malloc(min_size);

    if (!*p) min_size = 0;

    *size= min_size;

}
