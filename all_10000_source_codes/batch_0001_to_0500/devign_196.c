/* 
 * Benchmark Sample ID : devign_196
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a9493601638b048c44751956d2360f215918800c
 */

void *av_realloc(void *ptr, unsigned int size)

{

#ifdef MEMALIGN_HACK

    int diff;

#endif



    /* let's disallow possible ambiguous cases */

    if(size > INT_MAX)

        return NULL;



#ifdef MEMALIGN_HACK

    //FIXME this isn't aligned correctly, though it probably isn't needed

    if(!ptr) return av_malloc(size);

    diff= ((char*)ptr)[-1];

    return realloc(ptr - diff, size + diff) + diff;

#else

    return realloc(ptr, size);

#endif

}
