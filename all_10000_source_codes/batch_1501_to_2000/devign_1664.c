/* 
 * Benchmark Sample ID : devign_1664
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9ac228e02cf16202547e7025ef300369e0db7781
 */

static int qcow_check(BlockDriverState *bs)

{

    return qcow2_check_refcounts(bs);

}
