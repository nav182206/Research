/* 
 * Benchmark Sample ID : devign_8775
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=13f1c773640171efa8175b1ba6dcd624c1ad68c1
 */

static void openrisc_sim_net_init(MemoryRegion *address_space,

                                  hwaddr base,

                                  hwaddr descriptors,

                                  qemu_irq irq, NICInfo *nd)

{

    DeviceState *dev;

    SysBusDevice *s;



    dev = qdev_create(NULL, "open_eth");

    qdev_set_nic_properties(dev, nd);

    qdev_init_nofail(dev);



    s = SYS_BUS_DEVICE(dev);

    sysbus_connect_irq(s, 0, irq);

    memory_region_add_subregion(address_space, base,

                                sysbus_mmio_get_region(s, 0));

    memory_region_add_subregion(address_space, descriptors,

                                sysbus_mmio_get_region(s, 1));

}
