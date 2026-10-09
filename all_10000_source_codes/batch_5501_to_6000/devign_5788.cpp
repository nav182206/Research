/* 
 * Benchmark Sample ID : devign_5788
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ca44141d5fb801dd5903102acefd0f2d8e8bb6a1
 */

static void ide_device_class_init(ObjectClass *klass, void *data)

{

    DeviceClass *k = DEVICE_CLASS(klass);

    k->init = ide_qdev_init;

    set_bit(DEVICE_CATEGORY_STORAGE, k->categories);

    k->bus_type = TYPE_IDE_BUS;


    k->props = ide_props;

}
