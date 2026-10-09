/* 
 * Benchmark Sample ID : devign_3721
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2c62f08ddbf3fa80dc7202eb9a2ea60ae44e2cc5
 */

static void omap_screen_dump(void *opaque, const char *filename, bool cswitch,

                             Error **errp)

{

    struct omap_lcd_panel_s *omap_lcd = opaque;

    DisplaySurface *surface = qemu_console_surface(omap_lcd->con);



    omap_update_display(opaque);

    if (omap_lcd && surface_data(surface))

        omap_ppm_save(filename, surface_data(surface),

                    omap_lcd->width, omap_lcd->height,

                    surface_stride(surface), errp);

}
