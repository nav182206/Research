/* 
 * Benchmark Sample ID : devign_1082
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=56e2cd9c042e05255aa28487694c29aaec023263
 */

static int probe(AVProbeData *p)

{

    unsigned i, frames, checked = 0;



    if (p->buf_size < 22 || AV_RL16(p->buf) || AV_RL16(p->buf + 2) != 1)

        return 0;

    frames = AV_RL16(p->buf + 4);

    if (!frames)

        return 0;

    for (i = 0; i < frames && i * 16 + 22 <= p->buf_size; i++) {

        unsigned offset;

        if (AV_RL16(p->buf + 10 + i * 16) & ~1)

            return FFMIN(i, AVPROBE_SCORE_MAX / 4);

        if (p->buf[13 + i * 16])

            return FFMIN(i, AVPROBE_SCORE_MAX / 4);

        if (AV_RL32(p->buf + 14 + i * 16) < 40)

            return FFMIN(i, AVPROBE_SCORE_MAX / 4);

        offset = AV_RL32(p->buf + 18 + i * 16);

        if (offset < 22)

            return FFMIN(i, AVPROBE_SCORE_MAX / 4);

        if (offset + 8 > p->buf_size)

            continue;

        if (p->buf[offset] != 40 && AV_RB64(p->buf + offset) != PNGSIG)

            return FFMIN(i, AVPROBE_SCORE_MAX / 4);

        checked++;

    }



    if (checked < frames)

        return AVPROBE_SCORE_MAX / 4 + FFMIN(checked, 1);

    return AVPROBE_SCORE_MAX / 2 + 1;

}
