/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_3449
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

static int64_t get_remaining_dirty(void)

{

    BlkMigDevState *bmds;

    int64_t dirty = 0;



    QSIMPLEQ_FOREACH(bmds, &block_mig_state.bmds_list, entry) {

        dirty += bdrv_get_dirty_count(bmds->bs, bmds->dirty_bitmap);

    }



    return dirty << BDRV_SECTOR_BITS;

}
