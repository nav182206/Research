/* 
 * Benchmark Sample ID : devign_5060
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=02cb7f3a256517cbf3136caff2863fbafc57b540
 */

int v9fs_co_mknod(V9fsState *s, V9fsString *path, uid_t uid,

                  gid_t gid, dev_t dev, mode_t mode)

{

    int err;

    FsCred cred;



    cred_init(&cred);

    cred.fc_uid  = uid;

    cred.fc_gid  = gid;

    cred.fc_mode = mode;

    cred.fc_rdev = dev;

    v9fs_co_run_in_worker(

        {

            err = s->ops->mknod(&s->ctx, path->data, &cred);

            if (err < 0) {

                err = -errno;

            }

        });

    return err;

}
