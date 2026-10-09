/* 
 * Benchmark Sample ID : devign_6694
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=54688b1ec1f468c7272b837ff57298068aaedf5f
 */

static void core_region_del(MemoryListener *listener,

                            MemoryRegionSection *section)

{

    cpu_register_physical_memory_log(section, false);

}
