/* 
 * Benchmark Sample ID : devign_1735
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d3002b0463727bf8110833b9d1a6efaa28990c28
 */

void register_displaychangelistener(DisplayChangeListener *dcl)

{

    QemuConsole *con;



    trace_displaychangelistener_register(dcl, dcl->ops->dpy_name);

    dcl->ds = get_alloc_displaystate();

    QLIST_INSERT_HEAD(&dcl->ds->listeners, dcl, next);

    gui_setup_refresh(dcl->ds);

    if (dcl->con) {

        dcl->con->dcls++;

        con = dcl->con;

    } else {

        con = active_console;

    }

    if (dcl->ops->dpy_gfx_switch && con) {

        dcl->ops->dpy_gfx_switch(dcl, con->surface);

    }

}
