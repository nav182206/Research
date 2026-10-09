/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8450
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=38f3adc34de83bf75d2023831dc520d32568a2d9
 */

FWCfgState *fw_cfg_init_io_dma(uint32_t iobase, uint32_t dma_iobase,

                                AddressSpace *dma_as)

{

    DeviceState *dev;

    SysBusDevice *sbd;

    FWCfgIoState *ios;

    FWCfgState *s;

    bool dma_requested = dma_iobase && dma_as;



    dev = qdev_create(NULL, TYPE_FW_CFG_IO);

    if (!dma_requested) {

        qdev_prop_set_bit(dev, "dma_enabled", false);

    }



    fw_cfg_init1(dev);



    sbd = SYS_BUS_DEVICE(dev);

    ios = FW_CFG_IO(dev);

    sysbus_add_io(sbd, iobase, &ios->comb_iomem);



    s = FW_CFG(dev);



    if (s->dma_enabled) {

        /* 64 bits for the address field */

        s->dma_as = dma_as;

        s->dma_addr = 0;

        sysbus_add_io(sbd, dma_iobase, &s->dma_iomem);

    }



    return s;

}
