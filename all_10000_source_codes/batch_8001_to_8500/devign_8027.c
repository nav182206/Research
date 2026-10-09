/* 
 * Benchmark Sample ID : devign_8027
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d319064465e148b8adb53d1ea5d38c09f987056e
 */

void uninit_opts(void)

{

    int i;

    for (i = 0; i < AVMEDIA_TYPE_NB; i++)

        av_freep(&avcodec_opts[i]);

    av_freep(&avformat_opts->key);

    av_freep(&avformat_opts);

#if CONFIG_SWSCALE

    av_freep(&sws_opts);

#endif

    for (i = 0; i < opt_name_count; i++) {

        //opt_values are only stored for codec-specific options in which case

        //both the name and value are dup'd

        if (opt_values[i]) {

            av_freep(&opt_names[i]);

            av_freep(&opt_values[i]);

        }

    }

    av_freep(&opt_names);

    av_freep(&opt_values);

}
