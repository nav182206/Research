/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1207
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=94171e119cb6f7bab2578896643b0daff1d9b184
 */

static int monitor_read_password(Monitor *mon, ReadLineFunc *readline_func,

                                 void *opaque)

{

    if (mon->rs) {

        readline_start(mon->rs, "Password: ", 1, readline_func, opaque);

        /* prompt is printed on return from the command handler */

        return 0;

    } else {

        monitor_printf(mon, "terminal does not support password prompting\n");

        return -ENOTTY;

    }

}
