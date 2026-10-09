/* 
 * Benchmark Sample ID : devign_6942
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3718d8ab65f68de2acccbe6a315907805f54e3cc
 */

static void blk_mig_cleanup(void)

{

    BlkMigDevState *bmds;

    BlkMigBlock *blk;



    bdrv_drain_all();



    unset_dirty_tracking();



    blk_mig_lock();

    while ((bmds = QSIMPLEQ_FIRST(&block_mig_state.bmds_list)) != NULL) {

        QSIMPLEQ_REMOVE_HEAD(&block_mig_state.bmds_list, entry);

        bdrv_set_in_use(bmds->bs, 0);

        bdrv_unref(bmds->bs);

        g_free(bmds->aio_bitmap);

        g_free(bmds);

    }



    while ((blk = QSIMPLEQ_FIRST(&block_mig_state.blk_list)) != NULL) {

        QSIMPLEQ_REMOVE_HEAD(&block_mig_state.blk_list, entry);

        g_free(blk->buf);

        g_free(blk);

    }

    blk_mig_unlock();

}
