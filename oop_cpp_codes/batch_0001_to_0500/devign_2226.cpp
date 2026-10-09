/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_2226
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a367467995d0528fe591d87ca2e437c7b7d7951b
 */

static int do_co_pwrite_zeroes(BlockBackend *blk, int64_t offset,

                               int64_t count, int flags, int64_t *total)

{

    Coroutine *co;

    CoWriteZeroes data = {

        .blk    = blk,

        .offset = offset,

        .count  = count,

        .total  = total,

        .flags  = flags,

        .done   = false,

    };



    if (count >> BDRV_SECTOR_BITS > INT_MAX) {

        return -ERANGE;

    }



    co = qemu_coroutine_create(co_pwrite_zeroes_entry, &data);

    qemu_coroutine_enter(co);

    while (!data.done) {

        aio_poll(blk_get_aio_context(blk), true);

    }

    if (data.ret < 0) {

        return data.ret;

    } else {

        return 1;

    }

}
