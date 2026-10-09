/* 
 * Benchmark Sample ID : devign_6583
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a91394f4de63ae5c2e21c548045b79393ca7fea1
 */

static av_cold int dirac_decode_init(AVCodecContext *avctx)

{

    DiracContext *s = avctx->priv_data;

    int i;



    s->avctx = avctx;

    s->frame_number = -1;



    if (avctx->flags&CODEC_FLAG_EMU_EDGE) {

        av_log(avctx, AV_LOG_ERROR, "Edge emulation not supported!\n");

        return AVERROR_PATCHWELCOME;

    }



    ff_dsputil_init(&s->dsp, avctx);

    ff_diracdsp_init(&s->diracdsp);



    for (i = 0; i < MAX_FRAMES; i++)

        s->all_frames[i].avframe = av_frame_alloc();



    return 0;

}
