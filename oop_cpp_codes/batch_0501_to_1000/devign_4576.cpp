/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_4576
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0db6e54a8a2c6e16780356422da671b71f862341
 */

static int set_dirty_tracking(void)

{

    BlkMigDevState *bmds;

    int ret;



    QSIMPLEQ_FOREACH(bmds, &block_mig_state.bmds_list, entry) {

        bmds->dirty_bitmap = bdrv_create_dirty_bitmap(bmds->bs, BLOCK_SIZE,

                                                      NULL);

        if (!bmds->dirty_bitmap) {

            ret = -errno;

            goto fail;

        }

    }

    return 0;



fail:

    QSIMPLEQ_FOREACH(bmds, &block_mig_state.bmds_list, entry) {

        if (bmds->dirty_bitmap) {

            bdrv_release_dirty_bitmap(bmds->bs, bmds->dirty_bitmap);

        }

    }

    return ret;

}
