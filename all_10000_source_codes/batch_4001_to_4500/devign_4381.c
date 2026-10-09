/* 
 * Benchmark Sample ID : devign_4381
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f800d6508d7e8fbd8d9777b775d333a4f02112ef
 */

static av_cold int dnxhd_decode_init_thread_copy(AVCodecContext *avctx)

{

    DNXHDContext *ctx = avctx->priv_data;




    // make sure VLC tables will be loaded when cid is parsed

    ctx->cid = -1;



    ctx->rows = av_mallocz_array(avctx->thread_count, sizeof(RowContext));

    if (!ctx->rows)

        return AVERROR(ENOMEM);



    return 0;

}
