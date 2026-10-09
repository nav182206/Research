/* 
 * Benchmark Sample ID : devign_1216
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e2ad0b66fa273c5c823978e8f601f2c0d9ee42f8
 */

int avpicture_get_size(enum AVPixelFormat pix_fmt, int width, int height)

{

    const AVPixFmtDescriptor *desc = av_pix_fmt_desc_get(pix_fmt);

    AVPicture dummy_pict;

    int ret;



    if (!desc)

        return AVERROR(EINVAL);

    if ((ret = av_image_check_size(width, height, 0, NULL)) < 0)

        return ret;

    if (desc->flags & AV_PIX_FMT_FLAG_PSEUDOPAL)

        // do not include palette for these pseudo-paletted formats

        return width * height;

    return avpicture_fill(&dummy_pict, NULL, pix_fmt, width, height);

}
