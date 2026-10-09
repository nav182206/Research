/* 
 * Benchmark Sample ID : devign_525
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3ca5df36a50e3ffd3b24734725bf545617a627a8
 */

static void flush(AVCodecContext *avctx)

{

    WmallDecodeCtx *s    = avctx->priv_data;

    s->packet_loss       = 1;

    s->packet_done       = 0;

    s->num_saved_bits    = 0;

    s->frame_offset      = 0;

    s->next_packet_start = 0;

    s->cdlms[0][0].order = 0;

    s->frame.nb_samples  = 0;

    init_put_bits(&s->pb, s->frame_data, MAX_FRAMESIZE);

}
