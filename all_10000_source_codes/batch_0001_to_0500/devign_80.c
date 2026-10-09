/* 
 * Benchmark Sample ID : devign_80
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=269fc8e04906ffd965aa19425ca90980b23c6508
 */

static int write_trailer(AVFormatContext *s)

{

    WVMuxContext *wc = s->priv_data;

    AVIOContext *pb = s->pb;



    ff_ape_write(s);



    if (pb->seekable) {

        avio_seek(pb, 12, SEEK_SET);

        avio_wl32(pb, wc->duration);

        avio_flush(pb);

    }



    return 0;

}
