/* 
 * Benchmark Sample ID : devign_7121
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6484e422479c93f28e3f8a68258b0eacd3b31e6d
 */

void qemu_iohandler_fill(GArray *pollfds)

{

    IOHandlerRecord *ioh;



    QLIST_FOREACH(ioh, &io_handlers, next) {

        int events = 0;



        if (ioh->deleted)

            continue;

        if (ioh->fd_read &&

            (!ioh->fd_read_poll ||

             ioh->fd_read_poll(ioh->opaque) != 0)) {

            events |= G_IO_IN | G_IO_HUP | G_IO_ERR;

        }

        if (ioh->fd_write) {

            events |= G_IO_OUT | G_IO_ERR;

        }

        if (events) {

            GPollFD pfd = {

                .fd = ioh->fd,

                .events = events,

            };

            ioh->pollfds_idx = pollfds->len;

            g_array_append_val(pollfds, pfd);

        } else {

            ioh->pollfds_idx = -1;

        }

    }

}
