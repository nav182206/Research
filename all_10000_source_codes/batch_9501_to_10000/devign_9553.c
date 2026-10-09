/* 
 * Benchmark Sample ID : devign_9553
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=92e483f8ed70d88d4f64337f65bae212502735d4
 */

static int cmp_intervals(const void *a, const void *b)

{

    const Interval *i1 = a;

    const Interval *i2 = b;

    int64_t ts_diff = i1->start_ts - i2->start_ts;

    int ret;



    ret = ts_diff > 0 ? 1 : ts_diff < 0 ? -1 : 0;

    return ret == 0 ? i1->index - i2->index : ret;

}
