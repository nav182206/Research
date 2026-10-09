/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2157
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a5b8dd2ce83208cd7d6eb4562339ecf5aae13574
 */

static void vvfat_refresh_limits(BlockDriverState *bs, Error **errp)

{

    bs->request_alignment = BDRV_SECTOR_SIZE; /* No sub-sector I/O supported */

}
