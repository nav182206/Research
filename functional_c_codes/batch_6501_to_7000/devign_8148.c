/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8148
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b23046abe78f48498a423b802d6d86ba0172d57f
 */

static void build_pci_bus_state_init(AcpiBuildPciBusHotplugState *state,

                                     AcpiBuildPciBusHotplugState *parent,

                                     bool pcihp_bridge_en)

{

    state->parent = parent;

    state->device_table = build_alloc_array();

    state->notify_table = build_alloc_array();

    state->pcihp_bridge_en = pcihp_bridge_en;

}
