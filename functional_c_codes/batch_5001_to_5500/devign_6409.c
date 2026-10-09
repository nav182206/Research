/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6409
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5c8467a07c654f6acd9e8e3a436cd5b746bb2f44
 */

static int ivf_write_trailer(AVFormatContext *s)

{

    AVIOContext *pb = s->pb;

    if (pb->seekable) {

        IVFEncContext *ctx = s->priv_data;

        size_t end = avio_tell(pb);



        avio_seek(pb, 24, SEEK_SET);

        avio_wl64(pb, ctx->frame_cnt * ctx->sum_delta_pts / (ctx->frame_cnt - 1));

        avio_seek(pb, end, SEEK_SET);

    }



    return 0;

}
