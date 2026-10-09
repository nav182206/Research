/* 
 * Benchmark Sample ID : devign_9277
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3d0db3e74d818ba43c62cdfb3220e551f4f5ae37
 */

static void spapr_rng_class_init(ObjectClass *oc, void *data)

{

    DeviceClass *dc = DEVICE_CLASS(oc);



    dc->realize = spapr_rng_realize;

    set_bit(DEVICE_CATEGORY_MISC, dc->categories);

    dc->props = spapr_rng_properties;


}
