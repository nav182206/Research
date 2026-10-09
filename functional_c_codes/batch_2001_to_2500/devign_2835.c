/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2835
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b4ba67d9a702507793c2724e56f98e9b0f7be02b
 */

uint32_t qpci_io_readl(QPCIDevice *dev, void *data)

{

    uintptr_t addr = (uintptr_t)data;



    if (addr < QPCI_PIO_LIMIT) {

        return dev->bus->pio_readl(dev->bus, addr);

    } else {

        uint32_t val;

        dev->bus->memread(dev->bus, addr, &val, sizeof(val));

        return le32_to_cpu(val);

    }

}
