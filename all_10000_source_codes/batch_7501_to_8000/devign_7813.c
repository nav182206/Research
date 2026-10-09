/* 
 * Benchmark Sample ID : devign_7813
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=34a8dcd031d637273cdea021e5a79cf720c4c51c
 */

static int decode_end(AVCodecContext *avctx)

{

    SmackVContext * const smk = (SmackVContext *)avctx->priv_data;



    if(smk->mmap_tbl)

        av_free(smk->mmap_tbl);

    if(smk->mclr_tbl)

        av_free(smk->mclr_tbl);

    if(smk->full_tbl)

        av_free(smk->full_tbl);

    if(smk->type_tbl)

        av_free(smk->type_tbl);



    if (smk->pic.data[0])

        avctx->release_buffer(avctx, &smk->pic);



    return 0;

}
