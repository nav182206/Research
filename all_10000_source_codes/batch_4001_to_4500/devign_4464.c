/* 
 * Benchmark Sample ID : devign_4464
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=62030ed135e4cfb960cb626510cbb3ea77bb9ef9
 */

static void test_port(int port)

{

    struct qhc uhci;



    g_assert(port > 0);

    qusb_pci_init_one(qs->pcibus, &uhci, QPCI_DEVFN(0x1d, 0), 4);

    uhci_port_test(&uhci, port - 1, UHCI_PORT_CCS);


}
