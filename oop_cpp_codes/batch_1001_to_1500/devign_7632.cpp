/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_7632
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=65db4899fa8790049bec3af16ecdb75dd81051fd
 */

static int ffmmal_fill_input_port(AVCodecContext *avctx)

{

    MMALDecodeContext *ctx = avctx->priv_data;



    while (ctx->waiting_buffers) {

        MMAL_BUFFER_HEADER_T *mbuffer;

        FFBufferEntry *buffer;

        MMAL_STATUS_T status;



        mbuffer = mmal_queue_get(ctx->pool_in->queue);

        if (!mbuffer)

            return 0;



        buffer = ctx->waiting_buffers;



        mmal_buffer_header_reset(mbuffer);

        mbuffer->cmd = 0;

        mbuffer->pts = buffer->pts;

        mbuffer->dts = buffer->dts;

        mbuffer->flags = buffer->flags;

        mbuffer->data = buffer->data;

        mbuffer->length = buffer->length;

        mbuffer->user_data = buffer->ref;

        mbuffer->alloc_size = ctx->decoder->input[0]->buffer_size;



        if ((status = mmal_port_send_buffer(ctx->decoder->input[0], mbuffer))) {

            mmal_buffer_header_release(mbuffer);

            av_buffer_unref(&buffer->ref);

        }



        // Remove from start of the list

        ctx->waiting_buffers = buffer->next;

        if (ctx->waiting_buffers_tail == buffer)

            ctx->waiting_buffers_tail = NULL;

        av_free(buffer);



        if (status) {

            av_log(avctx, AV_LOG_ERROR, "MMAL error %d when sending input\n", (int)status);

            return AVERROR_UNKNOWN;

        }

    }



    return 0;

}
