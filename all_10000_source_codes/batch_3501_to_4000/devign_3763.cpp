/* 
 * Benchmark Sample ID : devign_3763
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=72cf2d4f0e181d0d3a3122e04129c58a95da713e
 */

void destroy_bdrvs(dev_match_fn *match_fn, void *arg)

{

    DriveInfo *dinfo;

    struct BlockDriverState *bs;



    TAILQ_FOREACH(dinfo, &drives, next) {

        bs = dinfo->bdrv;

        if (bs) {

            if (bs->private && match_fn(bs->private, arg)) {

                drive_uninit(bs);

                bdrv_delete(bs);

            }

        }

    }

}
