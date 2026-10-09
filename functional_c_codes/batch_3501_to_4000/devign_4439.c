/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4439
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2cface71ca58b1ab811efae7d22f3264f362f672
 */

static int write_trailer(AVFormatContext *s){

    NUTContext *nut= s->priv_data;

    AVIOContext *bc= s->pb;



    while(nut->header_count<3)

        write_headers(s, bc);

    avio_flush(bc);

    ff_nut_free_sp(nut);

    av_freep(&nut->stream);


    av_freep(&nut->time_base);



    return 0;

}
