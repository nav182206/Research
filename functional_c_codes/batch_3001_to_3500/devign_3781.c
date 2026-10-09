/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3781
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2d528d45ecf5ee3c1a566a9f3d664464925ef830
 */

static CharDriverState *qemu_chr_open_fd(int fd_in, int fd_out)

{

    CharDriverState *chr;

    FDCharDriver *s;



    chr = qemu_chr_alloc();

    s = g_malloc0(sizeof(FDCharDriver));

    s->fd_in = io_channel_from_fd(fd_in);

    s->fd_out = io_channel_from_fd(fd_out);

    qemu_set_nonblock(fd_out);

    s->chr = chr;

    chr->opaque = s;

    chr->chr_add_watch = fd_chr_add_watch;

    chr->chr_write = fd_chr_write;

    chr->chr_update_read_handler = fd_chr_update_read_handler;

    chr->chr_close = fd_chr_close;



    return chr;

}
