/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1827
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=220b24c7c97dc033ceab1510549f66d0e7b52ef1
 */

static unsigned int get_video_format_idx(AVCodecContext *avctx)

{

    unsigned int ret_idx = 0;

    unsigned int idx;

    unsigned int num_formats = sizeof(ff_schro_video_format_info) /

                               sizeof(ff_schro_video_format_info[0]);



    for (idx = 1; idx < num_formats; ++idx) {

        const SchroVideoFormatInfo *vf = &ff_schro_video_format_info[idx];

        if (avctx->width  == vf->width &&

            avctx->height == vf->height) {

            ret_idx = idx;

            if (avctx->time_base.den == vf->frame_rate_num &&

                avctx->time_base.num == vf->frame_rate_denom)

                return idx;

        }

    }

    return ret_idx;

}
