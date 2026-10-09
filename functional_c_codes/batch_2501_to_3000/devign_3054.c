/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3054
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8b3b720620a1137a1b794fc3ed64734236f94e06
 */

static int write_refcount_block(BlockDriverState *bs)

{

    BDRVQcowState *s = bs->opaque;

    size_t size = s->cluster_size;



    if (s->refcount_block_cache_offset == 0) {

        return 0;

    }



    BLKDBG_EVENT(bs->file, BLKDBG_REFBLOCK_UPDATE);

    if (bdrv_pwrite(bs->file, s->refcount_block_cache_offset,

            s->refcount_block_cache, size) != size)

    {

        return -EIO;

    }



    return 0;

}
