/* 
 * Benchmark Sample ID : devign_7787
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8ac55351459055f2faee585d9ba2f84707741815
 */

static void hda_codec_device_class_init(ObjectClass *klass, void *data)

{

    DeviceClass *k = DEVICE_CLASS(klass);

    k->realize = hda_codec_dev_realize;

    k->exit = hda_codec_dev_exit;

    set_bit(DEVICE_CATEGORY_SOUND, k->categories);

    k->bus_type = TYPE_HDA_BUS;

    k->props = hda_props;

}
