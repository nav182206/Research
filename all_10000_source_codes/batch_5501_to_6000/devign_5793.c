/* 
 * Benchmark Sample ID : devign_5793
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b181e04777da67acbc7448f87e4ae9f1518e08b2
 */

static CharDriverState *qemu_chr_open_pp(QemuOpts *opts)

{

    const char *filename = qemu_opt_get(opts, "path");

    CharDriverState *chr;

    int fd;



    fd = open(filename, O_RDWR);

    if (fd < 0)

        return NULL;



    chr = g_malloc0(sizeof(CharDriverState));

    chr->opaque = (void *)(intptr_t)fd;

    chr->chr_write = null_chr_write;

    chr->chr_ioctl = pp_ioctl;

    return chr;

}
