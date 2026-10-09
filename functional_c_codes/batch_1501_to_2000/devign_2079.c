/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2079
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4f5e19e6c570459cd524b29b24374f03860f5149
 */

static int pci_dec_21154_init_device(SysBusDevice *dev)

{

    UNINState *s;

    int pci_mem_config, pci_mem_data;



    /* Uninorth bridge */

    s = FROM_SYSBUS(UNINState, dev);



    // XXX: s = &pci_bridge[2];

    pci_mem_config = cpu_register_io_memory(pci_unin_config_read,

                                            pci_unin_config_write, s);

    pci_mem_data = cpu_register_io_memory(pci_unin_main_read,

                                          pci_unin_main_write, &s->host_state);

    sysbus_init_mmio(dev, 0x1000, pci_mem_config);

    sysbus_init_mmio(dev, 0x1000, pci_mem_data);

    return 0;

}
