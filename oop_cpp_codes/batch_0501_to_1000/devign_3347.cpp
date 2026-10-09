/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_3347
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=494a8ebe713055d3946183f4b395f85a18b43e9e
 */

static int proxy_ioc_getversion(FsContext *fs_ctx, V9fsPath *path,

                                mode_t st_mode, uint64_t *st_gen)

{

    int err;



    /* Do not try to open special files like device nodes, fifos etc

     * we can get fd for regular files and directories only

     */

    if (!S_ISREG(st_mode) && !S_ISDIR(st_mode)) {

        errno = ENOTTY;

        return -1;

    }

    err = v9fs_request(fs_ctx->private, T_GETVERSION, st_gen, "s", path);

    if (err < 0) {

        errno = -err;

        err = -1;

    }

    return err;

}
