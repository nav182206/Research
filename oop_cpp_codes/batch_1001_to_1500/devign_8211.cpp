/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_8211
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e4f4fb1eca795e36f363b4647724221e774523c1
 */

static void amdvi_class_init(ObjectClass *klass, void* data)

{

    DeviceClass *dc = DEVICE_CLASS(klass);

    X86IOMMUClass *dc_class = X86_IOMMU_CLASS(klass);



    dc->reset = amdvi_reset;

    dc->vmsd = &vmstate_amdvi;

    dc->hotpluggable = false;

    dc_class->realize = amdvi_realize;






}
