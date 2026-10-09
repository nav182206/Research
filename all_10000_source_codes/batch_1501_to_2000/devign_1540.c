/* 
 * Benchmark Sample ID : devign_1540
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b308c82cbda44e138ef990af64d44a5613c16092
 */

static void pci_bridge_update_mappings(PCIBridge *br)

{

    /* Make updates atomic to: handle the case of one VCPU updating the bridge

     * while another accesses an unaffected region. */

    memory_region_transaction_begin();

    pci_bridge_region_cleanup(br);

    pci_bridge_region_init(br);

    memory_region_transaction_commit();

}
