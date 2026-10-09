/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3873
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=dc0ad40de2b0d6995eb842e56b22f9096bd539ff
 */

static void ac3_update_bap_counts_c(uint16_t mant_cnt[16], uint8_t *bap,

                                    int len)

{

    while (len-- >= 0)

        mant_cnt[bap[len]]++;

}
