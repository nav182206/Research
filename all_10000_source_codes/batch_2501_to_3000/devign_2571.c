/* 
 * Benchmark Sample ID : devign_2571
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=523a59f596a3e62f5a28eb171adba35e71310040
 */

static void pci_bridge_region_cleanup(PCIBridge *br)

{

    PCIBus *parent = br->dev.bus;

    pci_bridge_cleanup_alias(&br->alias_io,

                             parent->address_space_io);

    pci_bridge_cleanup_alias(&br->alias_mem,

                             parent->address_space_mem);

    pci_bridge_cleanup_alias(&br->alias_pref_mem,

                             parent->address_space_mem);

}
