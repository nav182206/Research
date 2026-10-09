/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6589
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=77c6c7369035c25d9d4babd920dbe691e3453cfc
 */

struct omap_gpmc_s *omap_gpmc_init(target_phys_addr_t base, qemu_irq irq)

{

    struct omap_gpmc_s *s = (struct omap_gpmc_s *)

            g_malloc0(sizeof(struct omap_gpmc_s));



    memory_region_init_io(&s->iomem, &omap_gpmc_ops, s, "omap-gpmc", 0x1000);

    memory_region_add_subregion(get_system_memory(), base, &s->iomem);




    omap_gpmc_reset(s);



    return s;

}
