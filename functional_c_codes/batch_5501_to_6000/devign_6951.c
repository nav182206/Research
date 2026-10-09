/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6951
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=621ff94d5074d88253a5818c6b9c4db718fbfc65
 */

int bdrv_create_file(const char *filename, QemuOpts *opts, Error **errp)

{

    BlockDriver *drv;

    Error *local_err = NULL;

    int ret;



    drv = bdrv_find_protocol(filename, true, errp);

    if (drv == NULL) {

        return -ENOENT;

    }



    ret = bdrv_create(drv, filename, opts, &local_err);

    if (local_err) {

        error_propagate(errp, local_err);

    }

    return ret;

}
