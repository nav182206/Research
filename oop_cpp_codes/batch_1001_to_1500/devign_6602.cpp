/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_6602
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e4f4fb1eca795e36f363b4647724221e774523c1
 */

static void sun4m_fdc_class_init(ObjectClass *klass, void *data)

{

    DeviceClass *dc = DEVICE_CLASS(klass);



    dc->props = sun4m_fdc_properties;

    set_bit(DEVICE_CATEGORY_STORAGE, dc->categories);






}
