/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8811
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a88ae0d44b6b5830b752641b2198735272f13eaf
 */

static void pc_xen_hvm_init(MachineState *machine)
{
    PCIBus *bus;
    pc_xen_hvm_init_pci(machine);
    bus = pci_find_primary_bus();
    if (bus != NULL) {
        pci_create_simple(bus, -1, "xen-platform");
