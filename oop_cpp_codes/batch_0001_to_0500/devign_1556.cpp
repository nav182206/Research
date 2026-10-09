/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_1556
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2b584959ed300ddff4acba0d7554becad5f274fd
 */

void bdrv_set_geometry_hint(BlockDriverState *bs,

                            int cyls, int heads, int secs)

{

    bs->cyls = cyls;

    bs->heads = heads;

    bs->secs = secs;

}
