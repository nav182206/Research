/* 
 * Benchmark Sample ID : devign_548
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b45c03f585ea9bb1af76c73e82195418c294919d
 */

static struct omap_tipb_bridge_s *omap_tipb_bridge_init(

    MemoryRegion *memory, hwaddr base,

    qemu_irq abort_irq, omap_clk clk)

{

    struct omap_tipb_bridge_s *s = (struct omap_tipb_bridge_s *)

            g_malloc0(sizeof(struct omap_tipb_bridge_s));



    s->abort = abort_irq;

    omap_tipb_bridge_reset(s);



    memory_region_init_io(&s->iomem, NULL, &omap_tipb_bridge_ops, s,

                          "omap-tipb-bridge", 0x100);

    memory_region_add_subregion(memory, base, &s->iomem);



    return s;

}
