/* 
 * Benchmark Sample ID : devign_7459
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a369da5f31ddbdeb32a7f76622e480d3995fbb00
 */

DeviceState *pc_vga_init(ISABus *isa_bus, PCIBus *pci_bus)

{

    DeviceState *dev = NULL;



    if (cirrus_vga_enabled) {

        if (pci_bus) {

            dev = pci_cirrus_vga_init(pci_bus);

        } else {

            dev = isa_cirrus_vga_init(get_system_memory());

        }

    } else if (vmsvga_enabled) {

        if (pci_bus) {

            dev = pci_vmsvga_init(pci_bus);

            if (!dev) {

                fprintf(stderr, "Warning: vmware_vga not available,"

                        " using standard VGA instead\n");

                dev = pci_vga_init(pci_bus);

            }

        } else {

            fprintf(stderr, "%s: vmware_vga: no PCI bus\n", __FUNCTION__);

        }

#ifdef CONFIG_SPICE

    } else if (qxl_enabled) {

        if (pci_bus) {

            dev = &pci_create_simple(pci_bus, -1, "qxl-vga")->qdev;

        } else {

            fprintf(stderr, "%s: qxl: no PCI bus\n", __FUNCTION__);

        }

#endif

    } else if (std_vga_enabled) {

        if (pci_bus) {

            dev = pci_vga_init(pci_bus);

        } else {

            dev = isa_vga_init(isa_bus);

        }

    }



    return dev;

}
