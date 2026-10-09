/* 
 * Benchmark Sample ID : devign_939
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6092666ebdc68b2634db050689292c71a5c368c0
 */

static void core_commit(MemoryListener *listener)

{

    PhysPageMap info = cur_map;

    cur_map = next_map;

    phys_sections_clear(&info);

}
