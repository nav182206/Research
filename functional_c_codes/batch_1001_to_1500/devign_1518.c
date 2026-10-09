/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1518
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=46c5874e9cd752ed8ded31af03472edd8fc3efc1
 */

static PCIDevice *find_dev(sPAPREnvironment *spapr, uint64_t buid,

                           uint32_t config_addr)

{

    sPAPRPHBState *sphb = find_phb(spapr, buid);

    PCIHostState *phb = PCI_HOST_BRIDGE(sphb);

    int bus_num = (config_addr >> 16) & 0xFF;

    int devfn = (config_addr >> 8) & 0xFF;



    if (!phb) {

        return NULL;

    }



    return pci_find_device(phb->bus, bus_num, devfn);

}
