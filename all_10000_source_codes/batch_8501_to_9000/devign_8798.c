/* 
 * Benchmark Sample ID : devign_8798
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6512a2a7106480c19183d6466a6845bc9bdf6ec0
 */

static BlockDriverAIOCB *dma_bdrv_io(

    BlockDriverState *bs, QEMUSGList *sg, uint64_t sector_num,

    BlockDriverCompletionFunc *cb, void *opaque,

    int is_write)

{

    DMABlockState *dbs = qemu_malloc(sizeof(*dbs));



    dbs->bs = bs;

    dbs->acb = qemu_aio_get(bs, cb, opaque);

    dbs->sg = sg;

    dbs->sector_num = sector_num;

    dbs->sg_cur_index = 0;

    dbs->sg_cur_byte = 0;

    dbs->is_write = is_write;

    dbs->bh = NULL;

    qemu_iovec_init(&dbs->iov, sg->nsg);

    dma_bdrv_cb(dbs, 0);

    return dbs->acb;

}
