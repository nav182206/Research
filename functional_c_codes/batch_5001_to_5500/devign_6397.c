/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6397
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4accd107d0fd4a6fd7d2ad4f3365c67623834262
 */

static void unplug_nic(PCIBus *b, PCIDevice *d)

{

    if (pci_get_word(d->config + PCI_CLASS_DEVICE) ==

            PCI_CLASS_NETWORK_ETHERNET) {

        qdev_unplug(&(d->qdev), NULL);

    }

}
