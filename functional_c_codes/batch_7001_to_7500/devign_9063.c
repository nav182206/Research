/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9063
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=81e3e75b6461c53724fe7c7918bc54468fcdaf9d
 */

static int pcibus_reset(BusState *qbus)

{

    pci_bus_reset(DO_UPCAST(PCIBus, qbus, qbus));



    /* topology traverse is done by pci_bus_reset().

       Tell qbus/qdev walker not to traverse the tree */

    return 1;

}
