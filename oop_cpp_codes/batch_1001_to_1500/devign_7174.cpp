/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_7174
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2572b37a4751cc967582d7d04f21d9bf97187ae5
 */

int64_t bdrv_get_block_status(BlockDriverState *bs, int64_t sector_num,

                              int nb_sectors, int *pnum)

{

    Coroutine *co;

    BdrvCoGetBlockStatusData data = {

        .bs = bs,

        .sector_num = sector_num,

        .nb_sectors = nb_sectors,

        .pnum = pnum,

        .done = false,

    };



    if (qemu_in_coroutine()) {

        /* Fast-path if already in coroutine context */

        bdrv_get_block_status_co_entry(&data);

    } else {

        co = qemu_coroutine_create(bdrv_get_block_status_co_entry);

        qemu_coroutine_enter(co, &data);

        while (!data.done) {

            qemu_aio_wait();

        }

    }

    return data.ret;

}
