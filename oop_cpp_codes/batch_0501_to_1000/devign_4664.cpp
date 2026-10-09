/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_4664
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=133e9b228df16d11de01529c217417e78d1d9370
 */

static void pci_device_class_init(ObjectClass *klass, void *data)

{

    DeviceClass *k = DEVICE_CLASS(klass);

    k->init = pci_qdev_init;

    k->exit = pci_unregister_device;

    k->bus_type = TYPE_PCI_BUS;

    k->props = pci_props;

}
