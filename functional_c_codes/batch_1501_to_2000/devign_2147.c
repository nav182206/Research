/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2147
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d659d94013390238961fac741572306c95496bf5
 */

static void pcie_pci_bridge_reset(DeviceState *qdev)

{

    PCIDevice *d = PCI_DEVICE(qdev);

    pci_bridge_reset(qdev);

    msi_reset(d);

    shpc_reset(d);

}
