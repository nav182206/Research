/* 
 * Benchmark Sample ID : devign_1591
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=43e86c8f5b6d9f6279e20dede4e1f7829bdc43b7
 */

static uint32_t pcie_mmcfg_data_read(PCIBus *s, uint32_t addr, int len)

{

    PCIDevice *pci_dev = pcie_dev_find_by_mmcfg_addr(s, addr);



    if (!pci_dev) {

        return ~0x0;

    }

    return pci_host_config_read_common(pci_dev, PCIE_MMCFG_CONFOFFSET(addr),

                                       pci_config_size(pci_dev), len);

}
