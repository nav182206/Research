/* 
 * Benchmark Sample ID : devign_4370
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0c8f86ea98945678622c6e4b070c4218a53a0d19
 */

static void rocker_class_init(ObjectClass *klass, void *data)

{

    DeviceClass *dc = DEVICE_CLASS(klass);

    PCIDeviceClass *k = PCI_DEVICE_CLASS(klass);



    k->init = pci_rocker_init;

    k->exit = pci_rocker_uninit;

    k->vendor_id = PCI_VENDOR_ID_REDHAT;

    k->device_id = PCI_DEVICE_ID_REDHAT_ROCKER;

    k->revision = ROCKER_PCI_REVISION;

    k->class_id = PCI_CLASS_NETWORK_OTHER;

    set_bit(DEVICE_CATEGORY_NETWORK, dc->categories);

    dc->desc = "Rocker Switch";

    dc->reset = rocker_reset;

    dc->props = rocker_properties;

    dc->vmsd = &rocker_vmsd;

}
