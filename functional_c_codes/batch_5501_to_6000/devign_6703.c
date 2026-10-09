/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6703
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ac4b32df71bd932838043a4838b86d11e169707f
 */

static void vp8_idct_dc_add4y_c(uint8_t *dst, int16_t block[4][16],

                                ptrdiff_t stride)

{

    vp8_idct_dc_add_c(dst +  0, block[0], stride);

    vp8_idct_dc_add_c(dst +  4, block[1], stride);

    vp8_idct_dc_add_c(dst +  8, block[2], stride);

    vp8_idct_dc_add_c(dst + 12, block[3], stride);

}
