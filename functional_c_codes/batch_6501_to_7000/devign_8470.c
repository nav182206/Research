/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8470
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=494a8ebe713055d3946183f4b395f85a18b43e9e
 */

static int proxy_open2(FsContext *fs_ctx, V9fsPath *dir_path, const char *name,

                       int flags, FsCred *credp, V9fsFidOpenState *fs)

{

    V9fsString fullname;



    v9fs_string_init(&fullname);

    v9fs_string_sprintf(&fullname, "%s/%s", dir_path->data, name);



    fs->fd = v9fs_request(fs_ctx->private, T_CREATE, NULL, "sdddd",

                          &fullname, flags, credp->fc_mode,

                          credp->fc_uid, credp->fc_gid);

    v9fs_string_free(&fullname);

    if (fs->fd < 0) {

        errno = -fs->fd;

        fs->fd = -1;

    }

    return fs->fd;

}
