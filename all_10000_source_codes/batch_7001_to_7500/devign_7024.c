/* 
 * Benchmark Sample ID : devign_7024
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8689d87ac61a412b88326c4d31a8f3375926f869
 */

static int matroska_read_packet(AVFormatContext *s, AVPacket *pkt)

{

    MatroskaDemuxContext *matroska = s->priv_data;

    int ret = 0;



    while (!ret && matroska_deliver_packet(matroska, pkt)) {

        if (matroska->done)

            return AVERROR_EOF;

        ret = matroska_parse_cluster(matroska);

    }



    return ret;

}
