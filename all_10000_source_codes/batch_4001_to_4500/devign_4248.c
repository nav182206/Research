/* 
 * Benchmark Sample ID : devign_4248
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b4ba67d9a702507793c2724e56f98e9b0f7be02b
 */

uint8_t qpci_io_readb(QPCIDevice *dev, void *data)

{

    uintptr_t addr = (uintptr_t)data;



    if (addr < QPCI_PIO_LIMIT) {

        return dev->bus->pio_readb(dev->bus, addr);

    } else {

        uint8_t val;

        dev->bus->memread(dev->bus, addr, &val, sizeof(val));

        return val;

    }

}
