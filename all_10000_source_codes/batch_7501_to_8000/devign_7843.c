/* 
 * Benchmark Sample ID : devign_7843
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6abc56e892c2c2500d1fc2698fa6d580b72f721b
 */

static int dshow_read_packet(AVFormatContext *s, AVPacket *pkt)

{

    struct dshow_ctx *ctx = s->priv_data;

    AVPacketList *pktl = NULL;



    while (!ctx->eof && !pktl) {

        WaitForSingleObject(ctx->mutex, INFINITE);

        pktl = ctx->pktl;

        if (pktl) {

            *pkt = pktl->pkt;

            ctx->pktl = ctx->pktl->next;

            av_free(pktl);

            ctx->curbufsize -= pkt->size;

        }

        ResetEvent(ctx->event[1]);

        ReleaseMutex(ctx->mutex);

        if (!pktl) {

            if (dshow_check_event_queue(ctx->media_event) < 0) {

                ctx->eof = 1;

            } else if (s->flags & AVFMT_FLAG_NONBLOCK) {

                return AVERROR(EAGAIN);

            } else {

                WaitForMultipleObjects(2, ctx->event, 0, INFINITE);

            }

        }

    }



    return ctx->eof ? AVERROR(EIO) : pkt->size;

}
