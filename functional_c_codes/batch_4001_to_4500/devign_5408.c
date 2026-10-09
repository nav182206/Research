/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5408
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a553c6a347d3d28d7ee44c3df3d5c4ee780dba23
 */

static void release_unused_pictures(H264Context *h, int remove_current)

{

    int i;



    /* release non reference frames */

    for (i = 0; i < MAX_PICTURE_COUNT; i++) {

        if (h->DPB[i].f.data[0] && !h->DPB[i].reference &&

            (remove_current || &h->DPB[i] != h->cur_pic_ptr)) {

            unref_picture(h, &h->DPB[i]);

        }

    }

}
