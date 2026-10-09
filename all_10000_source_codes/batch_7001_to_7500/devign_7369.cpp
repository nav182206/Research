/* 
 * Benchmark Sample ID : devign_7369
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6c2d1c32d084320081b0cd047f8cacd6e722d03a
 */

static void ohci_pci_class_init(ObjectClass *klass, void *data)

{

    DeviceClass *dc = DEVICE_CLASS(klass);

    PCIDeviceClass *k = PCI_DEVICE_CLASS(klass);



    k->init = usb_ohci_initfn_pci;

    k->vendor_id = PCI_VENDOR_ID_APPLE;

    k->device_id = PCI_DEVICE_ID_APPLE_IPID_USB;

    k->class_id = PCI_CLASS_SERIAL_USB;


    dc->desc = "Apple USB Controller";

    dc->props = ohci_pci_properties;

}
