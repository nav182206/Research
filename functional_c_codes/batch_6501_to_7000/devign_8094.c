/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8094
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5d5de3eba4c7890c2e8077f5b4ae569671d11cf8
 */

int ff_v4l2_context_dequeue_packet(V4L2Context* ctx, AVPacket* pkt)

{

    V4L2Buffer* avbuf = NULL;



    /* if we are draining, we are no longer inputing data, therefore enable a

     * timeout so we can dequeue and flag the last valid buffer.

     *

     * blocks until:

     *  1. encoded packet available

     *  2. an input buffer ready to be dequeued

     */

    avbuf = v4l2_dequeue_v4l2buf(ctx, ctx_to_m2mctx(ctx)->draining ? 200 : -1);

    if (!avbuf) {

        if (ctx->done)

            return AVERROR_EOF;



        return AVERROR(EAGAIN);

    }



    return ff_v4l2_buffer_buf_to_avpkt(pkt, avbuf);

}
