/* 
 * Benchmark Sample ID : devign_396
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5f8b6491f20732e0a31e64bbf75b62def579e044
 */

static void coroutine_fn wait_for_overlapping_requests(BlockDriverState *bs,
        int64_t sector_num, int nb_sectors)
{
    BdrvTrackedRequest *req;
    int64_t cluster_sector_num;
    int cluster_nb_sectors;
    bool retry;
    /* If we touch the same cluster it counts as an overlap.  This guarantees
     * that allocating writes will be serialized and not race with each other
     * for the same cluster.  For example, in copy-on-read it ensures that the
     * CoR read and write operations are atomic and guest writes cannot
     * interleave between them.
    round_to_clusters(bs, sector_num, nb_sectors,
                      &cluster_sector_num, &cluster_nb_sectors);
    do {
        retry = false;
        QLIST_FOREACH(req, &bs->tracked_requests, list) {
            if (tracked_request_overlaps(req, cluster_sector_num,
                                         cluster_nb_sectors)) {
                qemu_co_queue_wait(&req->wait_queue);
                retry = true;
                break;
            }
        }
    } while (retry);
}
