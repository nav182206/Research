/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1198
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=783b350b2e49d06030b30ee9b7e1aa5825e4a5a5
 */

static av_cold int decode_close_mp3on4(AVCodecContext * avctx)
{
    MP3On4DecodeContext *s = avctx->priv_data;
    int i;
    for (i = 0; i < s->frames; i++)
        av_freep(&s->mp3decctx[i]);
    return 0;
}
