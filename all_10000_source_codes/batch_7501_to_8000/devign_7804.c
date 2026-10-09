/* 
 * Benchmark Sample ID : devign_7804
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0fada67420e29f389119ca6f44285203400e0730
 */

static bool vhost_section(MemoryRegionSection *section)

{

    return section->address_space == get_system_memory()

        && memory_region_is_ram(section->mr);

}
