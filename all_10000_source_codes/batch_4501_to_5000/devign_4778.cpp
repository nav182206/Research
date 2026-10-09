/* 
 * Benchmark Sample ID : devign_4778
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b1fc72f0fb0aeae4194ff89c454aabe019983d0d
 */

static void xics_common_class_init(ObjectClass *oc, void *data)

{

    DeviceClass *dc = DEVICE_CLASS(oc);




    dc->reset = xics_common_reset;


}
