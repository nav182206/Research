/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_9007
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

static void unset_dirty_tracking(void)

{

    BlkMigDevState *bmds;



    QSIMPLEQ_FOREACH(bmds, &block_mig_state.bmds_list, entry) {

        bdrv_release_dirty_bitmap(bmds->bs, bmds->dirty_bitmap);

    }

}
