/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3832
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=72cf2d4f0e181d0d3a3122e04129c58a95da713e
 */

void usb_register_port(USBBus *bus, USBPort *port, void *opaque, int index,

                       usb_attachfn attach)

{

    port->opaque = opaque;

    port->index = index;

    port->attach = attach;

    TAILQ_INSERT_TAIL(&bus->free, port, next);

    bus->nfree++;

}
