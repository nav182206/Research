/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_346
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9a75b0a037e3a8030992244353f17b62f6daf2ab
 */

static QPCIDevice *get_ahci_device(uint32_t *fingerprint)

{

    QPCIDevice *ahci;

    uint32_t ahci_fingerprint;

    QPCIBus *pcibus;



    pcibus = qpci_init_pc();



    /* Find the AHCI PCI device and verify it's the right one. */

    ahci = qpci_device_find(pcibus, QPCI_DEVFN(0x1F, 0x02));

    g_assert(ahci != NULL);



    ahci_fingerprint = qpci_config_readl(ahci, PCI_VENDOR_ID);



    switch (ahci_fingerprint) {

    case AHCI_INTEL_ICH9:

        break;

    default:

        /* Unknown device. */

        g_assert_not_reached();

    }



    if (fingerprint) {

        *fingerprint = ahci_fingerprint;

    }

    return ahci;

}
