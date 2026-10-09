/* 
 * Benchmark Sample ID : devign_1538
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=47d4be12c3997343e436c6cca89aefbbbeb70863
 */

int qemu_strtol(const char *nptr, const char **endptr, int base,

                long *result)

{

    char *p;

    int err = 0;

    if (!nptr) {

        if (endptr) {

            *endptr = nptr;

        }

        err = -EINVAL;

    } else {

        errno = 0;

        *result = strtol(nptr, &p, base);

        err = check_strtox_error(endptr, p, errno);

    }

    return err;

}
