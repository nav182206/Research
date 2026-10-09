/* 
 * Benchmark Sample ID : devign_6040
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a879125b47c3ae554c01824f996a64a45a86556e
 */

static uint16_t qpci_pc_config_readw(QPCIBus *bus, int devfn, uint8_t offset)

{

    outl(0xcf8, (1 << 31) | (devfn << 8) | offset);

    return inw(0xcfc);

}
