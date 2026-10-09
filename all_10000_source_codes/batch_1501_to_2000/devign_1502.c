/* 
 * Benchmark Sample ID : devign_1502
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4c7b023d56e09a78a587d036db1b64bf7c493b3d
 */

static int nvdec_mpeg12_end_frame(AVCodecContext *avctx)

{

    NVDECContext *ctx = avctx->internal->hwaccel_priv_data;

    int ret = ff_nvdec_end_frame(avctx);

    ctx->bitstream = NULL;

    return ret;

}
