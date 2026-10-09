/* 
 * Benchmark Sample ID : devign_2463
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c23c15d30b901bb447cdcada96cae64c0046d146
 */

int qemu_acl_remove(qemu_acl *acl,

                    const char *match)

{

    qemu_acl_entry *entry;

    int i = 0;



    QTAILQ_FOREACH(entry, &acl->entries, next) {

        i++;

        if (strcmp(entry->match, match) == 0) {

            QTAILQ_REMOVE(&acl->entries, entry, next);




            return i;

        }

    }

    return -1;

}
