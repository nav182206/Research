/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2724
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e2d1eace00a80c4b53998397d38ea4e08c5d47f0
 */

static int adx_decode_header(AVCodecContext *avctx, const uint8_t *buf,

                             int bufsize)

{

    int offset;



    if (buf[0] != 0x80)

        return 0;

    offset = (AV_RB32(buf) ^ 0x80000000) + 4;

    if (bufsize < offset || memcmp(buf + offset - 6, "(c)CRI", 6))

        return 0;



    avctx->channels    = buf[7];

    avctx->sample_rate = AV_RB32(buf + 8);

    avctx->bit_rate    = avctx->sample_rate * avctx->channels * 18 * 8 / 32;



    return offset;

}
