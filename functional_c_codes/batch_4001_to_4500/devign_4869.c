/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4869
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=167bc3d2fa100590b5a9d8fd9f19ae0207197447
 */

static void musicpal_lcd_init(DisplayState *ds, uint32_t base)

{

    musicpal_lcd_state *s;

    int iomemtype;



    s = qemu_mallocz(sizeof(musicpal_lcd_state));

    if (!s)

        return;

    s->base = base;

    s->ds = ds;

    iomemtype = cpu_register_io_memory(0, musicpal_lcd_readfn,

                                       musicpal_lcd_writefn, s);

    cpu_register_physical_memory(base, MP_LCD_SIZE, iomemtype);



    graphic_console_init(ds, lcd_refresh, NULL, NULL, NULL, s);

    dpy_resize(ds, 128*3, 64*3);

}
