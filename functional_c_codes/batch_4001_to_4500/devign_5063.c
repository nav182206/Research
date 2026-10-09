/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5063
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9ee0cb201e6bfe03549a649fd165a85cfed34d05
 */

static int block_save_complete(QEMUFile *f, void *opaque)

{

    int ret;



    DPRINTF("Enter save live complete submitted %d transferred %d\n",

            block_mig_state.submitted, block_mig_state.transferred);



    ret = flush_blks(f);

    if (ret) {

        blk_mig_cleanup();

        return ret;

    }



    blk_mig_reset_dirty_cursor();



    /* we know for sure that save bulk is completed and

       all async read completed */

    assert(block_mig_state.submitted == 0);



    do {

        ret = blk_mig_save_dirty_block(f, 0);

    } while (ret == 0);



    blk_mig_cleanup();

    if (ret) {

        return ret;

    }

    /* report completion */

    qemu_put_be64(f, (100 << BDRV_SECTOR_BITS) | BLK_MIG_FLAG_PROGRESS);



    DPRINTF("Block migration completed\n");



    qemu_put_be64(f, BLK_MIG_FLAG_EOS);



    return 0;

}
