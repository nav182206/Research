/* 
 * Benchmark Sample ID : devign_1004
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static void map_page(uint8_t **ptr, uint64_t addr, uint32_t wanted)

{

    target_phys_addr_t len = wanted;



    if (*ptr) {

        cpu_physical_memory_unmap(*ptr, len, 1, len);

    }



    *ptr = cpu_physical_memory_map(addr, &len, 1);

    if (len < wanted) {

        cpu_physical_memory_unmap(*ptr, len, 1, len);

        *ptr = NULL;

    }

}
