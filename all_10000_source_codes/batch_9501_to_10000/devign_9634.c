/* 
 * Benchmark Sample ID : devign_9634
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6cec5487990bf3f1f22b3fcb871978255e92ae0d
 */

static void vnc_dpy_resize(DisplayState *ds)

{

    int size_changed;

    VncState *vs = ds->opaque;



    vs->old_data = qemu_realloc(vs->old_data, ds_get_linesize(ds) * ds_get_height(ds));



    if (vs->old_data == NULL) {

	fprintf(stderr, "vnc: memory allocation failed\n");

	exit(1);

    }



    if (ds_get_bytes_per_pixel(ds) != vs->depth)

        console_color_init(ds);

    vnc_colordepth(ds);

    size_changed = ds_get_width(ds) != vs->width || ds_get_height(ds) != vs->height;

    if (size_changed) {

        vs->width = ds_get_width(ds);

        vs->height = ds_get_height(ds);

        if (vs->csock != -1 && vs->has_resize) {

            vnc_write_u8(vs, 0);  /* msg id */

            vnc_write_u8(vs, 0);

            vnc_write_u16(vs, 1); /* number of rects */

            vnc_framebuffer_update(vs, 0, 0, ds_get_width(ds), ds_get_height(ds), -223);

            vnc_flush(vs);

        }

    }



    memset(vs->dirty_row, 0xFF, sizeof(vs->dirty_row));

    memset(vs->old_data, 42, ds_get_linesize(vs->ds) * ds_get_height(vs->ds));

}
