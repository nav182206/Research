/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9789
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8696f254444c2ec24daa570f26feadbd3df911e4
 */

static int get_slice_offset(AVCodecContext *avctx, const uint8_t *buf, int n)

{

    if(avctx->slice_count) return avctx->slice_offset[n];

    else                   return AV_RL32(buf + n*8 - 4) == 1 ? AV_RL32(buf + n*8) :  AV_RB32(buf + n*8);

}
