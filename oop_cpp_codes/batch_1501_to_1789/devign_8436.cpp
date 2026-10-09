/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_8436
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=efec3dd631d94160288392721a5f9c39e50fb2bc
 */

static void pci_grackle_class_init(ObjectClass *klass, void *data)

{

    SysBusDeviceClass *k = SYS_BUS_DEVICE_CLASS(klass);

    DeviceClass *dc = DEVICE_CLASS(klass);



    k->init = pci_grackle_init_device;

    dc->no_user = 1;

}
