/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_1919
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=efec3dd631d94160288392721a5f9c39e50fb2bc
 */

static void ioapic_common_class_init(ObjectClass *klass, void *data)

{

    DeviceClass *dc = DEVICE_CLASS(klass);



    dc->realize = ioapic_common_realize;

    dc->vmsd = &vmstate_ioapic_common;

    dc->no_user = 1;

}
