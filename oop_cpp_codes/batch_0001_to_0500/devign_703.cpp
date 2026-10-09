/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_703
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5a3d7b23ba41b4884b43b6bc936ea18f999d5c6b
 */

static void xics_class_init(ObjectClass *oc, void *data)

{

    DeviceClass *dc = DEVICE_CLASS(oc);



    dc->realize = xics_realize;

    dc->props = xics_properties;

    dc->reset = xics_reset;

}
