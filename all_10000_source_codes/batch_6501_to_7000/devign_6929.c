/* 
 * Benchmark Sample ID : devign_6929
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ae50212ff717f3d295ebff352eb7d6cc08332b7e
 */

static void handle_hmp_command(Monitor *mon, const char *cmdline)

{

    QDict *qdict;

    const mon_cmd_t *cmd;



    qdict = qdict_new();



    cmd = monitor_parse_command(mon, cmdline, 0, mon->cmd_table, qdict);

    if (cmd) {

        cmd->mhandler.cmd(mon, qdict);

    }



    QDECREF(qdict);

}
