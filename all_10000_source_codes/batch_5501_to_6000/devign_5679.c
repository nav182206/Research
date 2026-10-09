/* 
 * Benchmark Sample ID : devign_5679
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b645000e1ac430601eddb0b435936837aea94bb4
 */

PCIBus *pci_get_bus_devfn(int *devfnp, PCIBus *root, const char *devaddr)

{

    int dom, bus;

    unsigned slot;



    assert(!root->parent_dev);



    if (!root) {

        fprintf(stderr, "No primary PCI bus\n");

        return NULL;

    }



    if (!devaddr) {

        *devfnp = -1;

        return pci_find_bus_nr(root, 0);

    }



    if (pci_parse_devaddr(devaddr, &dom, &bus, &slot, NULL) < 0) {

        return NULL;

    }



    if (dom != 0) {

        fprintf(stderr, "No support for non-zero PCI domains\n");

        return NULL;

    }



    *devfnp = PCI_DEVFN(slot, 0);

    return pci_find_bus_nr(root, bus);

}
