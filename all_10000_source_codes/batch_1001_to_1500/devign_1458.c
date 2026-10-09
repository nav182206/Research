/* 
 * Benchmark Sample ID : devign_1458
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=187337f8b0ec0813dd3876d1efe37d415fb81c2e
 */

void *pl110_init(DisplayState *ds, uint32_t base, qemu_irq irq,

                 int versatile)

{

    pl110_state *s;

    int iomemtype;



    s = (pl110_state *)qemu_mallocz(sizeof(pl110_state));

    iomemtype = cpu_register_io_memory(0, pl110_readfn,

                                       pl110_writefn, s);

    cpu_register_physical_memory(base, 0x00000fff, iomemtype);

    s->base = base;

    s->ds = ds;

    s->versatile = versatile;

    s->irq = irq;

    graphic_console_init(ds, pl110_update_display, pl110_invalidate_display,

                         NULL, s);

    /* ??? Save/restore.  */

    return s;

}
