/* 
 * Benchmark Sample ID : devign_3238
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=efec3dd631d94160288392721a5f9c39e50fb2bc
 */

static void piix4_class_init(ObjectClass *klass, void *data)

{

    DeviceClass *dc = DEVICE_CLASS(klass);

    PCIDeviceClass *k = PCI_DEVICE_CLASS(klass);



    k->no_hotplug = 1;

    k->init = piix4_initfn;

    k->vendor_id = PCI_VENDOR_ID_INTEL;

    k->device_id = PCI_DEVICE_ID_INTEL_82371AB_0;

    k->class_id = PCI_CLASS_BRIDGE_ISA;

    dc->desc = "ISA bridge";

    dc->no_user = 1;

    dc->vmsd = &vmstate_piix4;

}
