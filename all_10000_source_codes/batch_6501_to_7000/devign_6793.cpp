/* 
 * Benchmark Sample ID : devign_6793
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=dc9121210eaf34e768901ffc6992dd13062c743a
 */

int do_migrate(Monitor *mon, const QDict *qdict, QObject **ret_data)
{
    MigrationState *s = NULL;
    const char *p;
    int detach = qdict_get_try_bool(qdict, "detach", 0);
    int blk = qdict_get_try_bool(qdict, "blk", 0);
    int inc = qdict_get_try_bool(qdict, "inc", 0);
    const char *uri = qdict_get_str(qdict, "uri");
    if (current_migration &&
        current_migration->get_status(current_migration) == MIG_STATE_ACTIVE) {
        monitor_printf(mon, "migration already in progress\n");
    if (strstart(uri, "tcp:", &p)) {
        s = tcp_start_outgoing_migration(mon, p, max_throttle, detach,
                                         blk, inc);
#if !defined(WIN32)
    } else if (strstart(uri, "exec:", &p)) {
        s = exec_start_outgoing_migration(mon, p, max_throttle, detach,
                                          blk, inc);
    } else if (strstart(uri, "unix:", &p)) {
        s = unix_start_outgoing_migration(mon, p, max_throttle, detach,
                                          blk, inc);
    } else if (strstart(uri, "fd:", &p)) {
        s = fd_start_outgoing_migration(mon, p, max_throttle, detach, 
                                        blk, inc);
#endif
    } else {
        monitor_printf(mon, "unknown migration protocol: %s\n", uri);
    if (s == NULL) {
        monitor_printf(mon, "migration failed\n");
    if (current_migration) {
        current_migration->release(current_migration);
    current_migration = s;
    return 0;
