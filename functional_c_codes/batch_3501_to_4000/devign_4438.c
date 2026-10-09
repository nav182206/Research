/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4438
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f9d7e9feec2a0fd7f7930d01876a70a9b8a4a3b9
 */

static int tee_write_trailer(AVFormatContext *avf)

{

    TeeContext *tee = avf->priv_data;

    AVFormatContext *avf2;

    int ret_all = 0, ret;

    unsigned i;



    for (i = 0; i < tee->nb_slaves; i++) {

        avf2 = tee->slaves[i].avf;

        if ((ret = av_write_trailer(avf2)) < 0)

            if (!ret_all)

                ret_all = ret;

        if (!(avf2->oformat->flags & AVFMT_NOFILE))

            ff_format_io_close(avf2, &avf2->pb);

    }

    close_slaves(avf);

    return ret_all;

}
