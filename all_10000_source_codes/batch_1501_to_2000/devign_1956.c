/* 
 * Benchmark Sample ID : devign_1956
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b4ba67d9a702507793c2724e56f98e9b0f7be02b
 */

void qpci_io_writel(QPCIDevice *dev, void *data, uint32_t value)

{

    uintptr_t addr = (uintptr_t)data;



    if (addr < QPCI_PIO_LIMIT) {

        dev->bus->pio_writel(dev->bus, addr, value);

    } else {

        value = cpu_to_le32(value);

        dev->bus->memwrite(dev->bus, addr, &value, sizeof(value));

    }

}
