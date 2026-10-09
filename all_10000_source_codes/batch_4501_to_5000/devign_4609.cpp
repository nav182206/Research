/* 
 * Benchmark Sample ID : devign_4609
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=94b037f2a451b3dc855f9f2c346e5049a361bd55
 */

static XHCIEPContext *xhci_alloc_epctx(XHCIState *xhci,

                                       unsigned int slotid,

                                       unsigned int epid)

{

    XHCIEPContext *epctx;

    int i;



    epctx = g_new0(XHCIEPContext, 1);

    epctx->xhci = xhci;

    epctx->slotid = slotid;

    epctx->epid = epid;



    for (i = 0; i < ARRAY_SIZE(epctx->transfers); i++) {

        epctx->transfers[i].xhci = xhci;

        epctx->transfers[i].slotid = slotid;

        epctx->transfers[i].epid = epid;

        usb_packet_init(&epctx->transfers[i].packet);

    }

    epctx->kick_timer = timer_new_ns(QEMU_CLOCK_VIRTUAL, xhci_ep_kick_timer, epctx);



    return epctx;

}
