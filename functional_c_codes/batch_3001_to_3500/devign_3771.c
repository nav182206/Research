/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3771
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b4ba67d9a702507793c2724e56f98e9b0f7be02b
 */

void *qpci_legacy_iomap(QPCIDevice *dev, uint16_t addr)

{

    return (void *)(uintptr_t)addr;

}
