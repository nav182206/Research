/* 
 * Benchmark Sample ID : devign_5112
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e92f0e1910f0655a0edd8d87c5a7262d36517a89
 */

int bdrv_flush(BlockDriverState *bs)

{

    Coroutine *co;

    FlushCo flush_co = {

        .bs = bs,

        .ret = NOT_DONE,

    };



    if (qemu_in_coroutine()) {

        /* Fast-path if already in coroutine context */

        bdrv_flush_co_entry(&flush_co);

    } else {

        co = qemu_coroutine_create(bdrv_flush_co_entry, &flush_co);

        qemu_coroutine_enter(co);

        BDRV_POLL_WHILE(bs, flush_co.ret == NOT_DONE);

    }



    return flush_co.ret;

}
