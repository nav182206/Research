/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3964
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7e7e59409294af9caa63808e56c5cc824c98b4fc
 */

static inline unsigned char gif_clut_index(uint8_t r, uint8_t g, uint8_t b)

{

    return ((((r)/47)%6)*6*6+(((g)/47)%6)*6+(((b)/47)%6));

}
