/* 
 * Benchmark Sample ID : devign_7975
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=af60314291af3cabda18d27f928b0e0ff899cc76
 */

static bool vhost_section(MemoryRegionSection *section)

{

    return memory_region_is_ram(section->mr);

}
