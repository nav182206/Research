/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3798
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=777c5f1e436d334a57b650b6951c13d8d2799df0
 */

void unregister_displaychangelistener(DisplayChangeListener *dcl)

{

    DisplayState *ds = dcl->ds;

    trace_displaychangelistener_unregister(dcl, dcl->ops->dpy_name);

    if (dcl->con) {

        dcl->con->dcls--;

    }

    QLIST_REMOVE(dcl, next);


    gui_setup_refresh(ds);

}
