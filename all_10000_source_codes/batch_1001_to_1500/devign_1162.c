/* 
 * Benchmark Sample ID : devign_1162
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d9cdb7d8d6d828bb5497ea3f0fd7edd2f3f6cc30
 */

static av_cold int pcm_dvd_decode_init(AVCodecContext *avctx)

{

    PCMDVDContext *s = avctx->priv_data;



    /* Invalid header to force parsing of the first header */

    s->last_header = -1;

    /* reserve space for 8 channels, 3 bytes/sample, 4 samples/block */

    if (!(s->extra_samples = av_malloc(8 * 3 * 4)))

        return AVERROR(ENOMEM);

    s->extra_sample_count = 0;



    return 0;

}
