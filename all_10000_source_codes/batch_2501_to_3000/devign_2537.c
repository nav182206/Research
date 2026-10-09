/* 
 * Benchmark Sample ID : devign_2537
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=530eb6acf8ee867bf00728bf7efaf505da107e17
 */

static int hls_write_trailer(struct AVFormatContext *s)

{

    HLSContext *hls = s->priv_data;

    AVFormatContext *oc = hls->avf;



    av_write_trailer(oc);

    hls->size = avio_tell(hls->avf->pb) - hls->start_pos;

    avio_closep(&oc->pb);

    avformat_free_context(oc);

    av_free(hls->basename);

    hls_append_segment(hls, hls->duration, hls->start_pos, hls->size);

    hls_window(s, 1);



    hls_free_segments(hls);

    avio_close(hls->pb);

    return 0;

}
