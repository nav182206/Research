/* 
 * Benchmark Sample ID : devign_4675
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b4ba67d9a702507793c2724e56f98e9b0f7be02b
 */

static void ehci_port_test(struct qhc *hc, int port, uint32_t expect)

{

    void *addr = hc->base + 0x64 + 4 * port;

    uint32_t value = qpci_io_readl(hc->dev, addr);

    uint16_t mask = ~(PORTSC_CSC | PORTSC_PEDC | PORTSC_OCC);



#if 0

    fprintf(stderr, "%s: %d, have 0x%08x, want 0x%08x\n",

            __func__, port, value & mask, expect & mask);

#endif

    g_assert((value & mask) == (expect & mask));

}
