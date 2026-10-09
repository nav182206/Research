/* 
 * Benchmark Sample ID : devign_7784
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=72cf2d4f0e181d0d3a3122e04129c58a95da713e
 */

void qemu_acl_reset(qemu_acl *acl)

{

    qemu_acl_entry *entry;



    /* Put back to deny by default, so there is no window

     * of "open access" while the user re-initializes the

     * access control list */

    acl->defaultDeny = 1;

    TAILQ_FOREACH(entry, &acl->entries, next) {

        TAILQ_REMOVE(&acl->entries, entry, next);

        free(entry->match);

        free(entry);

    }

    acl->nentries = 0;

}
