/* 
 * Benchmark Sample ID : devign_808
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=fd56e0612b6454a282fa6a953fdb09281a98c589
 */

static void pci_bridge_region_del(PCIBridge *br, PCIBridgeWindows *w)

{

    PCIDevice *pd = PCI_DEVICE(br);

    PCIBus *parent = pd->bus;



    memory_region_del_subregion(parent->address_space_io, &w->alias_io);

    memory_region_del_subregion(parent->address_space_mem, &w->alias_mem);

    memory_region_del_subregion(parent->address_space_mem, &w->alias_pref_mem);

    pci_unregister_vga(pd);

}
