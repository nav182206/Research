/* 
 * Benchmark Sample ID : devign_5374
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=21ef45d71221b4577330fe3aacfb06afad91ad46
 */

static void vnc_dpy_setdata(DisplayChangeListener *dcl,

                            DisplayState *ds)

{

    VncDisplay *vd = ds->opaque;



    qemu_pixman_image_unref(vd->guest.fb);

    vd->guest.fb = pixman_image_ref(ds->surface->image);

    vd->guest.format = ds->surface->format;

    vnc_dpy_update(dcl, ds, 0, 0, ds_get_width(ds), ds_get_height(ds));

}
