/* 
 * Benchmark Sample ID : devign_6594
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7bc155163ec08a0302526d7e19d08c8053f932f0
 */

static int expand_rle_row(SgiState *s, uint8_t *out_buf,

                          uint8_t *out_end, int pixelstride)

{

    unsigned char pixel, count;

    unsigned char *orig = out_buf;



    while (1) {

        if (bytestream2_get_bytes_left(&s->g) < 1)

            return AVERROR_INVALIDDATA;

        pixel = bytestream2_get_byteu(&s->g);

        if (!(count = (pixel & 0x7f))) {

            return (out_buf - orig) / pixelstride;

        }



        /* Check for buffer overflow. */

        if(out_buf + pixelstride * count >= out_end) return -1;



        if (pixel & 0x80) {

            while (count--) {

                *out_buf = bytestream2_get_byte(&s->g);

                out_buf += pixelstride;

            }

        } else {

            pixel = bytestream2_get_byte(&s->g);



            while (count--) {

                *out_buf = pixel;

                out_buf += pixelstride;

            }

        }

    }

}
