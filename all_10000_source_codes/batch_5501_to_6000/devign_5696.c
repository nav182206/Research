/* 
 * Benchmark Sample ID : devign_5696
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d7b61ecc61f84d23f98f1ee270fb48b41834ca00
 */

static int unin_internal_pci_host_init(PCIDevice *d)

{

    pci_config_set_vendor_id(d->config, PCI_VENDOR_ID_APPLE);

    pci_config_set_device_id(d->config, PCI_DEVICE_ID_APPLE_UNI_N_I_PCI);

    d->config[0x08] = 0x00; // revision

    pci_config_set_class(d->config, PCI_CLASS_BRIDGE_HOST);

    d->config[0x0C] = 0x08; // cache_line_size

    d->config[0x0D] = 0x10; // latency_timer

    d->config[0x34] = 0x00; // capabilities_pointer

    return 0;

}
