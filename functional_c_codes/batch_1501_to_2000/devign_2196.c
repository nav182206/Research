/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2196
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=692d88b4085559f1254d0e04d64a849ce8ab5932
 */

static void mux_chr_update_read_handler(CharDriverState *chr,

                                        GMainContext *context)

{

    MuxDriver *d = chr->opaque;

    int idx;



    if (d->mux_cnt >= MAX_MUX) {

        fprintf(stderr, "Cannot add I/O handlers, MUX array is full\n");

        return;

    }



    if (chr->mux_idx == -1) {

        chr->mux_idx = d->mux_cnt++;

    }



    idx = chr->mux_idx;

    d->ext_opaque[idx] = chr->handler_opaque;

    d->chr_can_read[idx] = chr->chr_can_read;

    d->chr_read[idx] = chr->chr_read;

    d->chr_event[idx] = chr->chr_event;



    /* Fix up the real driver with mux routines */

    if (d->mux_cnt == 1) {

        qemu_chr_add_handlers_full(d->drv, mux_chr_can_read,

                                   mux_chr_read,

                                   mux_chr_event,

                                   chr, context);

    }

    if (d->focus != -1) {

        mux_chr_send_event(d, d->focus, CHR_EVENT_MUX_OUT);

    }

    d->focus = idx;

    mux_chr_send_event(d, d->focus, CHR_EVENT_MUX_IN);

}
