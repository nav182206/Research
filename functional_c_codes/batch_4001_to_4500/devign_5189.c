/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5189
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ca99993adc9205c905dba5dc1bb819959ada7200
 */

void qmp_migrate(const char *uri, bool has_blk, bool blk,
                 bool has_inc, bool inc, bool has_detach, bool detach,
                 Error **errp)
{
    Error *local_err = NULL;
    MigrationState *s = migrate_get_current();
    MigrationParams params;
    const char *p;
    params.blk = has_blk && blk;
    params.shared = has_inc && inc;
    if (s->state == MIG_STATE_ACTIVE || s->state == MIG_STATE_SETUP ||
        s->state == MIG_STATE_CANCELLING) {
        error_set(errp, QERR_MIGRATION_ACTIVE);
    if (qemu_savevm_state_blocked(errp)) {
    if (migration_blockers) {
        *errp = error_copy(migration_blockers->data);
    s = migrate_init(&params);
    if (strstart(uri, "tcp:", &p)) {
        tcp_start_outgoing_migration(s, p, &local_err);
#ifdef CONFIG_RDMA
    } else if (strstart(uri, "rdma:", &p)) {
        rdma_start_outgoing_migration(s, p, &local_err);
#endif
#if !defined(WIN32)
    } else if (strstart(uri, "exec:", &p)) {
        exec_start_outgoing_migration(s, p, &local_err);
    } else if (strstart(uri, "unix:", &p)) {
        unix_start_outgoing_migration(s, p, &local_err);
    } else if (strstart(uri, "fd:", &p)) {
        fd_start_outgoing_migration(s, p, &local_err);
#endif
    } else {
        error_set(errp, QERR_INVALID_PARAMETER_VALUE, "uri", "a valid migration protocol");
        s->state = MIG_STATE_ERROR;
    if (local_err) {
        migrate_fd_error(s);
        error_propagate(errp, local_err);
