/* 
 * Benchmark Sample ID : devign_9541
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=32baeafeee4f8446c2c3720b9223ad2166ca9d30
 */

static void put_pixels_clamped_c(const int16_t *block, uint8_t *av_restrict pixels,

                                 ptrdiff_t line_size)

{

    int i;



    /* read the pixels */

    for (i = 0; i < 8; i++) {

        pixels[0] = av_clip_uint8(block[0]);

        pixels[1] = av_clip_uint8(block[1]);

        pixels[2] = av_clip_uint8(block[2]);

        pixels[3] = av_clip_uint8(block[3]);

        pixels[4] = av_clip_uint8(block[4]);

        pixels[5] = av_clip_uint8(block[5]);

        pixels[6] = av_clip_uint8(block[6]);

        pixels[7] = av_clip_uint8(block[7]);



        pixels += line_size;

        block  += 8;

    }

}
