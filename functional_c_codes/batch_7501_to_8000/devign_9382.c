/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9382
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0e8d2b5575938b8876a3c4bb66ee13c5d306fb6d
 */

static int do_quit(Monitor *mon, const QDict *qdict, QObject **ret_data)

{

    exit(0);

    return 0;

}
