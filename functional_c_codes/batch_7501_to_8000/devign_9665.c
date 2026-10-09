/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9665
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=149f54b53b7666a3facd45e86eece60ce7d3b114
 */

bool cpu_physical_memory_is_io(hwaddr phys_addr)

{

    MemoryRegionSection *section;



    section = phys_page_find(address_space_memory.dispatch,

                             phys_addr >> TARGET_PAGE_BITS);



    return !(memory_region_is_ram(section->mr) ||

             memory_region_is_romd(section->mr));

}
