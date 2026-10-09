/* 
 * Benchmark Sample ID : devign_3150
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=220b24c7c97dc033ceab1510549f66d0e7b52ef1
 */

static enum AVPixelFormat get_chroma_format(SchroChromaFormat schro_pix_fmt)

{

    int num_formats = sizeof(schro_pixel_format_map) /

                      sizeof(schro_pixel_format_map[0]);

    int idx;



    for (idx = 0; idx < num_formats; ++idx)

        if (schro_pixel_format_map[idx].schro_pix_fmt == schro_pix_fmt)

            return schro_pixel_format_map[idx].ff_pix_fmt;

    return AV_PIX_FMT_NONE;

}
