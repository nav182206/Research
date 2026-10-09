/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3983
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6f1de6b70d857d5e316ae6fd908f52818b827b08
 */

static gboolean cadence_uart_xmit(GIOChannel *chan, GIOCondition cond,

                                  void *opaque)

{

    CadenceUARTState *s = opaque;

    int ret;



    /* instant drain the fifo when there's no back-end */

    if (!s->chr) {

        s->tx_count = 0;

        return FALSE;

    }



    if (!s->tx_count) {

        return FALSE;

    }



    ret = qemu_chr_fe_write(s->chr, s->tx_fifo, s->tx_count);

    s->tx_count -= ret;

    memmove(s->tx_fifo, s->tx_fifo + ret, s->tx_count);



    if (s->tx_count) {

        int r = qemu_chr_fe_add_watch(s->chr, G_IO_OUT|G_IO_HUP,

                                      cadence_uart_xmit, s);

        assert(r);

    }



    uart_update_status(s);

    return FALSE;

}
