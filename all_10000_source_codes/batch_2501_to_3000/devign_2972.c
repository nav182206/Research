/* 
 * Benchmark Sample ID : devign_2972
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ef1e1e0782e99c9dcf2b35e5310cdd8ca9211374
 */

static void display_mouse_set(DisplayChangeListener *dcl,

                              int x, int y, int on)

{

    SimpleSpiceDisplay *ssd = container_of(dcl, SimpleSpiceDisplay, dcl);



    qemu_mutex_lock(&ssd->lock);

    ssd->ptr_x = x;

    ssd->ptr_y = y;

    if (ssd->ptr_move) {

        g_free(ssd->ptr_move);

    }

    ssd->ptr_move = qemu_spice_create_cursor_update(ssd, NULL, on);

    qemu_mutex_unlock(&ssd->lock);

}
