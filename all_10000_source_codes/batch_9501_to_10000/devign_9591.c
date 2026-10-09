/* 
 * Benchmark Sample ID : devign_9591
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b4ba67d9a702507793c2724e56f98e9b0f7be02b
 */

void start_ahci_device(AHCIQState *ahci)

{

    /* Map AHCI's ABAR (BAR5) */

    ahci->hba_base = qpci_iomap(ahci->dev, 5, &ahci->barsize);

    g_assert(ahci->hba_base);



    /* turns on pci.cmd.iose, pci.cmd.mse and pci.cmd.bme */

    qpci_device_enable(ahci->dev);

}
