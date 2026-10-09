/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8106
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b9f7855a50a7cbf04454fa84e9d1f333151f2259
 */

static int sector_limits_lun2qemu(int64_t sector, IscsiLun *iscsilun)

{

    int limit = MIN(sector_lun2qemu(sector, iscsilun), INT_MAX / 2 + 1);



    return limit < BDRV_REQUEST_MAX_SECTORS ? limit : 0;

}
