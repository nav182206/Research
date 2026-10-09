/* 
 * Benchmark Sample ID : devign_9687
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=85f477935cd6b34e6ec2716b20e15ce748277a89
 */

static av_cold int avs_decode_init(AVCodecContext * avctx)

{

    avctx->pix_fmt = PIX_FMT_PAL8;


    return 0;

}
