/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_528
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=75cdcd1553e74b5edc58aed23e3b2da8dabb1876
 */

void parse_option_size(const char *name, const char *value,

                       uint64_t *ret, Error **errp)

{

    char *postfix;

    double sizef;



    sizef = strtod(value, &postfix);

    if (sizef < 0 || sizef > UINT64_MAX) {

        error_setg(errp, QERR_INVALID_PARAMETER_VALUE, name,

                   "a non-negative number below 2^64");

        return;

    }

    switch (*postfix) {

    case 'T':

        sizef *= 1024;

        /* fall through */

    case 'G':

        sizef *= 1024;

        /* fall through */

    case 'M':

        sizef *= 1024;

        /* fall through */

    case 'K':

    case 'k':

        sizef *= 1024;

        /* fall through */

    case 'b':

    case '\0':

        *ret = (uint64_t) sizef;

        break;

    default:

        error_setg(errp, QERR_INVALID_PARAMETER_VALUE, name, "a size");

        error_append_hint(errp, "You may use k, M, G or T suffixes for "

                          "kilobytes, megabytes, gigabytes and terabytes.\n");

        return;

    }

}
