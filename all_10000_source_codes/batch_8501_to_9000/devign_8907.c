/* 
 * Benchmark Sample ID : devign_8907
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=fa1298c2d623522eda7b4f1f721fcb935abb7360
 */

static void ohci_bus_stop(OHCIState *ohci)

{

    trace_usb_ohci_stop(ohci->name);

    if (ohci->eof_timer) {

        timer_del(ohci->eof_timer);

        timer_free(ohci->eof_timer);

    }

    ohci->eof_timer = NULL;

}
