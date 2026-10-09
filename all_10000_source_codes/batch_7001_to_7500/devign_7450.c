/* 
 * Benchmark Sample ID : devign_7450
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5efdf53227809a0da436dd63d7ed19c99044ecbd
 */

static bool is_zero_cluster(BlockDriverState *bs, int64_t start)

{

    BDRVQcow2State *s = bs->opaque;

    int nr;

    BlockDriverState *file;

    int64_t res = bdrv_get_block_status_above(bs, NULL, start,

                                              s->cluster_sectors, &nr, &file);

    return res >= 0 && (res & BDRV_BLOCK_ZERO);

}
