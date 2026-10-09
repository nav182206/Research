/* 
 * Benchmark Sample ID : devign_8847
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4295e15aa730a95003a3639d6dad2eb1e65a59e2
 */

static void migration_state_notifier(Notifier *notifier, void *data)

{

    MigrationState *s = data;



    if (migration_is_active(s)) {

#ifdef SPICE_INTERFACE_MIGRATION

        spice_server_migrate_start(spice_server);

#endif

    } else if (migration_has_finished(s)) {

#if SPICE_SERVER_VERSION >= 0x000701 /* 0.7.1 */

#ifndef SPICE_INTERFACE_MIGRATION

        spice_server_migrate_switch(spice_server);

#else

        spice_server_migrate_end(spice_server, true);

    } else if (migration_has_failed(s)) {

        spice_server_migrate_end(spice_server, false);

#endif

#endif

    }

}
