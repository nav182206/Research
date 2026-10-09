/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_364
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d6604b29ef544793479d7fb4e05ef6622bb3e534
 */

static av_cold int encode_close(AVCodecContext* avc_context)

{

    TheoraContext *h = avc_context->priv_data;



    th_encode_free(h->t_state);

    av_freep(&h->stats);

    av_freep(&avc_context->coded_frame);

    av_freep(&avc_context->stats_out);

    av_freep(&avc_context->extradata);

    avc_context->extradata_size = 0;



    return 0;

}
