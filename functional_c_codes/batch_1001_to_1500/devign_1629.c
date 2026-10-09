/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1629
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=02cb7f3a256517cbf3136caff2863fbafc57b540
 */

int v9fs_co_mkdir(V9fsState *s, char *name, mode_t mode, uid_t uid, gid_t gid)

{

    int err;

    FsCred cred;



    cred_init(&cred);

    cred.fc_mode = mode;

    cred.fc_uid = uid;

    cred.fc_gid = gid;

    v9fs_co_run_in_worker(

        {

            err = s->ops->mkdir(&s->ctx, name, &cred);

            if (err < 0) {

                err = -errno;

            }

        });

    return err;

}
