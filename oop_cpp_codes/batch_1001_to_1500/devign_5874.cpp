/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_5874
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e4f4fb1eca795e36f363b4647724221e774523c1
 */

static void vfio_amd_xgbe_class_init(ObjectClass *klass, void *data)

{

    DeviceClass *dc = DEVICE_CLASS(klass);

    VFIOAmdXgbeDeviceClass *vcxc =

        VFIO_AMD_XGBE_DEVICE_CLASS(klass);

    vcxc->parent_realize = dc->realize;

    dc->realize = amd_xgbe_realize;

    dc->desc = "VFIO AMD XGBE";

    dc->vmsd = &vfio_platform_amd_xgbe_vmstate;



}
