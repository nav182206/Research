/* 
 * Benchmark Sample ID : devign_8221
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=207f328afc2137d422f59293ba37b8be5d3e1617
 */

static int vnc_refresh_lossy_rect(VncDisplay *vd, int x, int y)

{

    VncState *vs;

    int sty = y / VNC_STAT_RECT;

    int stx = x / VNC_STAT_RECT;

    int has_dirty = 0;



    y = y / VNC_STAT_RECT * VNC_STAT_RECT;

    x = x / VNC_STAT_RECT * VNC_STAT_RECT;



    QTAILQ_FOREACH(vs, &vd->clients, next) {

        int j;



        /* kernel send buffers are full -> refresh later */

        if (vs->output.offset) {

            continue;

        }



        if (!vs->lossy_rect[sty][stx]) {

            continue;

        }

        vs->lossy_rect[sty][stx] = 0;

        for (j = 0; j < VNC_STAT_RECT; ++j) {

            vnc_set_bits(vs->dirty[y + j], x / 16, VNC_STAT_RECT / 16);

        }

        has_dirty++;

    }

    return has_dirty;

}
