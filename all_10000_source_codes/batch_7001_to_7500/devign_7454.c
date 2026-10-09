/* 
 * Benchmark Sample ID : devign_7454
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d0d7708ba29cbcc343364a46bff981e0ff88366f
 */

static CharDriverState *qemu_chr_open_tty_fd(int fd)

{

    CharDriverState *chr;



    tty_serial_init(fd, 115200, 'N', 8, 1);

    chr = qemu_chr_open_fd(fd, fd);

    chr->chr_ioctl = tty_serial_ioctl;

    chr->chr_close = qemu_chr_close_tty;

    return chr;

}
