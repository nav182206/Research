/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7808
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e3fc4481b6dd60acdb9f3e370ee9a1d1bd4ddd73
 */

static int vqf_probe(AVProbeData *probe_packet)
{
    if (AV_RL32(probe_packet->buf) != MKTAG('T','W','I','N'))
        return 0;
    if (!memcmp(probe_packet->buf + 4, "97012000", 8))
        return AVPROBE_SCORE_MAX;
    if (!memcmp(probe_packet->buf + 4, "00052200", 8))
        return AVPROBE_SCORE_MAX;
    return AVPROBE_SCORE_EXTENSION;
}
