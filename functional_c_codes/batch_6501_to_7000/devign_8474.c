/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8474
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a38469e1da7b4829a2fba4279d8420a33f96832e
 */

int read_ffserver_streams(AVFormatContext *s, const char *filename)

{

    int i;

    AVFormatContext *ic;



    ic = av_open_input_file(filename, FFM_PACKET_SIZE);

    if (!ic)

        return -EIO;

    /* copy stream format */

    s->nb_streams = ic->nb_streams;

    for(i=0;i<ic->nb_streams;i++) {

        AVStream *st;

        st = av_mallocz(sizeof(AVFormatContext));

        memcpy(st, ic->streams[i], sizeof(AVStream));

        s->streams[i] = st;

    }



    av_close_input_file(ic);

    return 0;

}
