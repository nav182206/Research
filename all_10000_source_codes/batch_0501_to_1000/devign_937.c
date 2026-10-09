/* 
 * Benchmark Sample ID : devign_937
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2ea38a946dbd7c4528f5729f494758cfad491fa8
 */

static int av_always_inline mlp_thd_probe(AVProbeData *p, uint32_t sync)

{

    const uint8_t *buf, *last_buf = p->buf, *end = p->buf + p->buf_size;

    int frames = 0, valid = 0, size = 0;



    for (buf = p->buf; buf + 8 <= end; buf++) {

        if (AV_RB32(buf + 4) == sync) {

            frames++;

            if (last_buf + size == buf) {

                valid++;

            }

            last_buf = buf;

            size = (AV_RB16(buf) & 0xfff) * 2;

        } else if (buf - last_buf == size) {

            size += (AV_RB16(buf) & 0xfff) * 2;

        }

    }

    if (valid >= 100)

        return AVPROBE_SCORE_MAX;

    return 0;

}
