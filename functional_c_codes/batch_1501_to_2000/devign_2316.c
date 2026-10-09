/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2316
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2e6fc7eb1a4af1b127df5f07b8bb28af891946fa
 */

static void raw_eject(BlockDriverState *bs, bool eject_flag)

{

    bdrv_eject(bs->file->bs, eject_flag);

}
