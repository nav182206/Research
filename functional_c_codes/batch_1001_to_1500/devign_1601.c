/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1601
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=feeee5aca765606818e00f5a19d19f141f4ae365
 */

static BlockDriverState *get_bs_snapshots(void)

{

    BlockDriverState *bs;

    DriveInfo *dinfo;



    if (bs_snapshots)

        return bs_snapshots;

    QTAILQ_FOREACH(dinfo, &drives, next) {

        bs = dinfo->bdrv;

        if (bdrv_can_snapshot(bs))

            goto ok;

    }

    return NULL;

 ok:

    bs_snapshots = bs;

    return bs;

}
