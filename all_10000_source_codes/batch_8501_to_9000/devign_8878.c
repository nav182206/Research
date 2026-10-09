/* 
 * Benchmark Sample ID : devign_8878
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

int migrate_use_xbzrle(void)

{

    MigrationState *s;



    s = migrate_get_current();



    return s->enabled_capabilities[MIGRATION_CAPABILITY_XBZRLE];

}
