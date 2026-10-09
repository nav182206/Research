/* 
 * Benchmark Sample ID : devign_9578
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1f001dc7bc9e435bf231a5b0edcad1c7c2bd6214
 */

static int default_qemu_set_fd_handler2(int fd,

                                        IOCanReadHandler *fd_read_poll,

                                        IOHandler *fd_read,

                                        IOHandler *fd_write,

                                        void *opaque)



{

    abort();

}
