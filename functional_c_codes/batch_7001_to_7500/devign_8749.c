/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8749
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4534ff5426afeeae5238ba10a696cafa9a0168ee
 */

static int bdrv_qed_check(BlockDriverState *bs, BdrvCheckResult *result)

{

    BDRVQEDState *s = bs->opaque;



    return qed_check(s, result, false);

}
