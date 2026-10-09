/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9077
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ce137829e7e58fcdc5ba63b5e256f972e80be438
 */

static inline void array_free(array_t* array)

{

    if(array->pointer)

        free(array->pointer);

    array->size=array->next=0;

}
