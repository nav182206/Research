/* 
 * Benchmark Sample ID : devign_298
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=efec3dd631d94160288392721a5f9c39e50fb2bc
 */

static void arm_gic_common_class_init(ObjectClass *klass, void *data)

{

    DeviceClass *dc = DEVICE_CLASS(klass);



    dc->reset = arm_gic_common_reset;

    dc->realize = arm_gic_common_realize;

    dc->props = arm_gic_common_properties;

    dc->vmsd = &vmstate_gic;

    dc->no_user = 1;

}
