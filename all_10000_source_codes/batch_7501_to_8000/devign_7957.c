/* 
 * Benchmark Sample ID : devign_7957
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c4523aae0664aecaa366d45e3d0f3d810ca33062
 */

QVirtioPCIDevice *qvirtio_pci_device_find(QPCIBus *bus, uint16_t device_type)

{

    QVirtioPCIDevice *dev = NULL;

    qvirtio_pci_foreach(bus, device_type, qvirtio_pci_assign_device, &dev);



    dev->vdev.bus = &qvirtio_pci;



    return dev;

}
