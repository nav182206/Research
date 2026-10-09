/* 
 * Benchmark Sample ID : devign_1571
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7ebaf7955603cc50988e0eafd5e6074320fefc70
 */

static void spapr_cpu_core_class_init(ObjectClass *oc, void *data)

{

    DeviceClass *dc = DEVICE_CLASS(oc);

    dc->realize = spapr_cpu_core_realize;

}
