/* 
 * Benchmark Sample ID : devign_4368
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=87ca1f77b1c406137fe36ab73b2dc91fb75f8d0a
 */

static void vfio_listener_release(VFIOContainer *container)

{

    memory_listener_unregister(&container->iommu_data.listener);

}
