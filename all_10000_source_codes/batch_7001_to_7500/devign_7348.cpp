/* 
 * Benchmark Sample ID : devign_7348
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

static void blk_mig_reset_dirty_cursor(void)

{

    BlkMigDevState *bmds;



    QSIMPLEQ_FOREACH(bmds, &block_mig_state.bmds_list, entry) {

        bmds->cur_dirty = 0;

    }

}
