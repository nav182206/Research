/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2733
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f143efa60c44c65c22aeeb04217f3501e3d04b22
 */

static int local_rename(FsContext *ctx, const char *oldpath,

                        const char *newpath)

{

    char *tmp;

    int err;



    tmp = qemu_strdup(rpath(ctx, oldpath));

    if (tmp == NULL) {

        return -1;

    }



    err = rename(tmp, rpath(ctx, newpath));

    if (err == -1) {

        int serrno = errno;

        qemu_free(tmp);

        errno = serrno;

    } else {

        qemu_free(tmp);

    }



    return err;



}
