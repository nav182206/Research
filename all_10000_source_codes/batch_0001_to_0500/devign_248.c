/* 
 * Benchmark Sample ID : devign_248
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=fb23162885f7fd8cf7334bed22c25ac32c7d8b9d
 */

PCIDevice *pci_register_device(PCIBus *bus, const char *name,

                               int instance_size, int devfn,

                               PCIConfigReadFunc *config_read,

                               PCIConfigWriteFunc *config_write)

{

    PCIDevice *pci_dev;



    pci_dev = qemu_mallocz(instance_size);

    pci_dev = do_pci_register_device(pci_dev, bus, name, devfn,

                                     config_read, config_write);

    return pci_dev;

}
