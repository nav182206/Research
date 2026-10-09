/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7635
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=cbba331aa02f29870581ff0b7ded7477b279ae2c
 */

static void writer_print_ts(WriterContext *wctx, const char *key, int64_t ts, int is_duration)

{

    if ((!is_duration && ts == AV_NOPTS_VALUE) || (is_duration && ts == 0)) {

        writer_print_string(wctx, key, "N/A", 1);

    } else {

        writer_print_integer(wctx, key, ts);

    }

}
