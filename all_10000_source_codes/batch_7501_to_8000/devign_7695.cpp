/* 
 * Benchmark Sample ID : devign_7695
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a369da5f31ddbdeb32a7f76622e480d3995fbb00
 */

PCIDevice *pci_try_create_multifunction(PCIBus *bus, int devfn,

                                        bool multifunction,

                                        const char *name)

{

    DeviceState *dev;



    dev = qdev_try_create(&bus->qbus, name);

    if (!dev) {

        return NULL;

    }

    qdev_prop_set_uint32(dev, "addr", devfn);

    qdev_prop_set_bit(dev, "multifunction", multifunction);

    return DO_UPCAST(PCIDevice, qdev, dev);

}
