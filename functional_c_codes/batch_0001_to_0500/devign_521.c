/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_521
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a9f9b7f5c70e80245983e67b8ed23212d9637645
 */

static int mov_text_decode_close(AVCodecContext *avctx)

{

    MovTextContext *m = avctx->priv_data;

    mov_text_cleanup_ftab(m);


    return 0;

}
