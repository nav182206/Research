/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_9387
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=384acbf46b70edf0d2c1648aa1a92a90bcf7057d
 */

void qemu_bh_update_timeout(int *timeout)

{

    QEMUBH *bh;



    for (bh = async_context->first_bh; bh; bh = bh->next) {

        if (!bh->deleted && bh->scheduled) {

            if (bh->idle) {

                /* idle bottom halves will be polled at least

                 * every 10ms */

                *timeout = MIN(10, *timeout);

            } else {

                /* non-idle bottom halves will be executed

                 * immediately */

                *timeout = 0;

                break;

            }

        }

    }

}
