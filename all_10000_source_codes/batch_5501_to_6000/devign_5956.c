/* 
 * Benchmark Sample ID : devign_5956
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=05b685fbabb7fdcab72cb42b27db916fd74b2265
 */

iscsi_set_events(IscsiLun *iscsilun)

{

    struct iscsi_context *iscsi = iscsilun->iscsi;

    int ev;



    /* We always register a read handler.  */

    ev = POLLIN;

    ev |= iscsi_which_events(iscsi);

    if (ev != iscsilun->events) {

        aio_set_fd_handler(iscsilun->aio_context,

                           iscsi_get_fd(iscsi),

                           iscsi_process_read,

                           (ev & POLLOUT) ? iscsi_process_write : NULL,

                           iscsilun);



    }



    iscsilun->events = ev;

}
