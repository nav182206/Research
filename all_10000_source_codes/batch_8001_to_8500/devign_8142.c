/* 
 * Benchmark Sample ID : devign_8142
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b436982f04fb33bb29fcdea190bd1fdc97dc65ef
 */

static void mirror_write_complete(void *opaque, int ret)

{

    MirrorOp *op = opaque;

    MirrorBlockJob *s = op->s;



    aio_context_acquire(blk_get_aio_context(s->common.blk));

    if (ret < 0) {

        BlockErrorAction action;



        bdrv_set_dirty_bitmap(s->dirty_bitmap, op->sector_num, op->nb_sectors);

        action = mirror_error_action(s, false, -ret);

        if (action == BLOCK_ERROR_ACTION_REPORT && s->ret >= 0) {

            s->ret = ret;

        }

    }

    mirror_iteration_done(op, ret);

    aio_context_release(blk_get_aio_context(s->common.blk));

}
