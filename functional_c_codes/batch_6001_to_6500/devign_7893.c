/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7893
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b4ba67d9a702507793c2724e56f98e9b0f7be02b
 */

static uint16_t qvirtio_pci_config_readw(QVirtioDevice *d, uint64_t off)

{

    QVirtioPCIDevice *dev = (QVirtioPCIDevice *)d;

    uint16_t value;



    value = qpci_io_readw(dev->pdev, CONFIG_BASE(dev) + off);

    if (qvirtio_is_big_endian(d)) {

        value = bswap16(value);

    }

    return value;

}
