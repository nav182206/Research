/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6571
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ae2f1d4624dc372aa86f85aeb47f820f48a4af38
 */

static int common_init(AVCodecContext *avctx){

    HYuvContext *s = avctx->priv_data;

    int i;



    s->avctx= avctx;

    s->flags= avctx->flags;

        

    dsputil_init(&s->dsp, avctx);

    

    s->width= avctx->width;

    s->height= avctx->height;

    assert(s->width>0 && s->height>0);

    

    for(i=0; i<3; i++){

        s->temp[i]= av_malloc(avctx->width + 16);

    }

    return 0;

}
