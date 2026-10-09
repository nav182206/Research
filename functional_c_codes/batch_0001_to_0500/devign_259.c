/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_259
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3d948cdf3760b52238038626a7ffa7d30913060b
 */

static BlockJob *find_block_job(const char *device)

{

    BlockDriverState *bs;



    bs = bdrv_find(device);

    if (!bs || !bs->job) {

        return NULL;

    }

    return bs->job;

}
