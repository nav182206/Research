/* 
 * Benchmark Sample ID : devign_4707
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=fd56e0612b6454a282fa6a953fdb09281a98c589
 */

static void pci_update_mappings(PCIDevice *d)

{

    PCIIORegion *r;

    int i;

    pcibus_t new_addr;



    for(i = 0; i < PCI_NUM_REGIONS; i++) {

        r = &d->io_regions[i];



        /* this region isn't registered */

        if (!r->size)

            continue;



        new_addr = pci_bar_address(d, i, r->type, r->size);



        /* This bar isn't changed */

        if (new_addr == r->addr)

            continue;



        /* now do the real mapping */

        if (r->addr != PCI_BAR_UNMAPPED) {

            trace_pci_update_mappings_del(d, pci_bus_num(d->bus),

                                          PCI_SLOT(d->devfn),

                                          PCI_FUNC(d->devfn),

                                          i, r->addr, r->size);

            memory_region_del_subregion(r->address_space, r->memory);

        }

        r->addr = new_addr;

        if (r->addr != PCI_BAR_UNMAPPED) {

            trace_pci_update_mappings_add(d, pci_bus_num(d->bus),

                                          PCI_SLOT(d->devfn),

                                          PCI_FUNC(d->devfn),

                                          i, r->addr, r->size);

            memory_region_add_subregion_overlap(r->address_space,

                                                r->addr, r->memory, 1);

        }

    }



    pci_update_vga(d);

}
