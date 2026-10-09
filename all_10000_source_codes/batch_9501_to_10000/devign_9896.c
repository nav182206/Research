/* 
 * Benchmark Sample ID : devign_9896
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d1916d13e28b87f4b1b214231149e12e1d536b4b
 */

static void add_bytes_c(uint8_t *dst, uint8_t *src, int w){

    long i;

    for(i=0; i<=w-sizeof(long); i+=sizeof(long)){

        long a = *(long*)(src+i);

        long b = *(long*)(dst+i);

        *(long*)(dst+i) = ((a&pb_7f) + (b&pb_7f)) ^ ((a^b)&pb_80);

    }

    for(; i<w; i++)

        dst[i+0] += src[i+0];

}
