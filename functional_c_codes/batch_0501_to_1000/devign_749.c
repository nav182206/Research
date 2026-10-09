/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_749
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=47f0beadba9003391d8bfef59b15aa21a5b2d293
 */

static void cin_decode_rle(const unsigned char *src, int src_size, unsigned char *dst, int dst_size)

{

    int len, code;

    unsigned char *dst_end = dst + dst_size;

    const unsigned char *src_end = src + src_size;



    while (src < src_end && dst < dst_end) {

        code = *src++;

        if (code & 0x80) {

            len = code - 0x7F;

            memset(dst, *src++, FFMIN(len, dst_end - dst));

        } else {

            len = code + 1;

            memcpy(dst, src, FFMIN(len, dst_end - dst));

            src += len;

        }

        dst += len;

    }

}
