/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_7534
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=efec3dd631d94160288392721a5f9c39e50fb2bc
 */

static void s390_ipl_class_init(ObjectClass *klass, void *data)

{

    DeviceClass *dc = DEVICE_CLASS(klass);

    SysBusDeviceClass *k = SYS_BUS_DEVICE_CLASS(klass);



    k->init = s390_ipl_init;

    dc->props = s390_ipl_properties;

    dc->reset = s390_ipl_reset;

    dc->no_user = 1;

}
