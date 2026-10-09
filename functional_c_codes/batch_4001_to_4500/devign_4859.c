/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4859
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0c6b9b9fe5edb7b4307e1705bac7f1087262a6fb
 */

static inline int read_line(AVFormatContext *s, char *rbuf, const int rbufsize,

                            int *rbuflen)

{

    RTSPState *rt = s->priv_data;

    int idx       = 0;

    int ret       = 0;

    *rbuflen      = 0;



    do {

        ret = ffurl_read_complete(rt->rtsp_hd, rbuf + idx, 1);

        if (ret < 0)

            return ret;

        if (rbuf[idx] == '\r') {

            /* Ignore */

        } else if (rbuf[idx] == '\n') {

            rbuf[idx] = '\0';

            *rbuflen  = idx;

            return 0;

        } else

            idx++;

    } while (idx < rbufsize);

    av_log(s, AV_LOG_ERROR, "Message too long\n");

    return AVERROR(EIO);

}
