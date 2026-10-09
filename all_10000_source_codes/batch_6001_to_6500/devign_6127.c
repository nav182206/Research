/* 
 * Benchmark Sample ID : devign_6127
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=db374790c75fa4ef947abcb5019fcf21d0b2de85
 */

static int read_probe(AVProbeData *pd)

{

    if (pd->buf[0] == 'J' && pd->buf[1] == 'V' && strlen(MAGIC) <= pd->buf_size - 4 &&

        !memcmp(pd->buf + 4, MAGIC, strlen(MAGIC)))

        return AVPROBE_SCORE_MAX;

    return 0;

}
