/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9102
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=369f7de9d57e4dd2f312255fc12271d5749c0a4e
 */

static void parallels_close(BlockDriverState *bs)

{

    BDRVParallelsState *s = bs->opaque;

    g_free(s->catalog_bitmap);

}
