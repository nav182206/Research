/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4235
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=dc179ec81902e3c9d327f9e818454f2849308000
 */

void ff_sws_init_swScale_altivec(SwsContext *c)

{

    enum PixelFormat dstFormat = c->dstFormat;



    if (!(av_get_cpu_flags() & AV_CPU_FLAG_ALTIVEC))

        return;



    c->hScale       = hScale_altivec_real;

    if (!is16BPS(dstFormat) && !is9_OR_10BPS(dstFormat)) {

        c->yuv2yuvX     = yuv2yuvX_altivec_real;

    }



    /* The following list of supported dstFormat values should

     * match what's found in the body of ff_yuv2packedX_altivec() */

    if (!(c->flags & (SWS_BITEXACT | SWS_FULL_CHR_H_INT)) && !c->alpPixBuf &&

        (c->dstFormat==PIX_FMT_ABGR  || c->dstFormat==PIX_FMT_BGRA  ||

         c->dstFormat==PIX_FMT_BGR24 || c->dstFormat==PIX_FMT_RGB24 ||

         c->dstFormat==PIX_FMT_RGBA  || c->dstFormat==PIX_FMT_ARGB)) {

            c->yuv2packedX  = ff_yuv2packedX_altivec;

        }

}
