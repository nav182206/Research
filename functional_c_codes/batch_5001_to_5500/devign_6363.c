/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6363
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e549933a270dd2cfc36f2cf9bb6b29acf3dc6d08
 */

static void avc_luma_mid_16w_msa(const uint8_t *src, int32_t src_stride,

                                 uint8_t *dst, int32_t dst_stride,

                                 int32_t height)

{

    uint32_t multiple8_cnt;



    for (multiple8_cnt = 2; multiple8_cnt--;) {

        avc_luma_mid_8w_msa(src, src_stride, dst, dst_stride, height);

        src += 8;

        dst += 8;

    }

}
