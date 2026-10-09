/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5178
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=38d553322891c8e47182f05199d19888422167dc
 */

int avpicture_get_size(enum PixelFormat pix_fmt, int width, int height)

{

    AVPicture dummy_pict;

    if(av_image_check_size(width, height, 0, NULL))

        return -1;

    switch (pix_fmt) {

    case PIX_FMT_RGB8:

    case PIX_FMT_BGR8:

    case PIX_FMT_RGB4_BYTE:

    case PIX_FMT_BGR4_BYTE:

    case PIX_FMT_GRAY8:

        // do not include palette for these pseudo-paletted formats

        return width * height;

    }

    return avpicture_fill(&dummy_pict, NULL, pix_fmt, width, height);

}
