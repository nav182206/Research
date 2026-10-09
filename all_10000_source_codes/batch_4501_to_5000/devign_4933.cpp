/* 
 * Benchmark Sample ID : devign_4933
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e4f4fb1eca795e36f363b4647724221e774523c1
 */

static void sysbus_ahci_class_init(ObjectClass *klass, void *data)

{

    DeviceClass *dc = DEVICE_CLASS(klass);



    dc->realize = sysbus_ahci_realize;

    dc->vmsd = &vmstate_sysbus_ahci;

    dc->props = sysbus_ahci_properties;

    dc->reset = sysbus_ahci_reset;

    set_bit(DEVICE_CATEGORY_STORAGE, dc->categories);






}
