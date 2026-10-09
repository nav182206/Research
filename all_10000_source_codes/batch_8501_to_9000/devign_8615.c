/* 
 * Benchmark Sample ID : devign_8615
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=df824548d031dbfc5fa86ea9e0c652bd086b55c4
 */

static int delta_decode(uint8_t *dst, const uint8_t *src, int src_size,

                         unsigned val, const int8_t *table)

{

    uint8_t *dst0 = dst;



    while (src_size--) {

        uint8_t d = *src++;

        val = av_clip_uint8(val + table[d & 0xF]);

        *dst++ = val;

        val = av_clip_uint8(val + table[d >> 4]);

        *dst++ = val;

    }



    return dst-dst0;

}
