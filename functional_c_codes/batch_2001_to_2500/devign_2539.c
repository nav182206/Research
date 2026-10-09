/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2539
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=bdfce20df113522f389b4483ffd9d5b336e3c774
 */

static void xhci_port_write(void *ptr, hwaddr reg,

                            uint64_t val, unsigned size)

{

    XHCIPort *port = ptr;

    uint32_t portsc;



    trace_usb_xhci_port_write(port->portnr, reg, val);



    switch (reg) {

    case 0x00: /* PORTSC */

        portsc = port->portsc;

        /* write-1-to-clear bits*/

        portsc &= ~(val & (PORTSC_CSC|PORTSC_PEC|PORTSC_WRC|PORTSC_OCC|

                           PORTSC_PRC|PORTSC_PLC|PORTSC_CEC));

        if (val & PORTSC_LWS) {

            /* overwrite PLS only when LWS=1 */

            uint32_t pls = get_field(val, PORTSC_PLS);

            set_field(&portsc, pls, PORTSC_PLS);

            trace_usb_xhci_port_link(port->portnr, pls);

        }

        /* read/write bits */

        portsc &= ~(PORTSC_PP|PORTSC_WCE|PORTSC_WDE|PORTSC_WOE);

        portsc |= (val & (PORTSC_PP|PORTSC_WCE|PORTSC_WDE|PORTSC_WOE));

        port->portsc = portsc;

        /* write-1-to-start bits */

        if (val & PORTSC_PR) {

            xhci_port_reset(port);

        }

        break;

    case 0x04: /* PORTPMSC */

    case 0x08: /* PORTLI */

    default:

        trace_usb_xhci_unimplemented("port write", reg);

    }

}
