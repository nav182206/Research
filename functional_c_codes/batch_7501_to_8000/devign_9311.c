/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9311
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=bb99ae3ae924c942a634bec7711ec7ee11c38eb9
 */

static int init_input(AVFormatContext *s, const char *filename)
{
    int ret;
    AVProbeData pd = {filename, NULL, 0};
    if (s->pb) {
        s->flags |= AVFMT_FLAG_CUSTOM_IO;
        if (!s->iformat)
            return av_probe_input_buffer(s->pb, &s->iformat, filename, s, 0, 0);
        else if (s->iformat->flags & AVFMT_NOFILE)
            av_log(s, AV_LOG_WARNING, "Custom AVIOContext makes no sense and "
                                      "will be ignored with AVFMT_NOFILE format.\n");
    }
    if ( (s->iformat && s->iformat->flags & AVFMT_NOFILE) ||
        (!s->iformat && (s->iformat = av_probe_input_format(&pd, 0))))
    if ((ret = avio_open(&s->pb, filename, AVIO_FLAG_READ)) < 0)
        return ret;
    if (s->iformat)
    return av_probe_input_buffer(s->pb, &s->iformat, filename, s, 0, 0);
}
