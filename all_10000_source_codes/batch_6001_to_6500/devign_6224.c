/* 
 * Benchmark Sample ID : devign_6224
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=bea60dd7679364493a0d7f5b54316c767cf894ef
 */

static void vnc_dpy_switch(DisplayChangeListener *dcl,

                           DisplaySurface *surface)

{

    VncDisplay *vd = container_of(dcl, VncDisplay, dcl);

    VncState *vs;



    vnc_abort_display_jobs(vd);



    /* server surface */

    qemu_pixman_image_unref(vd->server);

    vd->ds = surface;

    vd->server = pixman_image_create_bits(VNC_SERVER_FB_FORMAT,

                                          surface_width(vd->ds),

                                          surface_height(vd->ds),

                                          NULL, 0);



    /* guest surface */

#if 0 /* FIXME */

    if (ds_get_bytes_per_pixel(ds) != vd->guest.ds->pf.bytes_per_pixel)

        console_color_init(ds);

#endif

    qemu_pixman_image_unref(vd->guest.fb);

    vd->guest.fb = pixman_image_ref(surface->image);

    vd->guest.format = surface->format;

    VNC_SET_VISIBLE_PIXELS_DIRTY(vd->guest.dirty,

                                 surface_width(vd->ds),

                                 surface_height(vd->ds));



    QTAILQ_FOREACH(vs, &vd->clients, next) {

        vnc_colordepth(vs);

        vnc_desktop_resize(vs);

        if (vs->vd->cursor) {

            vnc_cursor_define(vs);

        }

        VNC_SET_VISIBLE_PIXELS_DIRTY(vs->dirty,

                                     surface_width(vd->ds),

                                     surface_height(vd->ds));

    }

}
