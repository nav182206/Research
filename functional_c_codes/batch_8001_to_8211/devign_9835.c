/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9835
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6cec5487990bf3f1f22b3fcb871978255e92ae0d
 */

static void vnc_dpy_update(DisplayState *ds, int x, int y, int w, int h)

{

    VncState *vs = ds->opaque;

    int i;



    h += y;



    /* round x down to ensure the loop only spans one 16-pixel block per,

       iteration.  otherwise, if (x % 16) != 0, the last iteration may span

       two 16-pixel blocks but we only mark the first as dirty

    */

    w += (x % 16);

    x -= (x % 16);



    x = MIN(x, vs->width);

    y = MIN(y, vs->height);

    w = MIN(x + w, vs->width) - x;

    h = MIN(h, vs->height);



    for (; y < h; y++)

	for (i = 0; i < w; i += 16)

	    vnc_set_bit(vs->dirty_row[y], (x + i) / 16);

}
