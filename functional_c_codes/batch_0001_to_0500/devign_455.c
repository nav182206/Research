/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_455
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1f001dc7bc9e435bf231a5b0edcad1c7c2bd6214
 */

static int default_monitor_get_fd(Monitor *mon, const char *name, Error **errp)

{

    error_setg(errp, "only QEMU supports file descriptor passing");

    return -1;

}
