/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3986
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3dc6f8693694a649a9c83f1e2746565b47683923
 */

static void unsafe_flush_warning(BDRVSSHState *s, const char *what)

{

    if (!s->unsafe_flush_warning) {

        error_report("warning: ssh server %s does not support fsync",

                     s->inet->host);

        if (what) {

            error_report("to support fsync, you need %s", what);

        }

        s->unsafe_flush_warning = true;

    }

}
