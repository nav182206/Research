/* 
 * Benchmark Sample ID : devign_8705
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a9d4a6ef3437d316450c2e30b9ed6a8fd4df4804
 */

static int rm_read_header_old(AVFormatContext *s, AVFormatParameters *ap)

{

    RMContext *rm = s->priv_data;

    AVStream *st;



    rm->old_format = 1;

    st = av_new_stream(s, 0);

    if (!st)

        goto fail;

    rm_read_audio_stream_info(s, st, 1);

    return 0;

 fail:

    return -1;

}
