/* 
 * Benchmark Sample ID : devign_3316
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=523a59f596a3e62f5a28eb171adba35e71310040
 */

void pci_bridge_exitfn(PCIDevice *pci_dev)

{

    PCIBridge *s = DO_UPCAST(PCIBridge, dev, pci_dev);

    assert(QLIST_EMPTY(&s->sec_bus.child));

    QLIST_REMOVE(&s->sec_bus, sibling);

    pci_bridge_region_cleanup(s);

    memory_region_destroy(&s->address_space_mem);

    memory_region_destroy(&s->address_space_io);

    /* qbus_free() is called automatically by qdev_free() */

}
