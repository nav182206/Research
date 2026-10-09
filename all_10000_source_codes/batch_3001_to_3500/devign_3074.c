/* 
 * Benchmark Sample ID : devign_3074
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=28f9ab7029bd1a02f659995919f899f84ee7361b
 */

void ff_vp3_idct_add_c(uint8_t *dest/*align 8*/, int line_size, DCTELEM *block/*align 16*/){

    idct(dest, line_size, block, 2);

}
