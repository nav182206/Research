/* 
 * Benchmark Sample ID : devign_8886
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d6604b29ef544793479d7fb4e05ef6622bb3e534
 */

static av_cold int qtrle_encode_end(AVCodecContext *avctx)

{

    QtrleEncContext *s = avctx->priv_data;



    av_frame_free(&avctx->coded_frame);



    avpicture_free(&s->previous_frame);

    av_free(s->rlecode_table);

    av_free(s->length_table);

    av_free(s->skip_table);

    return 0;

}
