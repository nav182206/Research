/* 
 * Benchmark Sample ID : devign_9232
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=efec3dd631d94160288392721a5f9c39e50fb2bc
 */

static void port92_class_initfn(ObjectClass *klass, void *data)

{

    DeviceClass *dc = DEVICE_CLASS(klass);



    dc->no_user = 1;

    dc->realize = port92_realizefn;

    dc->reset = port92_reset;

    dc->vmsd = &vmstate_port92_isa;

}
