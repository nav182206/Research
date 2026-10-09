/* 
 * Benchmark Sample ID : devign_7895
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b45c03f585ea9bb1af76c73e82195418c294919d
 */

struct omap_mmc_s *omap2_mmc_init(struct omap_target_agent_s *ta,

                BlockBackend *blk, qemu_irq irq, qemu_irq dma[],

                omap_clk fclk, omap_clk iclk)

{

    struct omap_mmc_s *s = (struct omap_mmc_s *)

            g_malloc0(sizeof(struct omap_mmc_s));



    s->irq = irq;

    s->dma = dma;

    s->clk = fclk;

    s->lines = 4;

    s->rev = 2;



    omap_mmc_reset(s);



    memory_region_init_io(&s->iomem, NULL, &omap_mmc_ops, s, "omap.mmc",

                          omap_l4_region_size(ta, 0));

    omap_l4_attach(ta, 0, &s->iomem);



    /* Instantiate the storage */

    s->card = sd_init(blk, false);

    if (s->card == NULL) {

        exit(1);

    }



    s->cdet = qemu_allocate_irq(omap_mmc_cover_cb, s, 0);

    sd_set_cb(s->card, NULL, s->cdet);



    return s;

}
