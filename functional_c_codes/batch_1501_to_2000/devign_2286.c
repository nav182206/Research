/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2286
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9a75b0a037e3a8030992244353f17b62f6daf2ab
 */

static void free_ahci_device(QPCIDevice *dev)

{

    QPCIBus *pcibus = dev ? dev->bus : NULL;



    /* libqos doesn't have a function for this, so free it manually */

    g_free(dev);

    qpci_free_pc(pcibus);

}
