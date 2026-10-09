/* 
 * Benchmark Sample ID : devign_2778
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=792773b2255d25c6f5fe9dfa0ae200debab92de4
 */

static void init_blk_migration(Monitor *mon, QEMUFile *f)

{

    BlkMigDevState *bmds;

    BlockDriverState *bs;



    block_mig_state.submitted = 0;

    block_mig_state.read_done = 0;

    block_mig_state.transferred = 0;

    block_mig_state.total_sector_sum = 0;

    block_mig_state.prev_progress = -1;



    for (bs = bdrv_first; bs != NULL; bs = bs->next) {

        if (bs->type == BDRV_TYPE_HD) {

            bmds = qemu_mallocz(sizeof(BlkMigDevState));

            bmds->bs = bs;

            bmds->bulk_completed = 0;

            bmds->total_sectors = bdrv_getlength(bs) >> BDRV_SECTOR_BITS;

            bmds->completed_sectors = 0;

            bmds->shared_base = block_mig_state.shared_base;



            block_mig_state.total_sector_sum += bmds->total_sectors;



            if (bmds->shared_base) {

                monitor_printf(mon, "Start migration for %s with shared base "

                                    "image\n",

                               bs->device_name);

            } else {

                monitor_printf(mon, "Start full migration for %s\n",

                               bs->device_name);

            }



            QSIMPLEQ_INSERT_TAIL(&block_mig_state.bmds_list, bmds, entry);

        }

    }

}
