/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2556
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=57d24225595af78b0fd836d4d145f5d181e320a2
 */

static int check_recording_time(OutputStream *ost)

{

    OutputFile *of = output_files[ost->file_index];



    if (of->recording_time != INT64_MAX &&

        av_compare_ts(ost->sync_opts - ost->first_pts, ost->st->codec->time_base, of->recording_time,

                      AV_TIME_BASE_Q) >= 0) {

        ost->is_past_recording_time = 1;

        return 0;

    }

    return 1;

}
