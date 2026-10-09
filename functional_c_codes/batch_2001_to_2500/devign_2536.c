/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2536
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=66a08cbe6ad1aebec8eecf58b3ba042e19dd1649
 */

static void uhci_queue_fill(UHCIQueue *q, UHCI_TD *td)

{

    uint32_t int_mask = 0;

    uint32_t plink = td->link;

    UHCI_TD ptd;

    int ret;



    while (is_valid(plink)) {

        uhci_read_td(q->uhci, &ptd, plink);

        if (!(ptd.ctrl & TD_CTRL_ACTIVE)) {

            break;

        }

        if (uhci_queue_token(&ptd) != q->token) {

            break;

        }

        trace_usb_uhci_td_queue(plink & ~0xf, ptd.ctrl, ptd.token);

        ret = uhci_handle_td(q->uhci, q, &ptd, plink, &int_mask);

        if (ret == TD_RESULT_ASYNC_CONT) {

            break;

        }

        assert(ret == TD_RESULT_ASYNC_START);

        assert(int_mask == 0);

        plink = ptd.link;

    }

    usb_device_flush_ep_queue(q->ep->dev, q->ep);

}
