/* 
 * Benchmark Sample ID : devign_8467
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=81ffbf5ab1458e357a761f1272105a55829b351e
 */

static bool local_is_mapped_file_metadata(FsContext *fs_ctx, const char *name)

{

    return !strcmp(name, VIRTFS_META_DIR);

}
