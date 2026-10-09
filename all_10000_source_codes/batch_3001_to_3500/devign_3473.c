/* 
 * Benchmark Sample ID : devign_3473
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a2f8beef2dfaee573f7c4a607afaa9e83fc2c1e0
 */

static void ffm_set_write_index(AVFormatContext *s, int64_t pos,

                                int64_t file_size)

{

    av_opt_set_int(s, "server_attached", 1, AV_OPT_SEARCH_CHILDREN);

    av_opt_set_int(s, "write_index", pos, AV_OPT_SEARCH_CHILDREN);

    av_opt_set_int(s, "file_size", file_size, AV_OPT_SEARCH_CHILDREN);

}
