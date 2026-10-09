/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8212
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b4ba67d9a702507793c2724e56f98e9b0f7be02b
 */

static void pci_ehci_config(void)

{

    /* hands over all ports from companion uhci to ehci */

    qpci_io_writew(ehci1.dev, ehci1.base + 0x60, 1);

}
