/* 
 * Benchmark Sample ID : devign_7798
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static void timerblock_write(void *opaque, target_phys_addr_t addr,

                             uint64_t value, unsigned size)

{

    timerblock *tb = (timerblock *)opaque;

    int64_t old;

    switch (addr) {

    case 0: /* Load */

        tb->load = value;

        /* Fall through.  */

    case 4: /* Counter.  */

        if ((tb->control & 1) && tb->count) {

            /* Cancel the previous timer.  */

            qemu_del_timer(tb->timer);

        }

        tb->count = value;

        if (tb->control & 1) {

            timerblock_reload(tb, 1);

        }

        break;

    case 8: /* Control.  */

        old = tb->control;

        tb->control = value;

        if (((old & 1) == 0) && (value & 1)) {

            if (tb->count == 0 && (tb->control & 2)) {

                tb->count = tb->load;

            }

            timerblock_reload(tb, 1);

        }

        break;

    case 12: /* Interrupt status.  */

        tb->status &= ~value;

        timerblock_update_irq(tb);

        break;

    }

}
