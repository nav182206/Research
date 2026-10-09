/* 
 * Benchmark Sample ID : devign_2424
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=44b6789299a8acca3f25331bc411055cafc7bb06
 */

static BlockAIOCB *blkverify_aio_writev(BlockDriverState *bs,

        int64_t sector_num, QEMUIOVector *qiov, int nb_sectors,

        BlockCompletionFunc *cb, void *opaque)

{

    BDRVBlkverifyState *s = bs->opaque;

    BlkverifyAIOCB *acb = blkverify_aio_get(bs, true, sector_num, qiov,

                                            nb_sectors, cb, opaque);



    bdrv_aio_writev(s->test_file, sector_num, qiov, nb_sectors,

                    blkverify_aio_cb, acb);

    bdrv_aio_writev(bs->file, sector_num, qiov, nb_sectors,

                    blkverify_aio_cb, acb);

    return &acb->common;

}
