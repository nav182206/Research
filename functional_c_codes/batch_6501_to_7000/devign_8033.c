/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8033
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=61007b316cd71ee7333ff7a0a749a8949527575f
 */

int bdrv_key_required(BlockDriverState *bs)

{

    BlockDriverState *backing_hd = bs->backing_hd;



    if (backing_hd && backing_hd->encrypted && !backing_hd->valid_key)

        return 1;

    return (bs->encrypted && !bs->valid_key);

}
