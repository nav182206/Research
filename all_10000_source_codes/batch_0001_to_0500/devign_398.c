/* 
 * Benchmark Sample ID : devign_398
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f798184cfdcb7f92a38c5f717d675bd75e1fd3ac
 */

int64_t bdrv_dirty_iter_next(BdrvDirtyBitmapIter *iter)

{

    return hbitmap_iter_next(&iter->hbi);

}
