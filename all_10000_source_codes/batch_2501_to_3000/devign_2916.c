/* 
 * Benchmark Sample ID : devign_2916
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=83f238cbf0c038245d2b2dffa5beb0916e7c36d2
 */

static void arm_idct_add(UINT8 *dest, int line_size, DCTELEM *block)

{

    j_rev_dct_ARM (block);

    add_pixels_clamped(block, dest, line_size);

}
