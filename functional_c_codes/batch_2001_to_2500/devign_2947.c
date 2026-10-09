/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2947
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=73bb8f61d48dbf7237df2e9cacd037f12b84b00a
 */

static void FUNC(hevc_v_loop_filter_luma)(uint8_t *pix, ptrdiff_t stride,

                                          int *beta, int *tc, uint8_t *no_p,

                                          uint8_t *no_q)

{

    FUNC(hevc_loop_filter_luma)(pix, sizeof(pixel), stride,

                                beta, tc, no_p, no_q);

}
