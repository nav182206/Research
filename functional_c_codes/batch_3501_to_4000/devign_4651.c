/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4651
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9005c3b3efb7eb1b140d2ad0385efff6a3af59c4
 */

static ssize_t mp_dacl_listxattr(FsContext *ctx, const char *path,

                                 char *name, void *value, size_t osize)

{

    ssize_t len = sizeof(ACL_DEFAULT);



    if (!value) {

        return len;

    }



    if (osize < len) {

        errno = ERANGE;

        return -1;

    }



    /* len includes the trailing NUL */

    memcpy(value, ACL_ACCESS, len);

    return 0;

}
