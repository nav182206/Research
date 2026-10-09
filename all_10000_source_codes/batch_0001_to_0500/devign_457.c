/* 
 * Benchmark Sample ID : devign_457
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c51c08e0e70c186971385bdbb225f69edd4e3375
 */

static int decode_recovery_point(H264Context *h)

{

    h->sei_recovery_frame_cnt = get_ue_golomb(&h->gb);



    /* 1b exact_match_flag,

     * 1b broken_link_flag,

     * 2b changing_slice_group_idc */

    skip_bits(&h->gb, 4);



    if (h->avctx->debug & FF_DEBUG_PICT_INFO)

        av_log(h->avctx, AV_LOG_DEBUG, "sei_recovery_frame_cnt: %d\n", h->sei_recovery_frame_cnt);



    h->has_recovery_point = 1;



    return 0;

}
