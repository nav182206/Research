/* 
 * Benchmark Sample ID : devign_623
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8b3b720620a1137a1b794fc3ed64734236f94e06
 */

static int write_refcount_block_entries(BlockDriverState *bs,

    int64_t refcount_block_offset, int first_index, int last_index)

{

    BDRVQcowState *s = bs->opaque;

    size_t size;

    int ret;



    if (cache_refcount_updates) {

        return 0;

    }



    if (first_index < 0) {

        return 0;

    }



    first_index &= ~(REFCOUNTS_PER_SECTOR - 1);

    last_index = (last_index + REFCOUNTS_PER_SECTOR)

        & ~(REFCOUNTS_PER_SECTOR - 1);



    size = (last_index - first_index) << REFCOUNT_SHIFT;



    BLKDBG_EVENT(bs->file, BLKDBG_REFBLOCK_UPDATE_PART);

    ret = bdrv_pwrite(bs->file,

        refcount_block_offset + (first_index << REFCOUNT_SHIFT),

        &s->refcount_block_cache[first_index], size);

    if (ret < 0) {

        return ret;

    }



    return 0;

}
