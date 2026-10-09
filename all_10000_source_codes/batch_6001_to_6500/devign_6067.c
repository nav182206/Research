/* 
 * Benchmark Sample ID : devign_6067
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f15c4281dcabeddb61cb6430e0cc1047173292f8
 */

static av_cold int oggvorbis_encode_close(AVCodecContext *avctx)

{

    OggVorbisContext *s = avctx->priv_data;



    /* notify vorbisenc this is EOF */

    vorbis_analysis_wrote(&s->vd, 0);



    vorbis_block_clear(&s->vb);

    vorbis_dsp_clear(&s->vd);

    vorbis_info_clear(&s->vi);



    av_freep(&avctx->coded_frame);

    av_freep(&avctx->extradata);



    return 0;

}
