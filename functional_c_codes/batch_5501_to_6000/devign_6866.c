/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6866
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9c6b899f7a46893ab3b671e341a2234e9c0c060e
 */

static int local_name_to_path(FsContext *ctx, V9fsPath *dir_path,

                              const char *name, V9fsPath *target)

{

    if (dir_path) {

        v9fs_path_sprintf(target, "%s/%s", dir_path->data, name);

    } else {

        v9fs_path_sprintf(target, "%s", name);

    }

    return 0;

}
