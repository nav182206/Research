/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6847
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b3415e4c5f9205820fd6c9211ad50a4df2692a36
 */

void *av_fast_realloc(void *ptr, unsigned int *size, size_t min_size)

{

    if (min_size < *size)

        return ptr;



    min_size = FFMAX(17 * min_size / 16 + 32, min_size);



    ptr = av_realloc(ptr, min_size);

    /* we could set this to the unmodified min_size but this is safer

     * if the user lost the ptr and uses NULL now

     */

    if (!ptr)

        min_size = 0;



    *size = min_size;



    return ptr;

}
