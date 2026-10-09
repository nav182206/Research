/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9540
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7ceb9e6b11824ff18f424a35e41fbddf545d1238
 */

int ff_query_formats_all(AVFilterContext *ctx)

{

    return default_query_formats_common(ctx, ff_all_channel_counts);

}
