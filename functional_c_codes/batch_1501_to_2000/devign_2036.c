/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2036
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7e7e59409294af9caa63808e56c5cc824c98b4fc
 */

static void img_copy(uint8_t *dst, int dst_wrap, 

                     uint8_t *src, int src_wrap,

                     int width, int height)

{

    for(;height > 0; height--) {

        memcpy(dst, src, width);

        dst += dst_wrap;

        src += src_wrap;

    }

}
