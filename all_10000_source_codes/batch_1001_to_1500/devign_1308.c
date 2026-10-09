/* 
 * Benchmark Sample ID : devign_1308
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8360544a6d3a54df1fce80f55ba4ad075a8ded54
 */

static void qpci_spapr_io_writeb(QPCIBus *bus, void *addr, uint8_t value)

{

    QPCIBusSPAPR *s = container_of(bus, QPCIBusSPAPR, bus);

    uint64_t port = (uintptr_t)addr;

    if (port < s->pio.size) {

        writeb(s->pio_cpu_base + port, value);

    } else {

        writeb(s->mmio_cpu_base + port, value);

    }

}
