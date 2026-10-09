/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1177
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ded5957d75def70d2f1fc1c1eae079230004974b
 */

static int film_read_close(AVFormatContext *s)

{

    FilmDemuxContext *film = s->priv_data;



    av_freep(&film->sample_table);

    av_freep(&film->stereo_buffer);



    return 0;

}
