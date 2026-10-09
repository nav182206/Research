/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2493
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d9b789745b88df367674e45c55df29e9c7de8d8a
 */

static bool qemu_gluster_test_seek(struct glfs_fd *fd)

{

    off_t ret, eof;



    eof = glfs_lseek(fd, 0, SEEK_END);

    if (eof < 0) {

        /* this should never occur */

        return false;

    }



    /* this should always fail with ENXIO if SEEK_DATA is supported */

    ret = glfs_lseek(fd, eof, SEEK_DATA);

    return (ret < 0) && (errno == ENXIO);

}
