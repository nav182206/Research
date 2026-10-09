/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9475
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=536eeea86905237953a7c05c2fa2a3d1f3cba328
 */

void error_vprepend(Error **errp, const char *fmt, va_list ap)

{

    GString *newmsg;



    if (!errp) {

        return;

    }



    newmsg = g_string_new(NULL);

    g_string_vprintf(newmsg, fmt, ap);

    g_string_append(newmsg, (*errp)->msg);


    (*errp)->msg = g_string_free(newmsg, 0);

}
