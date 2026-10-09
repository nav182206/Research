/* 
 * Benchmark Sample ID : devign_9829
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6bde1e9d14ff1e0ecff74b8ff59607f545c6f2ec
 */

static int can_merge_formats(AVFilterFormats *a_arg,

                             AVFilterFormats *b_arg,

                             enum AVMediaType type,

                             int is_sample_rate)

{

    AVFilterFormats *a, *b, *ret;

    if (a == b)

        return 1;

    a = clone_filter_formats(a_arg);

    b = clone_filter_formats(b_arg);

    if (is_sample_rate) {

        ret = ff_merge_samplerates(a, b);

    } else {

        ret = ff_merge_formats(a, b, type);

    }

    if (ret) {

        av_freep(&ret->formats);

        av_freep(&ret);

        return 1;

    } else {

        av_freep(&a->formats);

        av_freep(&b->formats);

        av_freep(&a);

        av_freep(&b);

        return 0;

    }

}
