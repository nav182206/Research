/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_509
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=da8242e2d6f85d95239082efd0e5e2345e685a2c
 */

static void raw_decode(uint8_t *dst, const int8_t *src, int src_size)

{

    while (src_size--)

        *dst++ = *src++ + 128;

}
