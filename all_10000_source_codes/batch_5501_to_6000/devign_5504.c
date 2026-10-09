/* 
 * Benchmark Sample ID : devign_5504
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4baef2679e029c76707be1e2ed54bf3dd21693fe
 */

int qemu_strtol(const char *nptr, const char **endptr, int base,

                long *result)

{

    char *ep;

    int err = 0;

    if (!nptr) {

        if (endptr) {

            *endptr = nptr;

        }

        err = -EINVAL;

    } else {

        errno = 0;

        *result = strtol(nptr, &ep, base);

        err = check_strtox_error(nptr, ep, endptr, errno);

    }

    return err;

}
