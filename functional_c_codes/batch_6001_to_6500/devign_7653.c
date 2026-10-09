/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7653
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6abc56e892c2c2500d1fc2698fa6d580b72f721b
 */

static int shall_we_drop(AVFormatContext *s)

{

    struct dshow_ctx *ctx = s->priv_data;

    static const uint8_t dropscore[] = {62, 75, 87, 100};

    const int ndropscores = FF_ARRAY_ELEMS(dropscore);

    unsigned int buffer_fullness = (ctx->curbufsize*100)/s->max_picture_buffer;



    if(dropscore[++ctx->video_frame_num%ndropscores] <= buffer_fullness) {

        av_log(s, AV_LOG_ERROR,

              "real-time buffer %d%% full! frame dropped!\n", buffer_fullness);

        return 1;

    }



    return 0;

}
