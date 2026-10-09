/* 
 * Benchmark Sample ID : devign_9559
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d6604b29ef544793479d7fb4e05ef6622bb3e534
 */

static av_cold int flashsv_encode_end(AVCodecContext *avctx)

{

    FlashSVContext *s = avctx->priv_data;



    deflateEnd(&s->zstream);



    av_free(s->encbuffer);

    av_free(s->previous_frame);

    av_free(s->tmpblock);



    av_frame_free(&avctx->coded_frame);



    return 0;

}
