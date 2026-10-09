/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5300
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7a28b7714e4503149f773782a19708c773f3d62d
 */

static int gif_parse_next_image(GifState *s)

{

    for (;;) {

        int code = bytestream_get_byte(&s->bytestream);

#ifdef DEBUG

        dprintf(s->avctx, "gif: code=%02x '%c'\n", code, code);

#endif

        switch (code) {

        case ',':

            if (gif_read_image(s) < 0)

                return -1;

            return 0;

        case ';':

            /* end of image */

            return -1;

        case '!':

            if (gif_read_extension(s) < 0)

                return -1;

            break;

        default:

            /* error or errneous EOF */

            return -1;

        }

    }

}
