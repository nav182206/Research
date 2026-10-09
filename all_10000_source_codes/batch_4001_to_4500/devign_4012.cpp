/* 
 * Benchmark Sample ID : devign_4012
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=340b7caf5457b2988bfd53709a00cedc2fcd73b7
 */

static int hls_start(AVFormatContext *s)

{

    HLSContext *c = s->priv_data;

    AVFormatContext *oc = c->avf;

    int err = 0;



    if (c->wrap)

        c->number %= c->wrap;



    if (av_get_frame_filename(oc->filename, sizeof(oc->filename),

                              c->basename, c->number++) < 0)

        return AVERROR(EINVAL);



    if ((err = avio_open2(&oc->pb, oc->filename, AVIO_FLAG_WRITE,

                          &s->interrupt_callback, NULL)) < 0)

        return err;



    if (oc->oformat->priv_class && oc->priv_data)

        av_opt_set(oc->priv_data, "mpegts_flags", "resend_headers", 0);



    return 0;

}
