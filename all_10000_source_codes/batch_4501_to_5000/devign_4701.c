/* 
 * Benchmark Sample ID : devign_4701
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=72cf2d4f0e181d0d3a3122e04129c58a95da713e
 */

static void ioreq_release(struct ioreq *ioreq)

{

    struct XenBlkDev *blkdev = ioreq->blkdev;



    LIST_REMOVE(ioreq, list);

    memset(ioreq, 0, sizeof(*ioreq));

    ioreq->blkdev = blkdev;

    LIST_INSERT_HEAD(&blkdev->freelist, ioreq, list);

    blkdev->requests_finished--;

}
