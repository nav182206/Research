/* 
 * Benchmark Sample ID : devign_5619
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=187337f8b0ec0813dd3876d1efe37d415fb81c2e
 */

struct pxa2xx_mmci_s *pxa2xx_mmci_init(target_phys_addr_t base,

                qemu_irq irq, void *dma)

{

    int iomemtype;

    struct pxa2xx_mmci_s *s;



    s = (struct pxa2xx_mmci_s *) qemu_mallocz(sizeof(struct pxa2xx_mmci_s));

    s->base = base;

    s->irq = irq;

    s->dma = dma;



    iomemtype = cpu_register_io_memory(0, pxa2xx_mmci_readfn,

                    pxa2xx_mmci_writefn, s);

    cpu_register_physical_memory(base, 0x000fffff, iomemtype);



    /* Instantiate the actual storage */

    s->card = sd_init(sd_bdrv);



    register_savevm("pxa2xx_mmci", 0, 0,

                    pxa2xx_mmci_save, pxa2xx_mmci_load, s);



    return s;

}
