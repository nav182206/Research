/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7340
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6f1ccca4ae3b93b6a2a820a7a0e72081ab35767c
 */

static int dnxhd_decode_dct_block_10(const DNXHDContext *ctx,

                                     RowContext *row, int n)

{

    return dnxhd_decode_dct_block(ctx, row, n, 6, 8, 4);

}
