/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6183
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=16c429166ddf1736972b6ccce84bd3509ec16a34
 */

static int apng_read_close(AVFormatContext *s)

{

    APNGDemuxContext *ctx = s->priv_data;

    av_freep(&ctx->extra_data);

    ctx->extra_data_size = 0;

    return 0;

}
