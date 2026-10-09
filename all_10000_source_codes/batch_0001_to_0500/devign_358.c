/* 
 * Benchmark Sample ID : devign_358
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=919f3554387e043bdfe10c6369356d1104882183
 */

void ff_decode_dxt1(const uint8_t *s, uint8_t *dst,

                    const unsigned int w, const unsigned int h,

                    const unsigned int stride) {

    unsigned int bx, by, qstride = stride/4;

    uint32_t *d = (uint32_t *) dst;



    for (by=0; by < h/4; by++, d += stride-w)

        for (bx=0; bx < w/4; bx++, s+=8, d+=4)

            dxt1_decode_pixels(s, d, qstride, 0, 0LL);

}
