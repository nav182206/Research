/* 
 * Benchmark Sample ID : devign_4943
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0b8b8753e4d94901627b3e86431230f2319215c4
 */

static void qed_is_allocated_cb(void *opaque, int ret, uint64_t offset, size_t len)

{

    QEDIsAllocatedCB *cb = opaque;

    BDRVQEDState *s = cb->bs->opaque;

    *cb->pnum = len / BDRV_SECTOR_SIZE;

    switch (ret) {

    case QED_CLUSTER_FOUND:

        offset |= qed_offset_into_cluster(s, cb->pos);

        cb->status = BDRV_BLOCK_DATA | BDRV_BLOCK_OFFSET_VALID | offset;

        *cb->file = cb->bs->file->bs;

        break;

    case QED_CLUSTER_ZERO:

        cb->status = BDRV_BLOCK_ZERO;

        break;

    case QED_CLUSTER_L2:

    case QED_CLUSTER_L1:

        cb->status = 0;

        break;

    default:

        assert(ret < 0);

        cb->status = ret;

        break;

    }



    if (cb->co) {

        qemu_coroutine_enter(cb->co, NULL);

    }

}
