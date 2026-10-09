/* 
 * Benchmark Sample ID : devign_1307
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ef5a788527b2038d742b057a415ab4d0e735e98f
 */

static int64_t cvtnum(const char *s)

{

    char *end;

    return qemu_strtosz_suffix(s, &end, QEMU_STRTOSZ_DEFSUFFIX_B);

}
