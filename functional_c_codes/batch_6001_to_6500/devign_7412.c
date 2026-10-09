/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7412
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=cde0fc7544ca590c83f349d4dcccf375d55d6042
 */

static void monitor_print_error(Monitor *mon)

{

    qerror_print(mon->error);

    QDECREF(mon->error);

    mon->error = NULL;

}
