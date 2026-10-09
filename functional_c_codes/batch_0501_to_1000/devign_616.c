/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_616
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3b199d29cd597a3518136d78860e172060b9e83d
 */

static av_cold int seqvideo_decode_init(AVCodecContext *avctx)

{

    SeqVideoContext *seq = avctx->priv_data;



    seq->avctx = avctx;

    avctx->pix_fmt = AV_PIX_FMT_PAL8;



    seq->frame.data[0] = NULL;



    return 0;

}
