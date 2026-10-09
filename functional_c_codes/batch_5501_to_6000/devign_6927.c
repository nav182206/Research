/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6927
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=250561e1aebf69e911992da9017322df7aeaa564
 */

bool migration_is_blocked(Error **errp)

{

    if (qemu_savevm_state_blocked(errp)) {

        return true;

    }



    if (migration_blockers) {

        *errp = error_copy(migration_blockers->data);

        return true;

    }



    return false;

}
