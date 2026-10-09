/* 
 * Benchmark Sample ID : devign_6959
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=72cf2d4f0e181d0d3a3122e04129c58a95da713e
 */

qemu_acl *qemu_acl_init(const char *aclname)

{

    qemu_acl *acl;



    acl = qemu_acl_find(aclname);

    if (acl)

        return acl;



    acl = qemu_malloc(sizeof(*acl));

    acl->aclname = qemu_strdup(aclname);

    /* Deny by default, so there is no window of "open

     * access" between QEMU starting, and the user setting

     * up ACLs in the monitor */

    acl->defaultDeny = 1;



    acl->nentries = 0;

    TAILQ_INIT(&acl->entries);



    acls = qemu_realloc(acls, sizeof(*acls) * (nacls +1));

    acls[nacls] = acl;

    nacls++;



    return acl;

}
