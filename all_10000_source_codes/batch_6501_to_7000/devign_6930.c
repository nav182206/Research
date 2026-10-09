/* 
 * Benchmark Sample ID : devign_6930
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=53cb28cbfea038f8ad50132dc8a684e638c7d48b
 */

static uint16_t dummy_section(MemoryRegion *mr)

{

    MemoryRegionSection section = {

        .mr = mr,

        .offset_within_address_space = 0,

        .offset_within_region = 0,

        .size = int128_2_64(),

    };



    return phys_section_add(&section);

}
