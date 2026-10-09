/* 
 * Benchmark Sample ID : devign_2201
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1eda55510ae5d15ce3df9f496002508580899045
 */

static int decode_rle(AVCodecContext *avctx, AVFrame *p, GetByteContext *gbc,

                      int step)

{

    int i, j;

    int offset = avctx->width * step;

    uint8_t *outdata = p->data[0];



    for (i = 0; i < avctx->height; i++) {

        int size, left, code, pix;

        uint8_t *out = outdata;

        int pos = 0;



        /* size of packed line */

        size = left = bytestream2_get_be16(gbc);

        if (bytestream2_get_bytes_left(gbc) < size)




        /* decode line */

        while (left > 0) {

            code = bytestream2_get_byte(gbc);

            if (code & 0x80 ) { /* run */

                pix = bytestream2_get_byte(gbc);

                for (j = 0; j < 257 - code; j++) {

                    out[pos] = pix;

                    pos += step;

                    if (pos >= offset) {

                        pos -= offset;

                        pos++;

                    }



                }

                left  -= 2;

            } else { /* copy */

                for (j = 0; j < code + 1; j++) {

                    out[pos] = bytestream2_get_byte(gbc);

                    pos += step;

                    if (pos >= offset) {

                        pos -= offset;

                        pos++;

                    }



                }

                left  -= 2 + code;

            }

        }

        outdata += p->linesize[0];

    }

    return 0;

}
