/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4260
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c2500635235d809e0c0ac526a7e13072ab7c8900
 */

static int codec_get_buffer(AVCodecContext *s, AVFrame *frame)

{

    InputStream *ist = s->opaque;

    FrameBuffer *buf;

    int ret, i;



    if(av_image_check_size(s->width, s->height, 0, s))

        return -1;



    if (!ist->buffer_pool && (ret = alloc_buffer(s, ist, &ist->buffer_pool)) < 0)

        return ret;



    buf              = ist->buffer_pool;

    ist->buffer_pool = buf->next;

    buf->next        = NULL;

    if (buf->w != s->width || buf->h != s->height || buf->pix_fmt != s->pix_fmt) {

        av_freep(&buf->base[0]);

        av_free(buf);

        ist->dr1 = 0;

        if ((ret = alloc_buffer(s, ist, &buf)) < 0)

            return ret;

    }

    buf->refcount++;



    frame->opaque        = buf;

    frame->type          = FF_BUFFER_TYPE_USER;

    frame->extended_data = frame->data;

    frame->pkt_pts       = s->pkt ? s->pkt->pts : AV_NOPTS_VALUE;



    for (i = 0; i < FF_ARRAY_ELEMS(buf->data); i++) {

        frame->base[i]     = buf->base[i];  // XXX h264.c uses base though it shouldn't

        frame->data[i]     = buf->data[i];

        frame->linesize[i] = buf->linesize[i];

    }



    return 0;

}
