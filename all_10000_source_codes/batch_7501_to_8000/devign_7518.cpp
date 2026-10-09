/* 
 * Benchmark Sample ID : devign_7518
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=efec3dd631d94160288392721a5f9c39e50fb2bc
 */

static void pit_common_class_init(ObjectClass *klass, void *data)

{

    DeviceClass *dc = DEVICE_CLASS(klass);



    dc->realize = pit_common_realize;

    dc->vmsd = &vmstate_pit_common;

    dc->no_user = 1;

}
