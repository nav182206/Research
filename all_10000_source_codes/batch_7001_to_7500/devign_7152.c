/* 
 * Benchmark Sample ID : devign_7152
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3b199d29cd597a3518136d78860e172060b9e83d
 */

static av_cold int cinvideo_decode_init(AVCodecContext *avctx)

{

    CinVideoContext *cin = avctx->priv_data;

    unsigned int i;



    cin->avctx = avctx;

    avctx->pix_fmt = AV_PIX_FMT_PAL8;



    cin->frame.data[0] = NULL;



    cin->bitmap_size = avctx->width * avctx->height;

    for (i = 0; i < 3; ++i) {

        cin->bitmap_table[i] = av_mallocz(cin->bitmap_size);

        if (!cin->bitmap_table[i])

            av_log(avctx, AV_LOG_ERROR, "Can't allocate bitmap buffers.\n");

    }



    return 0;

}
