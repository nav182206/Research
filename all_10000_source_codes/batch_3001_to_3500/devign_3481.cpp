/* 
 * Benchmark Sample ID : devign_3481
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d28fca153bb27ff965b9eb26d73327fa4d2402c8
 */

static void pci_vpb_class_init(ObjectClass *klass, void *data)

{

    DeviceClass *dc = DEVICE_CLASS(klass);



    dc->realize = pci_vpb_realize;

    dc->reset = pci_vpb_reset;

    dc->vmsd = &pci_vpb_vmstate;

    dc->props = pci_vpb_properties;

    /* Reason: object_unref() hangs */

    dc->cannot_destroy_with_object_finalize_yet = true;

}
