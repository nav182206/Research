/* 
 * Benchmark Sample ID : devign_8266
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=35ee72b1d72a4c8fc0ae4e76ad00a71e831b8dbe
 */

static void float_to_int16_sse(int16_t *dst, const float *src, long len){

    int i;

    for(i=0; i<len; i+=4) {

        asm volatile(

            "cvtps2pi    %1, %%mm0 \n\t"

            "cvtps2pi    %2, %%mm1 \n\t"

            "packssdw %%mm1, %%mm0 \n\t"

            "movq     %%mm0, %0    \n\t"

            :"=m"(dst[i])

            :"m"(src[i]), "m"(src[i+2])

        );

    }

    asm volatile("emms");

}
