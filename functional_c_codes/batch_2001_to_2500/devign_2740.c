/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2740
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=717adf960933da0650d995f050d457063d591914
 */

static int check_strtox_error(const char *p, char *endptr, const char **next,

                              int err)

{

    if (err == 0 && endptr == p) {

        err = EINVAL;

    }

    if (!next && *endptr) {

        return -EINVAL;

    }

    if (next) {

        *next = endptr;

    }

    return -err;

}
