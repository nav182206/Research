/* 
 * Benchmark Sample ID : devign_3269
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=56e11ebf55a5e51a8a7131d382c2020e35d34f42
 */

static av_cold int encode_close(AVCodecContext *avctx)

{

    if (avctx->priv_data) {

        DCAEncContext *c = avctx->priv_data;

        subband_bufer_free(c);

        ff_dcaadpcm_free(&c->adpcm_ctx);

    }

    return 0;

}
