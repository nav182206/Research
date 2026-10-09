/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_757
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8425d693eefbedbb41f91735614d41067695aa37
 */

static int flac_probe(AVProbeData *p)

{

    uint8_t *bufptr = p->buf;

    uint8_t *end    = p->buf + p->buf_size;



    if(bufptr > end-4 || memcmp(bufptr, "fLaC", 4)) return 0;

    else                                            return AVPROBE_SCORE_MAX/2;

}
