/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7920
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b23046abe78f48498a423b802d6d86ba0172d57f
 */

static void *build_pci_bus_begin(PCIBus *bus, void *parent_state)

{

    AcpiBuildPciBusHotplugState *parent = parent_state;

    AcpiBuildPciBusHotplugState *child = g_malloc(sizeof *child);



    build_pci_bus_state_init(child, parent, parent->pcihp_bridge_en);



    return child;

}
