/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_620
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

uint64_t blk_mig_bytes_total(void)

{

    BlkMigDevState *bmds;

    uint64_t sum = 0;



    QSIMPLEQ_FOREACH(bmds, &block_mig_state.bmds_list, entry) {

        sum += bmds->total_sectors;

    }

    return sum << BDRV_SECTOR_BITS;

}
