/* 
 * Benchmark Sample ID : devign_6901
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=65207c59d99f2260c5f1d3b9c491146616a522aa
 */

static int qmp_async_cmd_handler(Monitor *mon, const mon_cmd_t *cmd,

                                 const QDict *params)

{

    return cmd->mhandler.cmd_async(mon, params, qmp_monitor_complete, mon);

}
