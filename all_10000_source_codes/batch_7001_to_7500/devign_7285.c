/* 
 * Benchmark Sample ID : devign_7285
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ac1970fbe8ad5a70174f462109ac0f6c7bf1bc43
 */

static void destroy_all_mappings(void)

{

    destroy_l2_mapping(&phys_map, P_L2_LEVELS - 1);

    phys_map_nodes_reset();

}
