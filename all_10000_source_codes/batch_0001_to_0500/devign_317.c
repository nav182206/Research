/* 
 * Benchmark Sample ID : devign_317
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e17408283562be359f16a7e12ddfee7509d6fe11
 */

static int floppy_probe_device(const char *filename)

{

    int fd, ret;

    int prio = 0;

    struct floppy_struct fdparam;

    struct stat st;



    if (strstart(filename, "/dev/fd", NULL))

        prio = 50;



    fd = open(filename, O_RDONLY | O_NONBLOCK);

    if (fd < 0) {

        goto out;

    }

    ret = fstat(fd, &st);

    if (ret == -1 || !S_ISBLK(st.st_mode)) {

        goto outc;

    }



    /* Attempt to detect via a floppy specific ioctl */

    ret = ioctl(fd, FDGETPRM, &fdparam);

    if (ret >= 0)

        prio = 100;



outc:

    close(fd);

out:

    return prio;

}
