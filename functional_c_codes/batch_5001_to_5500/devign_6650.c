/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6650
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1354c473789a91ba603d40bdf2521e3221c0a69f
 */

static bool raw_is_inserted(BlockDriverState *bs)

{

    return bdrv_is_inserted(bs->file->bs);

}
