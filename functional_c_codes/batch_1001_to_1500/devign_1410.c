/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1410
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=31c3a4dc7e15f993b0076c7231f80249a55ea146
 */

static int avcodec_find_best_pix_fmt1(int64_t pix_fmt_mask,

                                      int src_pix_fmt,

                                      int has_alpha,

                                      int loss_mask)

{

    int dist, i, loss, min_dist, dst_pix_fmt;



    /* find exact color match with smallest size */

    dst_pix_fmt = -1;

    min_dist = 0x7fffffff;

    for(i = 0;i < PIX_FMT_NB; i++) {

        if (pix_fmt_mask & (1 << i)) {

            loss = avcodec_get_pix_fmt_loss(i, src_pix_fmt, has_alpha) & loss_mask;

            if (loss == 0) {

                dist = avg_bits_per_pixel(i);

                if (dist < min_dist) {

                    min_dist = dist;

                    dst_pix_fmt = i;

                }

            }

        }

    }

    return dst_pix_fmt;

}
