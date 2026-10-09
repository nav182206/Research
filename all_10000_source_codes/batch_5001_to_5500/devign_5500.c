/* 
 * Benchmark Sample ID : devign_5500
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=fc22118d9bb56ec71655b936a29513c140e6c289
 */

static const char *rpath(FsContext *ctx, const char *path)

{

    /* FIXME: so wrong... */

    static char buffer[4096];

    snprintf(buffer, sizeof(buffer), "%s/%s", ctx->fs_root, path);

    return buffer;

}
