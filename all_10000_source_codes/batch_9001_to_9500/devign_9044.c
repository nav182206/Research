/* 
 * Benchmark Sample ID : devign_9044
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b45c03f585ea9bb1af76c73e82195418c294919d
 */

struct omap_mcspi_s *omap_mcspi_init(struct omap_target_agent_s *ta, int chnum,

                qemu_irq irq, qemu_irq *drq, omap_clk fclk, omap_clk iclk)

{

    struct omap_mcspi_s *s = (struct omap_mcspi_s *)

            g_malloc0(sizeof(struct omap_mcspi_s));

    struct omap_mcspi_ch_s *ch = s->ch;



    s->irq = irq;

    s->chnum = chnum;

    while (chnum --) {

        ch->txdrq = *drq ++;

        ch->rxdrq = *drq ++;

        ch ++;

    }

    omap_mcspi_reset(s);



    memory_region_init_io(&s->iomem, NULL, &omap_mcspi_ops, s, "omap.mcspi",

                          omap_l4_region_size(ta, 0));

    omap_l4_attach(ta, 0, &s->iomem);



    return s;

}
