/* 
 * Benchmark Sample ID : devign_7429
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

void migrate_add_blocker(Error *reason)

{

    migration_blockers = g_slist_prepend(migration_blockers, reason);

}
