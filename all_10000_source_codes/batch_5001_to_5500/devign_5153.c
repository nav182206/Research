/* 
 * Benchmark Sample ID : devign_5153
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static struct omap_mpuio_s *omap_mpuio_init(MemoryRegion *memory,

                target_phys_addr_t base,

                qemu_irq kbd_int, qemu_irq gpio_int, qemu_irq wakeup,

                omap_clk clk)

{

    struct omap_mpuio_s *s = (struct omap_mpuio_s *)

            g_malloc0(sizeof(struct omap_mpuio_s));



    s->irq = gpio_int;

    s->kbd_irq = kbd_int;

    s->wakeup = wakeup;

    s->in = qemu_allocate_irqs(omap_mpuio_set, s, 16);

    omap_mpuio_reset(s);



    memory_region_init_io(&s->iomem, &omap_mpuio_ops, s,

                          "omap-mpuio", 0x800);

    memory_region_add_subregion(memory, base, &s->iomem);



    omap_clk_adduser(clk, qemu_allocate_irqs(omap_mpuio_onoff, s, 1)[0]);



    return s;

}
