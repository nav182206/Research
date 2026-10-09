/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_335
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2119882c7eb7e2c612b24fc0c8d86f5887d6f1c3
 */

static void unset_dirty_tracking(void)

{

    BlkMigDevState *bmds;



    QSIMPLEQ_FOREACH(bmds, &block_mig_state.bmds_list, entry) {

        aio_context_acquire(blk_get_aio_context(bmds->blk));

        bdrv_release_dirty_bitmap(blk_bs(bmds->blk), bmds->dirty_bitmap);

        aio_context_release(blk_get_aio_context(bmds->blk));

    }

}
