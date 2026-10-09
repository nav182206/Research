/* 
 * Benchmark Sample ID : devign_3031
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0b8b8753e4d94901627b3e86431230f2319215c4
 */

static int qcow_write(BlockDriverState *bs, int64_t sector_num,

                      const uint8_t *buf, int nb_sectors)

{

    Coroutine *co;

    AioContext *aio_context = bdrv_get_aio_context(bs);

    QcowWriteCo data = {

        .bs         = bs,

        .sector_num = sector_num,

        .buf        = buf,

        .nb_sectors = nb_sectors,

        .ret        = -EINPROGRESS,

    };

    co = qemu_coroutine_create(qcow_write_co_entry);

    qemu_coroutine_enter(co, &data);

    while (data.ret == -EINPROGRESS) {

        aio_poll(aio_context, true);

    }

    return data.ret;

}
