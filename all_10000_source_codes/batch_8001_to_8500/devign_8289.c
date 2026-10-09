/* 
 * Benchmark Sample ID : devign_8289
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=21e00fa55f3fdfcbb20da7c6876c91ef3609b387
 */

static bool vfio_prereg_listener_skipped_section(MemoryRegionSection *section)

{

    if (memory_region_is_iommu(section->mr)) {

        hw_error("Cannot possibly preregister IOMMU memory");

    }



    return !memory_region_is_ram(section->mr) ||

            memory_region_is_skip_dump(section->mr);

}
