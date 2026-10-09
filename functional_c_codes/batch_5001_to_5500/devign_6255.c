/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6255
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=acbe59829e448aa63bdccc6ee484b7e1ac605e25
 */

static int qcow2_check(BlockDriverState *bs, BdrvCheckResult *result,

                       BdrvCheckMode fix)

{

    return qcow2_check_refcounts(bs, result, fix);

}
