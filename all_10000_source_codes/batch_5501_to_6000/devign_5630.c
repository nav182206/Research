/* 
 * Benchmark Sample ID : devign_5630
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

static void migrate_set_state(MigrationState *s, int old_state, int new_state)

{

    if (atomic_cmpxchg(&s->state, old_state, new_state) == new_state) {

        trace_migrate_set_state(new_state);

    }

}
