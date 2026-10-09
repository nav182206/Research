/* 
 * Benchmark Sample ID : devign_271
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9a75b0a037e3a8030992244353f17b62f6daf2ab
 */

static void ahci_pci_enable(AHCIQState *ahci)

{

    uint8_t reg;



    start_ahci_device(ahci);



    switch (ahci->fingerprint) {

    case AHCI_INTEL_ICH9:

        /* ICH9 has a register at PCI 0x92 that

         * acts as a master port enabler mask. */

        reg = qpci_config_readb(ahci->dev, 0x92);

        reg |= 0x3F;

        qpci_config_writeb(ahci->dev, 0x92, reg);

        /* 0...0111111b -- bit significant, ports 0-5 enabled. */

        ASSERT_BIT_SET(qpci_config_readb(ahci->dev, 0x92), 0x3F);

        break;

    }



}
