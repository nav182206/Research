/* 
 * Benchmark Sample ID : devign_1351
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d1adad3cca407f493c3637e20ecd4f7124e69212
 */

static inline void RENAME(hyscale)(SwsContext *c, uint16_t *dst, long dstWidth, const uint8_t *src, int srcW, int xInc,

                                   const int16_t *hLumFilter,

                                   const int16_t *hLumFilterPos, int hLumFilterSize,

                                   uint8_t *formatConvBuffer,

                                   uint32_t *pal, int isAlpha)

{

    void (*toYV12)(uint8_t *, const uint8_t *, long, uint32_t *) = isAlpha ? c->alpToYV12 : c->lumToYV12;

    void (*convertRange)(int16_t *, int) = isAlpha ? NULL : c->lumConvertRange;



    src += isAlpha ? c->alpSrcOffset : c->lumSrcOffset;



    if (toYV12) {

        toYV12(formatConvBuffer, src, srcW, pal);

        src= formatConvBuffer;

    }



    if (c->hScale16) {

        c->hScale16(dst, dstWidth, (uint16_t*)src, srcW, xInc, hLumFilter, hLumFilterPos, hLumFilterSize, av_pix_fmt_descriptors[c->srcFormat].comp[0].depth_minus1);

    } else if (!c->hyscale_fast) {

        c->hScale(dst, dstWidth, src, srcW, xInc, hLumFilter, hLumFilterPos, hLumFilterSize);

    } else { // fast bilinear upscale / crap downscale

        c->hyscale_fast(c, dst, dstWidth, src, srcW, xInc);

    }



    if (convertRange)

        convertRange(dst, dstWidth);

}
