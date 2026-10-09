/* 
 * Benchmark Sample ID : devign_8774
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bcf5d19c59a527c91bc29704f3e4956119c050cf
 */

int monitor_read_password(Monitor *mon, ReadLineFunc *readline_func,

                          void *opaque)

{

    if (monitor_ctrl_mode(mon)) {

        qerror_report(QERR_MISSING_PARAMETER, "password");

        return -EINVAL;

    } else if (mon->rs) {

        readline_start(mon->rs, "Password: ", 1, readline_func, opaque);

        /* prompt is printed on return from the command handler */

        return 0;

    } else {

        monitor_printf(mon, "terminal does not support password prompting\n");

        return -ENOTTY;

    }

}
