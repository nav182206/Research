/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3789
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=bbbc39ccacf66ef58261c155f9eed503947c3023
 */

static int ehci_reset_queue(EHCIQueue *q)

{

    int packets;



    trace_usb_ehci_queue_action(q, "reset");

    packets = ehci_cancel_queue(q);

    q->dev = NULL;

    q->qtdaddr = 0;


    return packets;

}
