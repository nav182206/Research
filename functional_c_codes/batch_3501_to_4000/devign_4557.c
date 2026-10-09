/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4557
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

assigned_dev_msix_mmio_read(void *opaque, target_phys_addr_t addr,

                            unsigned size)

{

    AssignedDevice *adev = opaque;

    uint64_t val;



    memcpy(&val, (void *)((uint8_t *)adev->msix_table + addr), size);



    return val;

}
