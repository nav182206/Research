/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3144
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c2f3029fbc5e7beb4cfb7ac264e10838fada524e
 */

static QPCIDevice *start_ahci_device(QPCIDevice *ahci, void **hba_base)

{

    /* Map AHCI's ABAR (BAR5) */

    *hba_base = qpci_iomap(ahci, 5, NULL);



    /* turns on pci.cmd.iose, pci.cmd.mse and pci.cmd.bme */

    qpci_device_enable(ahci);



    return ahci;

}
