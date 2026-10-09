/* 
 * Benchmark Sample ID : devign_4748
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ae4d2eb273b167dad748ea4249720319240b1ac2
 */

static void unplug_disks(PCIBus *b, PCIDevice *d, void *o)

{

    /* We have to ignore passthrough devices */

    if (!strcmp(d->name, "xen-pci-passthrough")) {

        return;

    }



    switch (pci_get_word(d->config + PCI_CLASS_DEVICE)) {

    case PCI_CLASS_STORAGE_IDE:

        pci_piix3_xen_ide_unplug(DEVICE(d));

        break;



    case PCI_CLASS_STORAGE_SCSI:

    case PCI_CLASS_STORAGE_EXPRESS:

        object_unparent(OBJECT(d));

        break;



    default:

        break;

    }

}
