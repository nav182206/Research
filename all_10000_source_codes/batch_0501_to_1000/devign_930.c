/* 
 * Benchmark Sample ID : devign_930
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b45c03f585ea9bb1af76c73e82195418c294919d
 */

static PXA2xxI2SState *pxa2xx_i2s_init(MemoryRegion *sysmem,

                hwaddr base,

                qemu_irq irq, qemu_irq rx_dma, qemu_irq tx_dma)

{

    PXA2xxI2SState *s = (PXA2xxI2SState *)

            g_malloc0(sizeof(PXA2xxI2SState));



    s->irq = irq;

    s->rx_dma = rx_dma;

    s->tx_dma = tx_dma;

    s->data_req = pxa2xx_i2s_data_req;



    pxa2xx_i2s_reset(s);



    memory_region_init_io(&s->iomem, NULL, &pxa2xx_i2s_ops, s,

                          "pxa2xx-i2s", 0x100000);

    memory_region_add_subregion(sysmem, base, &s->iomem);



    vmstate_register(NULL, base, &vmstate_pxa2xx_i2s, s);



    return s;

}
