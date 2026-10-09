/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1230
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=aa06658248a49f6ebf381894b9426cdfb377cd32
 */

static int dvvideo_encode_frame(AVCodecContext *c, uint8_t *buf, int buf_size,

                                void *data)

{

    DVVideoContext *s = c->priv_data;



    s->sys = dv_codec_profile(c);

    if (!s->sys)

        return -1;

    if(buf_size < s->sys->frame_size)

        return -1;



    c->pix_fmt = s->sys->pix_fmt;

    s->picture = *((AVFrame *)data);

    s->picture.key_frame = 1;

    s->picture.pict_type = FF_I_TYPE;



    s->buf = buf;

    c->execute(c, dv_encode_mt, (void**)&s->dv_anchor[0], NULL,

               s->sys->difseg_size * 27);



    emms_c();

    return s->sys->frame_size;

}
