/* 
 * Benchmark Sample ID : devign_936
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a553c6a347d3d28d7ee44c3df3d5c4ee780dba23
 */

static int find_unused_picture(MpegEncContext *s, int shared)

{

    int i;



    if (shared) {

        for (i = 0; i < MAX_PICTURE_COUNT; i++) {

            if (s->picture[i].f.data[0] == NULL)

                return i;

        }

    } else {

        for (i = 0; i < MAX_PICTURE_COUNT; i++) {

            if (pic_is_unused(s, &s->picture[i]))

                return i;

        }

    }



    return AVERROR_INVALIDDATA;

}
