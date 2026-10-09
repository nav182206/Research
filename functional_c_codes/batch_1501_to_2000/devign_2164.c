/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2164
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2174f12bdeb3974141784e14bbb7ad8c53178cd9
 */

static BlockAIOCB *raw_aio_writev(BlockDriverState *bs,

        int64_t sector_num, QEMUIOVector *qiov, int nb_sectors,

        BlockCompletionFunc *cb, void *opaque)

{

    return raw_aio_submit(bs, sector_num, qiov, nb_sectors,

                          cb, opaque, QEMU_AIO_WRITE);

}
