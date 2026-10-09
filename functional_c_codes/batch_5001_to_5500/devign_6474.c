/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6474
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6b19a7d91c8de9904c67b87203a46e55db4181ab
 */

static bool migration_object_check(MigrationState *ms, Error **errp)

{

    if (!migrate_params_check(&ms->parameters, errp)) {

        return false;

    }



    return true;

}
