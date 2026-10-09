/* 
 * Benchmark Sample ID : devign_3245
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e7cf59e84767e30b507b6bd7c1347072ec12b636
 */

void error_set_win32(Error **errp, int win32_err, ErrorClass err_class,

                     const char *fmt, ...)

{

    va_list ap;

    char *msg1, *msg2;



    if (errp == NULL) {

        return;

    }



    va_start(ap, fmt);

    error_setv(errp, err_class, fmt, ap);

    va_end(ap);



    if (win32_err != 0) {

        msg1 = (*errp)->msg;

        msg2 = g_win32_error_message(win32_err);

        (*errp)->msg = g_strdup_printf("%s: %s (error: %x)", msg1, msg2,

                                       (unsigned)win32_err);

        g_free(msg2);

        g_free(msg1);

    }

}
