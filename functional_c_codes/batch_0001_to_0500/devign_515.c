/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_515
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2217a2249dd78c3719f865569b661b8adcda4962
 */

static void encode_rgb48_10bit(AVCodecContext *avctx, const AVPicture *pic, uint8_t *dst)

{

    DPXContext *s = avctx->priv_data;

    const uint8_t *src = pic->data[0];

    int x, y;



    for (y = 0; y < avctx->height; y++) {

        for (x = 0; x < avctx->width; x++) {

            int value;

            if (s->big_endian) {

                value = ((AV_RB16(src + 6*x + 4) & 0xFFC0) >> 4)

                      | ((AV_RB16(src + 6*x + 2) & 0xFFC0) << 6)

                      | ((AV_RB16(src + 6*x + 0) & 0xFFC0) << 16);

            } else {

                value = ((AV_RL16(src + 6*x + 4) & 0xFFC0) >> 4)

                      | ((AV_RL16(src + 6*x + 2) & 0xFFC0) << 6)

                      | ((AV_RL16(src + 6*x + 0) & 0xFFC0) << 16);

            }

            write32(dst, value);

            dst += 4;

        }

        src += pic->linesize[0];

    }

}
