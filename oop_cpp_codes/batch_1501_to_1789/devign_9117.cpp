/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_9117
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e92f0e1910f0655a0edd8d87c5a7262d36517a89
 */

bdrv_rw_vmstate(BlockDriverState *bs, QEMUIOVector *qiov, int64_t pos,

                bool is_read)

{

    if (qemu_in_coroutine()) {

        return bdrv_co_rw_vmstate(bs, qiov, pos, is_read);

    } else {

        BdrvVmstateCo data = {

            .bs         = bs,

            .qiov       = qiov,

            .pos        = pos,

            .is_read    = is_read,

            .ret        = -EINPROGRESS,

        };

        Coroutine *co = qemu_coroutine_create(bdrv_co_rw_vmstate_entry, &data);



        qemu_coroutine_enter(co);

        while (data.ret == -EINPROGRESS) {

            aio_poll(bdrv_get_aio_context(bs), true);

        }

        return data.ret;

    }

}
