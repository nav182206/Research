/* 
 * Benchmark Sample ID : devign_9720
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=49bd1458da8909434eb83c5cda472c63ff6a529c
 */

static PCIBus *pci_get_bus_devfn(int *devfnp, const char *devaddr)

{

    int dom, bus;

    unsigned slot;



    if (!devaddr) {

        *devfnp = -1;

        return pci_find_bus(0);

    }



    if (pci_parse_devaddr(devaddr, &dom, &bus, &slot) < 0) {

        return NULL;

    }



    *devfnp = slot << 3;

    return pci_find_bus(bus);

}
