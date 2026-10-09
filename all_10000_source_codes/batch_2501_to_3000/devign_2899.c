/* 
 * Benchmark Sample ID : devign_2899
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0ecca7a49f8e254c12a3a1de048d738bfbb614c6
 */

void *av_realloc(void *ptr, unsigned int size)
{
#ifdef MEMALIGN_HACK
    //FIXME this isnt aligned correctly though it probably isnt needed
    int diff;
    if(!ptr) return av_malloc(size);
    diff= ((char*)ptr)[-1];
    return realloc(ptr - diff, size + diff) + diff;
#else
    return realloc(ptr, size);
#endif
}
