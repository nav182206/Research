/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_4176
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e0dadc1e9ef1f35208e5d2af9c7740c18a0b769f
 */

static void aux_slave_class_init(ObjectClass *klass, void *data)

{

    DeviceClass *k = DEVICE_CLASS(klass);



    set_bit(DEVICE_CATEGORY_MISC, k->categories);

    k->bus_type = TYPE_AUX_BUS;

}
