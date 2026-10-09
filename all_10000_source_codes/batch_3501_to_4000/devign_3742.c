/* 
 * Benchmark Sample ID : devign_3742
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=31e51d1c15b35dc98b88a301812914b70a2b55dc
 */

static int local_statfs(FsContext *s, V9fsPath *fs_path, struct statfs *stbuf)

{

    char *buffer;

    int ret;

    char *path = fs_path->data;



    buffer = rpath(s, path);

    ret = statfs(buffer, stbuf);

    g_free(buffer);

    return ret;

}
