/* 
 * Benchmark Sample ID : devign_8998
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3482655bbc21d158ed0daaa294c890997238cc23
 */

void migration_incoming_state_destroy(void)
{
    struct MigrationIncomingState *mis = migration_incoming_get_current();
    qemu_event_destroy(&mis->main_thread_load_event);
