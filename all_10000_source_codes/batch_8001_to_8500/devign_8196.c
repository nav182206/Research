/* 
 * Benchmark Sample ID : devign_8196
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=fd56e0612b6454a282fa6a953fdb09281a98c589
 */

static void piix4_pm_machine_ready(Notifier *n, void *opaque)

{

    PIIX4PMState *s = container_of(n, PIIX4PMState, machine_ready);

    PCIDevice *d = PCI_DEVICE(s);

    MemoryRegion *io_as = pci_address_space_io(d);

    uint8_t *pci_conf;



    pci_conf = d->config;

    pci_conf[0x5f] = 0x10 |

        (memory_region_present(io_as, 0x378) ? 0x80 : 0);

    pci_conf[0x63] = 0x60;

    pci_conf[0x67] = (memory_region_present(io_as, 0x3f8) ? 0x08 : 0) |

        (memory_region_present(io_as, 0x2f8) ? 0x90 : 0);



    if (s->use_acpi_pci_hotplug) {

        pci_for_each_bus(d->bus, piix4_update_bus_hotplug, s);

    } else {

        piix4_update_bus_hotplug(d->bus, s);

    }

}
