/* 
 * Benchmark Sample ID : devign_7278
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4baef2679e029c76707be1e2ed54bf3dd21693fe
 */

static int check_strtox_error(const char *nptr, char *ep,

                              const char **endptr, int libc_errno)

{

    if (libc_errno == 0 && ep == nptr) {

        libc_errno = EINVAL;

    }

    if (!endptr && *ep) {

        return -EINVAL;

    }

    if (endptr) {

        *endptr = ep;

    }

    return -libc_errno;

}
