/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_435
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5f758366c0710d23e43f4d0f83816b98616a13d0
 */

static CharDriverState *qmp_chardev_open_parallel(ChardevHostdev *parallel,

                                                  Error **errp)

{

#ifdef HAVE_CHARDEV_PARPORT

    int fd;



    fd = qmp_chardev_open_file_source(parallel->device, O_RDWR, errp);

    if (error_is_set(errp)) {

        return NULL;

    }

    return qemu_chr_open_pp_fd(fd);

#else

    error_setg(errp, "character device backend type 'parallel' not supported");

    return NULL;

#endif

}
