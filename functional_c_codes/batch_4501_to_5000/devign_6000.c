/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6000
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=61007b316cd71ee7333ff7a0a749a8949527575f
 */

void bdrv_set_enable_write_cache(BlockDriverState *bs, bool wce)

{

    bs->enable_write_cache = wce;



    /* so a reopen() will preserve wce */

    if (wce) {

        bs->open_flags |= BDRV_O_CACHE_WB;

    } else {

        bs->open_flags &= ~BDRV_O_CACHE_WB;

    }

}
