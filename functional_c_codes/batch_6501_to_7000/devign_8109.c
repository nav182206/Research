/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8109
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=245f7b51c0ea04fb2224b1127430a096c91aee70
 */

void vnc_hextile_set_pixel_conversion(VncState *vs, int generic)

{

    if (!generic) {

        switch (vs->ds->surface->pf.bits_per_pixel) {

            case 8:

                vs->send_hextile_tile = send_hextile_tile_8;

                break;

            case 16:

                vs->send_hextile_tile = send_hextile_tile_16;

                break;

            case 32:

                vs->send_hextile_tile = send_hextile_tile_32;

                break;

        }

    } else {

        switch (vs->ds->surface->pf.bits_per_pixel) {

            case 8:

                vs->send_hextile_tile = send_hextile_tile_generic_8;

                break;

            case 16:

                vs->send_hextile_tile = send_hextile_tile_generic_16;

                break;

            case 32:

                vs->send_hextile_tile = send_hextile_tile_generic_32;

                break;

        }

    }

}
