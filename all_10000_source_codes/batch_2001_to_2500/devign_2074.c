/* 
 * Benchmark Sample ID : devign_2074
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5064357588a187672ca64c169dc6e6e406777629
 */

static void conv411(uint8_t *dst, int dst_wrap, 
                    uint8_t *src, int src_wrap,
                    int width, int height)
{
    int w, c;
    uint8_t *s1, *s2, *d;
    for(;height > 0; height--) {
        s1 = src;
        s2 = src + src_wrap;
        d = dst;
        for(w = width;w > 0; w--) {
            c = (s1[0] + s2[0]) >> 1;
            d[0] = c;
            d[1] = c;
            s1++;
            s2++;
            d += 2;
        }
        src += src_wrap * 2;
        dst += dst_wrap;
    }
}
