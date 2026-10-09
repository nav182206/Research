/* 
 * Benchmark Sample ID : devign_4610
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=03f4995781a64e106e6f73864a1e9c4163dac53b
 */

static uint16_t phys_map_node_alloc(void)

{

    unsigned i;

    uint16_t ret;



    ret = next_map.nodes_nb++;

    assert(ret != PHYS_MAP_NODE_NIL);

    assert(ret != next_map.nodes_nb_alloc);

    for (i = 0; i < L2_SIZE; ++i) {

        next_map.nodes[ret][i].is_leaf = 0;

        next_map.nodes[ret][i].ptr = PHYS_MAP_NODE_NIL;

    }

    return ret;

}
