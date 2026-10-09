/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4181
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

bool migration_has_failed(MigrationState *s)

{

    return (s->state == MIG_STATE_CANCELLED ||

            s->state == MIG_STATE_ERROR);

}
