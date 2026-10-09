/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5543
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=da9b170c6f06184a5114dc66afb8385cd0ffff83
 */

void *av_malloc(unsigned int size)

{

    void *ptr;

    

#if defined (HAVE_MEMALIGN)

    ptr = memalign(16,size);

    /* Why 64? 

       Indeed, we should align it:

         on 4 for 386

         on 16 for 486

	 on 32 for 586, PPro - k6-III

	 on 64 for K7 (maybe for P3 too).

       Because L1 and L2 caches are aligned on those values.

       But I don't want to code such logic here!

     */

     /* Why 16?

        because some cpus need alignment, for example SSE2 on P4, & most RISC cpus

        it will just trigger an exception and the unaligned load will be done in the

        exception handler or it will just segfault (SSE2 on P4)

        Why not larger? because i didnt see a difference in benchmarks ...

     */

     /* benchmarks with p3

        memalign(64)+1		3071,3051,3032

        memalign(64)+2		3051,3032,3041

        memalign(64)+4		2911,2896,2915

        memalign(64)+8		2545,2554,2550

        memalign(64)+16		2543,2572,2563

        memalign(64)+32		2546,2545,2571

        memalign(64)+64		2570,2533,2558

        

        btw, malloc seems to do 8 byte alignment by default here

     */

#else

    ptr = malloc(size);

#endif

    return ptr;

}
