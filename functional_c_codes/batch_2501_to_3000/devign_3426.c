/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3426
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

MemoryRegion *iotlb_to_region(target_phys_addr_t index)

{

    return phys_sections[index & ~TARGET_PAGE_MASK].mr;

}
