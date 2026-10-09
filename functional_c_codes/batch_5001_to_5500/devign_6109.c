/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6109
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=76170f537304cc845d6d334d36daa0a0f16efb32
 */

static int yop_probe(AVProbeData *probe_packet)

{

    if (AV_RB16(probe_packet->buf) == AV_RB16("YO")  &&

        probe_packet->buf[6]                         &&

        probe_packet->buf[7]                         &&

        !(probe_packet->buf[8] & 1)                  &&

        !(probe_packet->buf[10] & 1))

        return AVPROBE_SCORE_MAX * 3 / 4;



    return 0;

}
