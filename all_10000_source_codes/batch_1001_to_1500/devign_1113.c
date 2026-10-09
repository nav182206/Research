/* 
 * Benchmark Sample ID : devign_1113
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8f6e699ddbcad32480fa64796ccf44cbaf5b4b91
 */

static void lsi_transfer_data(SCSIRequest *req, uint32_t len)

{

    LSIState *s = DO_UPCAST(LSIState, dev.qdev, req->bus->qbus.parent);

    int out;



    if (s->waiting == 1 || !s->current || req->hba_private != s->current ||

        (lsi_irq_on_rsl(s) && !(s->scntl1 & LSI_SCNTL1_CON))) {

        if (lsi_queue_req(s, req, len)) {

            return;

        }

    }



    out = (s->sstat1 & PHASE_MASK) == PHASE_DO;



    /* host adapter (re)connected */

    DPRINTF("Data ready tag=0x%x len=%d\n", req->tag, len);

    s->current->dma_len = len;

    s->command_complete = 1;

    if (s->waiting) {

        if (s->waiting == 1 || s->dbc == 0) {

            lsi_resume_script(s);

        } else {

            lsi_do_dma(s, out);

        }

    }

}
