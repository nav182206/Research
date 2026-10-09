/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9579
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=738012bec4c67e697e766edadab3f522c552a04d
 */

struct omap_eac_s *omap_eac_init(struct omap_target_agent_s *ta,

                qemu_irq irq, qemu_irq *drq, omap_clk fclk, omap_clk iclk)

{

    int iomemtype;

    struct omap_eac_s *s = (struct omap_eac_s *)

            qemu_mallocz(sizeof(struct omap_eac_s));



    s->irq = irq;

    s->codec.rxdrq = *drq ++;

    s->codec.txdrq = *drq;

    omap_eac_reset(s);



#ifdef HAS_AUDIO

    AUD_register_card("OMAP EAC", &s->codec.card);



    iomemtype = cpu_register_io_memory(omap_eac_readfn,

                    omap_eac_writefn, s);

    omap_l4_attach(ta, 0, iomemtype);

#endif



    return s;

}
