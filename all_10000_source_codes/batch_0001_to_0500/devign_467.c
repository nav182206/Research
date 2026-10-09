/* 
 * Benchmark Sample ID : devign_467
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=87e8788680e16c51f6048af26f3f7830c35207a5
 */

static int vid_probe(AVProbeData *p)

{

    // little endian VID tag, file starts with "VID\0"

    if (p->buf_size < 4 || AV_RL32(p->buf) != MKTAG('V', 'I', 'D', 0))

        return 0;



    return AVPROBE_SCORE_MAX;

}
