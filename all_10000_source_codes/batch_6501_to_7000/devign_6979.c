/* 
 * Benchmark Sample ID : devign_6979
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=fbcad04d6bfdff937536eb23088a01a280a1a3af
 */

static int raw_truncate(BlockDriverState *bs, int64_t offset)

{

    BDRVRawState *s = bs->opaque;

    LONG low, high;



    low = offset;

    high = offset >> 32;

    if (!SetFilePointer(s->hfile, low, &high, FILE_BEGIN))

	return -EIO;

    if (!SetEndOfFile(s->hfile))

        return -EIO;

    return 0;

}
