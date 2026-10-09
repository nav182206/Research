/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4932
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8bb93c6f99a42c2e0943bc904b283cd622d302c5
 */

static void dpy_refresh(DisplayState *s)

{

    DisplayChangeListener *dcl;



    QLIST_FOREACH(dcl, &s->listeners, next) {

        if (dcl->ops->dpy_refresh) {

            dcl->ops->dpy_refresh(dcl);

        }

    }

}
