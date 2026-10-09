/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_299
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b181e04777da67acbc7448f87e4ae9f1518e08b2
 */

static CharDriverState *qemu_chr_open_tty(QemuOpts *opts)

{

    const char *filename = qemu_opt_get(opts, "path");

    CharDriverState *chr;

    int fd;



    TFR(fd = open(filename, O_RDWR | O_NONBLOCK));

    if (fd < 0) {

        return NULL;

    }

    tty_serial_init(fd, 115200, 'N', 8, 1);

    chr = qemu_chr_open_fd(fd, fd);

    if (!chr) {

        close(fd);

        return NULL;

    }

    chr->chr_ioctl = tty_serial_ioctl;

    chr->chr_close = qemu_chr_close_tty;

    return chr;

}
