/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1891
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=32baeafeee4f8446c2c3720b9223ad2166ca9d30
 */

void ff_jref_idct_put(uint8_t *dest, ptrdiff_t line_size, int16_t *block)

{

    ff_j_rev_dct(block);

    ff_put_pixels_clamped(block, dest, line_size);

}
