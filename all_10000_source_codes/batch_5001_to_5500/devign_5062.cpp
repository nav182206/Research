/* 
 * Benchmark Sample ID : devign_5062
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=88b062c2036cfd05b5111147736a08ba05ea05a9
 */

int64_t bdrv_get_block_status_above(BlockDriverState *bs,

                                    BlockDriverState *base,

                                    int64_t sector_num,

                                    int nb_sectors, int *pnum,

                                    BlockDriverState **file)

{

    Coroutine *co;

    BdrvCoGetBlockStatusData data = {

        .bs = bs,

        .base = base,

        .file = file,

        .sector_num = sector_num,

        .nb_sectors = nb_sectors,

        .pnum = pnum,

        .done = false,

    };



    if (qemu_in_coroutine()) {

        /* Fast-path if already in coroutine context */

        bdrv_get_block_status_above_co_entry(&data);

    } else {

        AioContext *aio_context = bdrv_get_aio_context(bs);



        co = qemu_coroutine_create(bdrv_get_block_status_above_co_entry,

                                   &data);

        qemu_coroutine_enter(co);

        while (!data.done) {

            aio_poll(aio_context, true);

        }

    }

    return data.ret;

}
