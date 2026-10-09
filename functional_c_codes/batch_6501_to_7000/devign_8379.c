/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8379
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=aa4a3dce1c88ed51b616806b8214b7c8428b7470
 */

static void vmxnet3_deactivate_device(VMXNET3State *s)

{

    VMW_CBPRN("Deactivating vmxnet3...");

    s->device_active = false;

}
