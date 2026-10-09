/* 
 * Benchmark Sample ID : devign_9854
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5e1bf9d8c0d2cdbbf17b06a5dfdf87a635b3203b
 */

static int copy_packet_data(AVPacket *pkt, const AVPacket *src, int dup)

{

    pkt->data      = NULL;

    pkt->side_data = NULL;

    if (pkt->buf) {

        AVBufferRef *ref = av_buffer_ref(src->buf);

        if (!ref)

            return AVERROR(ENOMEM);

        pkt->buf  = ref;

        pkt->data = ref->data;

    } else {

        DUP_DATA(pkt->data, src->data, pkt->size, 1, ALLOC_BUF);

    }

    if (pkt->side_data_elems && dup)

        pkt->side_data = src->side_data;

    if (pkt->side_data_elems && !dup) {

        return av_copy_packet_side_data(pkt, src);

    }

    return 0;



failed_alloc:

    av_packet_unref(pkt);

    return AVERROR(ENOMEM);

}
