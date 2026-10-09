/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1392
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6a50636f35ba677c747f2f6127b0dba994b039ca
 */

static int do_qmp_capabilities(Monitor *mon, const QDict *params,

                               QObject **ret_data)

{

    /* Will setup QMP capabilities in the future */

    if (monitor_ctrl_mode(mon)) {

        mon->qmp.command_mode = 1;

    }



    return 0;

}
