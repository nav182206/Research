/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7317
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2634ab7fe29b3f75d0865b719caf8f310d634aae
 */

static void pci_nic_uninit(PCIDevice *pci_dev)

{

    EEPRO100State *s = DO_UPCAST(EEPRO100State, dev, pci_dev);



    vmstate_unregister(&pci_dev->qdev, s->vmstate, s);


    eeprom93xx_free(&pci_dev->qdev, s->eeprom);

    qemu_del_nic(s->nic);

}
