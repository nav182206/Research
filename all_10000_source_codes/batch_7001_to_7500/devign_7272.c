/* 
 * Benchmark Sample ID : devign_7272
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b4ba67d9a702507793c2724e56f98e9b0f7be02b
 */

void uhci_port_test(struct qhc *hc, int port, uint16_t expect)

{

    void *addr = hc->base + 0x10 + 2 * port;

    uint16_t value = qpci_io_readw(hc->dev, addr);

    uint16_t mask = ~(UHCI_PORT_WRITE_CLEAR | UHCI_PORT_RSVD1);



    g_assert((value & mask) == (expect & mask));

}
