/* 
 * Benchmark Sample ID : devign_6426
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d157ed5f7235f3d2d5596a514ad7507b18e24b88
 */

blkdebug_co_pwritev(BlockDriverState *bs, uint64_t offset, uint64_t bytes,

                    QEMUIOVector *qiov, int flags)

{

    BDRVBlkdebugState *s = bs->opaque;

    BlkdebugRule *rule = NULL;



    /* Sanity check block layer guarantees */

    assert(QEMU_IS_ALIGNED(offset, bs->bl.request_alignment));

    assert(QEMU_IS_ALIGNED(bytes, bs->bl.request_alignment));

    if (bs->bl.max_transfer) {

        assert(bytes <= bs->bl.max_transfer);

    }



    QSIMPLEQ_FOREACH(rule, &s->active_rules, active_next) {

        uint64_t inject_offset = rule->options.inject.offset;



        if (inject_offset == -1 ||

            (inject_offset >= offset && inject_offset < offset + bytes))

        {

            break;

        }

    }



    if (rule && rule->options.inject.error) {

        return inject_error(bs, rule);

    }



    return bdrv_co_pwritev(bs->file, offset, bytes, qiov, flags);

}
