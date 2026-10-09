/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6085
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4be746345f13e99e468c60acbd3a355e8183e3ce
 */

static void blk_disconnect(struct XenDevice *xendev)

{

    struct XenBlkDev *blkdev = container_of(xendev, struct XenBlkDev, xendev);



    if (blkdev->bs) {

        bdrv_detach_dev(blkdev->bs, blkdev);

        if (!blkdev->dinfo) {

            blk_unref(blk_by_name(blkdev->dev));

        }

        blkdev->bs = NULL;

    }

    xen_be_unbind_evtchn(&blkdev->xendev);



    if (blkdev->sring) {

        xc_gnttab_munmap(blkdev->xendev.gnttabdev, blkdev->sring, 1);

        blkdev->cnt_map--;

        blkdev->sring = NULL;

    }

}
