/* 
 * Benchmark Sample ID : devign_1706
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=fff23ee9a5de74ab111b3cea9eec56782e7d7c50
 */

static UHCIAsync *uhci_async_alloc(UHCIState *s)

{

    UHCIAsync *async = g_malloc(sizeof(UHCIAsync));



    memset(&async->packet, 0, sizeof(async->packet));

    async->uhci  = s;

    async->valid = 0;

    async->td    = 0;

    async->token = 0;

    async->done  = 0;

    async->isoc  = 0;

    usb_packet_init(&async->packet);

    qemu_sglist_init(&async->sgl, 1);



    return async;

}
