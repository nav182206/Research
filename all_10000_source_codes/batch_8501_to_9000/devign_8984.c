/* 
 * Benchmark Sample ID : devign_8984
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=fbddfc727bde692f009a269e8e628d8c152b537b
 */

int qemu_pixman_get_type(int rshift, int gshift, int bshift)

{

    int type = PIXMAN_TYPE_OTHER;



    if (rshift > gshift && gshift > bshift) {

        if (bshift == 0) {

            type = PIXMAN_TYPE_ARGB;

        } else {

#if PIXMAN_VERSION >= PIXMAN_VERSION_ENCODE(0, 21, 8)

            type = PIXMAN_TYPE_RGBA;

#endif

        }

    } else if (rshift < gshift && gshift < bshift) {

        if (rshift == 0) {

            type = PIXMAN_TYPE_ABGR;

        } else {

#if PIXMAN_VERSION >= PIXMAN_VERSION_ENCODE(0, 21, 8)

            type = PIXMAN_TYPE_BGRA;

#endif

        }

    }

    return type;

}
