/* 
 * Benchmark Sample ID : devign_4149
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=12351a91da97b414eec8cdb09f1d9f41e535a401
 */

static void ac97_class_init (ObjectClass *klass, void *data)

{

    DeviceClass *dc = DEVICE_CLASS (klass);

    PCIDeviceClass *k = PCI_DEVICE_CLASS (klass);



    k->realize = ac97_realize;


    k->vendor_id = PCI_VENDOR_ID_INTEL;

    k->device_id = PCI_DEVICE_ID_INTEL_82801AA_5;

    k->revision = 0x01;

    k->class_id = PCI_CLASS_MULTIMEDIA_AUDIO;

    set_bit(DEVICE_CATEGORY_SOUND, dc->categories);

    dc->desc = "Intel 82801AA AC97 Audio";

    dc->vmsd = &vmstate_ac97;

    dc->props = ac97_properties;

    dc->reset = ac97_on_reset;

}
