/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4101
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c11d3634b07b4aa71f75478aa1bcb63b0c22e030
 */

static void srt_to_ass(AVCodecContext *avctx, AVBPrint *dst,

                       const char *in, int x1, int y1, int x2, int y2)

{

    if (x1 >= 0 && y1 >= 0) {

        /* XXX: here we rescale coordinate assuming they are in DVD resolution

         * (720x480) since we don't have anything better */



        if (x2 >= 0 && y2 >= 0 && (x2 != x1 || y2 != y1) && x2 >= x1 && y2 >= y1) {

            /* text rectangle defined, write the text at the center of the rectangle */

            const int cx = x1 + (x2 - x1)/2;

            const int cy = y1 + (y2 - y1)/2;

            const int scaled_x = cx * ASS_DEFAULT_PLAYRESX / 720;

            const int scaled_y = cy * ASS_DEFAULT_PLAYRESY / 480;

            av_bprintf(dst, "{\\an5}{\\pos(%d,%d)}", scaled_x, scaled_y);

        } else {

            /* only the top left corner, assume the text starts in that corner */

            const int scaled_x = x1 * ASS_DEFAULT_PLAYRESX / 720;

            const int scaled_y = y1 * ASS_DEFAULT_PLAYRESY / 480;

            av_bprintf(dst, "{\\an1}{\\pos(%d,%d)}", scaled_x, scaled_y);

        }

    }



    ff_htmlmarkup_to_ass(avctx, dst, in);

}
