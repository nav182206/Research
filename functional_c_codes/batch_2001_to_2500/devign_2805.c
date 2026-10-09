/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2805
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=42e4126b793d15ec40f3a84017e1d8afecda1b6d
 */

uint32_t pci_data_read(PCIBus *s, uint32_t addr, int len)

{

    PCIDevice *pci_dev = pci_dev_find_by_addr(s, addr);

    uint32_t config_addr = addr & (PCI_CONFIG_SPACE_SIZE - 1);

    uint32_t val;



    assert(len == 1 || len == 2 || len == 4);

    if (!pci_dev) {

        return ~0x0;

    }



    val = pci_dev->config_read(pci_dev, config_addr, len);

    PCI_DPRINTF("%s: %s: addr=%02"PRIx32" val=%08"PRIx32" len=%d\n",

                __func__, pci_dev->name, config_addr, val, len);



    return val;

}
