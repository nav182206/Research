/* 
 * Benchmark Sample ID : devign_7773
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2c62f08ddbf3fa80dc7202eb9a2ea60ae44e2cc5
 */

static void qxl_hw_screen_dump(void *opaque, const char *filename, bool cswitch,

                               Error **errp)

{

    PCIQXLDevice *qxl = opaque;

    VGACommonState *vga = &qxl->vga;



    switch (qxl->mode) {

    case QXL_MODE_COMPAT:

    case QXL_MODE_NATIVE:

        qxl_render_update(qxl);

        ppm_save(filename, qxl->ssd.ds, errp);

        break;

    case QXL_MODE_VGA:

        vga->screen_dump(vga, filename, cswitch, errp);

        break;

    default:

        break;

    }

}
