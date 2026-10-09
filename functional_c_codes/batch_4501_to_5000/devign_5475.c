/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5475
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c82dc29a9112f34e0a51cad9a412cf6d9d05dfb2
 */

int qemu_set_fd_handler(int fd,

                        IOHandler *fd_read,

                        IOHandler *fd_write,

                        void *opaque)

{

    static IOTrampoline fd_trampolines[FD_SETSIZE];

    IOTrampoline *tramp = &fd_trampolines[fd];



    if (tramp->tag != 0) {

        g_io_channel_unref(tramp->chan);

        g_source_remove(tramp->tag);

    }



    if (opaque) {

        GIOCondition cond = 0;



        tramp->fd_read = fd_read;

        tramp->fd_write = fd_write;

        tramp->opaque = opaque;



        if (fd_read) {

            cond |= G_IO_IN | G_IO_ERR;

        }



        if (fd_write) {

            cond |= G_IO_OUT | G_IO_ERR;

        }



        tramp->chan = g_io_channel_unix_new(fd);

        tramp->tag = g_io_add_watch(tramp->chan, cond, fd_trampoline, tramp);

    }



    return 0;

}
