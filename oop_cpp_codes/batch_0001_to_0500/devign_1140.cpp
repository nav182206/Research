/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_1140
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=efec3dd631d94160288392721a5f9c39e50fb2bc
 */

static void apic_common_class_init(ObjectClass *klass, void *data)

{

    ICCDeviceClass *idc = ICC_DEVICE_CLASS(klass);

    DeviceClass *dc = DEVICE_CLASS(klass);



    dc->vmsd = &vmstate_apic_common;

    dc->reset = apic_reset_common;

    dc->no_user = 1;

    dc->props = apic_properties_common;

    idc->init = apic_init_common;

}
