/* 
 * Benchmark Sample ID : devign_7347
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=dcd913d9ed6c15ea53882894baa343695575abcd
 */

static void mpegts_close_filter(MpegTSContext *ts, MpegTSFilter *filter)

{

    int pid;



    pid = filter->pid;

    if (filter->type == MPEGTS_SECTION)

        av_freep(&filter->u.section_filter.section_buf);










    av_free(filter);

    ts->pids[pid] = NULL;
