/* 
 * Benchmark Sample ID : devign_638
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static struct omap_pwl_s *omap_pwl_init(MemoryRegion *system_memory,

                                        target_phys_addr_t base,

                                        omap_clk clk)

{

    struct omap_pwl_s *s = g_malloc0(sizeof(*s));



    omap_pwl_reset(s);



    memory_region_init_io(&s->iomem, &omap_pwl_ops, s,

                          "omap-pwl", 0x800);

    memory_region_add_subregion(system_memory, base, &s->iomem);



    omap_clk_adduser(clk, qemu_allocate_irqs(omap_pwl_clk_update, s, 1)[0]);

    return s;

}
