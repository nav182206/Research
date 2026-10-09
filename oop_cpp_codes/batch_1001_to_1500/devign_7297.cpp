/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_7297
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=94b037f2a451b3dc855f9f2c346e5049a361bd55
 */

static int xhci_ep_nuke_one_xfer(XHCITransfer *t, TRBCCode report)

{

    int killed = 0;



    if (report && (t->running_async || t->running_retry)) {

        t->status = report;

        xhci_xfer_report(t);

    }



    if (t->running_async) {

        usb_cancel_packet(&t->packet);

        t->running_async = 0;

        killed = 1;

    }

    if (t->running_retry) {

        XHCIEPContext *epctx = t->xhci->slots[t->slotid-1].eps[t->epid-1];

        if (epctx) {

            epctx->retry = NULL;

            timer_del(epctx->kick_timer);

        }

        t->running_retry = 0;

        killed = 1;

    }

    g_free(t->trbs);



    t->trbs = NULL;

    t->trb_count = t->trb_alloced = 0;



    return killed;

}
