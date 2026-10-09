/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1218
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=32bafa8fdd098d52fbf1102d5a5e48d29398c0aa
 */

static void block_dirty_bitmap_add_prepare(BlkActionState *common,

                                           Error **errp)

{

    Error *local_err = NULL;

    BlockDirtyBitmapAdd *action;

    BlockDirtyBitmapState *state = DO_UPCAST(BlockDirtyBitmapState,

                                             common, common);



    if (action_check_completion_mode(common, errp) < 0) {

        return;

    }



    action = common->action->u.block_dirty_bitmap_add;

    /* AIO context taken and released within qmp_block_dirty_bitmap_add */

    qmp_block_dirty_bitmap_add(action->node, action->name,

                               action->has_granularity, action->granularity,

                               &local_err);



    if (!local_err) {

        state->prepared = true;

    } else {

        error_propagate(errp, local_err);

    }

}
