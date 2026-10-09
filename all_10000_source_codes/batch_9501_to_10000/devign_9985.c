/* 
 * Benchmark Sample ID : devign_9985
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8731c86d03d062ad19f098b77ab1f1bc4ad7c406
 */

static int a64_write_trailer(struct AVFormatContext *s)

{

    A64MuxerContext *c = s->priv_data;

    AVPacket pkt;

    /* need to flush last packet? */

    if(c->interleaved) a64_write_packet(s, &pkt);

    return 0;

}
