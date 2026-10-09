/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5796
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e9064c9ce8ed18c3a3aab61e58e663b8f5b0c551
 */

static void cmv_decode_intra(CmvContext * s, const uint8_t *buf, const uint8_t *buf_end){

    unsigned char *dst = s->frame.data[0];

    int i;



    for (i=0; i < s->avctx->height && buf+s->avctx->width<=buf_end; i++) {

        memcpy(dst, buf, s->avctx->width);

        dst += s->frame.linesize[0];

        buf += s->avctx->width;

    }

}
