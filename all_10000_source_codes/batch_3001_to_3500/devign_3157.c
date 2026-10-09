/* 
 * Benchmark Sample ID : devign_3157
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a717f9904227d7979473bad40c50eb40af41d01d
 */

static int mpegts_read_close(AVFormatContext *s)

{

    MpegTSContext *ts = s->priv_data;

    int i;



    clear_programs(ts);



    for(i=0;i<NB_PID_MAX;i++)

        if (ts->pids[i]) mpegts_close_filter(ts, ts->pids[i]);



    return 0;

}
