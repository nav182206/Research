/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_668
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1e9b65bb1bad51735cab6c861c29b592dccabf0e
 */

void error_setg_errno(Error **errp, int os_errno, const char *fmt, ...)

{

    va_list ap;

    char *msg;

    int saved_errno = errno;



    if (errp == NULL) {

        return;

    }



    va_start(ap, fmt);

    error_setv(errp, ERROR_CLASS_GENERIC_ERROR, fmt, ap);

    va_end(ap);



    if (os_errno != 0) {

        msg = (*errp)->msg;

        (*errp)->msg = g_strdup_printf("%s: %s", msg, strerror(os_errno));

        g_free(msg);

    }



    errno = saved_errno;

}
