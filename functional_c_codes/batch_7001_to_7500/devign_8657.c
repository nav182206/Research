/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8657
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ce960aa9062a407d0ca15aee3dcd3bd84a4e24f9
 */

static int coroutine_fn bdrv_mirror_top_flush(BlockDriverState *bs)

{





    return bdrv_co_flush(bs->backing->bs);
