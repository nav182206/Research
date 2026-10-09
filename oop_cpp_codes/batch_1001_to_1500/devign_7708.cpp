/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_7708
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2b584959ed300ddff4acba0d7554becad5f274fd
 */

void bdrv_get_geometry_hint(BlockDriverState *bs,

                            int *pcyls, int *pheads, int *psecs)

{

    *pcyls = bs->cyls;

    *pheads = bs->heads;

    *psecs = bs->secs;

}
