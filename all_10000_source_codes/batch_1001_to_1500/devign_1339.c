/* 
 * Benchmark Sample ID : devign_1339
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=84a3a53cf61ef691478bd91afa455c801696053c
 */

static int omap_intc_init(SysBusDevice *sbd)

{

    DeviceState *dev = DEVICE(sbd);

    struct omap_intr_handler_s *s = OMAP_INTC(dev);



    if (!s->iclk) {

        hw_error("omap-intc: clk not connected\n");

    }

    s->nbanks = 1;

    sysbus_init_irq(sbd, &s->parent_intr[0]);

    sysbus_init_irq(sbd, &s->parent_intr[1]);

    qdev_init_gpio_in(dev, omap_set_intr, s->nbanks * 32);

    memory_region_init_io(&s->mmio, OBJECT(s), &omap_inth_mem_ops, s,

                          "omap-intc", s->size);

    sysbus_init_mmio(sbd, &s->mmio);

    return 0;

}
