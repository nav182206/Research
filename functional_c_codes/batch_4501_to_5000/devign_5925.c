/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5925
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ec0e68ef1da316b3ead1943d8f607cc68b13e0d1
 */

static void gem_init(NICInfo *nd, uint32_t base, qemu_irq irq)

{

    DeviceState *dev;

    SysBusDevice *s;



    qemu_check_nic_model(nd, "cadence_gem");

    dev = qdev_create(NULL, "cadence_gem");

    qdev_set_nic_properties(dev, nd);

    qdev_init_nofail(dev);

    s = SYS_BUS_DEVICE(dev);

    sysbus_mmio_map(s, 0, base);

    sysbus_connect_irq(s, 0, irq);

}
