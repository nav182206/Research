/* 
 * Benchmark Sample ID : devign_5592
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9561fda8d90e176bef598ba87c42a1bd6ad03ef7
 */

static void xilinx_axidma_init(Object *obj)

{

    XilinxAXIDMA *s = XILINX_AXI_DMA(obj);

    SysBusDevice *sbd = SYS_BUS_DEVICE(obj);



    object_property_add_link(obj, "axistream-connected", TYPE_STREAM_SLAVE,

                             (Object **)&s->tx_data_dev, &error_abort);

    object_property_add_link(obj, "axistream-control-connected",

                             TYPE_STREAM_SLAVE,

                             (Object **)&s->tx_control_dev, &error_abort);



    object_initialize(&s->rx_data_dev, sizeof(s->rx_data_dev),

                      TYPE_XILINX_AXI_DMA_DATA_STREAM);

    object_initialize(&s->rx_control_dev, sizeof(s->rx_control_dev),

                      TYPE_XILINX_AXI_DMA_CONTROL_STREAM);

    object_property_add_child(OBJECT(s), "axistream-connected-target",

                              (Object *)&s->rx_data_dev, &error_abort);

    object_property_add_child(OBJECT(s), "axistream-control-connected-target",

                              (Object *)&s->rx_control_dev, &error_abort);



    sysbus_init_irq(sbd, &s->streams[0].irq);

    sysbus_init_irq(sbd, &s->streams[1].irq);



    memory_region_init_io(&s->iomem, obj, &axidma_ops, s,

                          "xlnx.axi-dma", R_MAX * 4 * 2);

    sysbus_init_mmio(sbd, &s->iomem);

}
