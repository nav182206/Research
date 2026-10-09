/* 
 * Benchmark Sample ID : devign_4993
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=caf7be30b11288c498fae67be4741bfbf083d977
 */

static int mpjpeg_read_probe(AVProbeData *p)

{

    AVIOContext *pb;

    char line[128] = { 0 };

    int ret = 0;



    pb = avio_alloc_context(p->buf, p->buf_size, 0, NULL, NULL, NULL, NULL);

    if (!pb)

        return AVERROR(ENOMEM);



    if (p->buf_size < 2 || p->buf[0] != '-' || p->buf[1] != '-')

        return 0;



    while (!pb->eof_reached) {

        ret = get_line(pb, line, sizeof(line));

        if (ret < 0)

            break;



        ret = check_content_type(line);

        if (!ret) {

            ret = AVPROBE_SCORE_MAX;

            break;

        }

    }



    av_free(pb);



    return ret;

}
