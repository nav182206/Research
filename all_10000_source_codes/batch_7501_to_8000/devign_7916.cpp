/* 
 * Benchmark Sample ID : devign_7916
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2174f12bdeb3974141784e14bbb7ad8c53178cd9
 */

static BlockAIOCB *raw_aio_submit(BlockDriverState *bs,

        int64_t sector_num, QEMUIOVector *qiov, int nb_sectors,

        BlockCompletionFunc *cb, void *opaque, int type)

{

    BDRVRawState *s = bs->opaque;



    if (fd_open(bs) < 0)

        return NULL;



    /*

     * Check if the underlying device requires requests to be aligned,

     * and if the request we are trying to submit is aligned or not.

     * If this is the case tell the low-level driver that it needs

     * to copy the buffer.

     */

    if (s->needs_alignment) {

        if (!bdrv_qiov_is_aligned(bs, qiov)) {

            type |= QEMU_AIO_MISALIGNED;

#ifdef CONFIG_LINUX_AIO

        } else if (s->use_aio) {

            return laio_submit(bs, s->aio_ctx, s->fd, sector_num, qiov,

                               nb_sectors, cb, opaque, type);

#endif

        }

    }



    return paio_submit(bs, s->fd, sector_num, qiov, nb_sectors,

                       cb, opaque, type);

}
