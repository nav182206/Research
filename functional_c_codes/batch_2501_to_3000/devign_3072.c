/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3072
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=68d553587c0aa271c3eb2902921b503740d775b6
 */

static int ehci_init_transfer(EHCIQueue *q)

{

    uint32_t cpage, offset, bytes, plen;

    target_phys_addr_t page;



    cpage  = get_field(q->qh.token, QTD_TOKEN_CPAGE);

    bytes  = get_field(q->qh.token, QTD_TOKEN_TBYTES);

    offset = q->qh.bufptr[0] & ~QTD_BUFPTR_MASK;

    qemu_sglist_init(&q->sgl, 5);



    while (bytes > 0) {

        if (cpage > 4) {

            fprintf(stderr, "cpage out of range (%d)\n", cpage);

            return USB_RET_PROCERR;

        }



        page  = q->qh.bufptr[cpage] & QTD_BUFPTR_MASK;

        page += offset;

        plen  = bytes;

        if (plen > 4096 - offset) {

            plen = 4096 - offset;

            offset = 0;

            cpage++;

        }



        qemu_sglist_add(&q->sgl, page, plen);

        bytes -= plen;

    }

    return 0;

}
