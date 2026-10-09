/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1467
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3403e5eb884f3a74c40fe7cccc103f848c040215
 */

static void parse_option_number(const char *name, const char *value,

                                uint64_t *ret, Error **errp)

{

    char *postfix;

    uint64_t number;



    number = strtoull(value, &postfix, 0);

    if (*postfix != '\0') {

        error_setg(errp, QERR_INVALID_PARAMETER_VALUE, name, "a number");

        return;

    }

    *ret = number;

}
