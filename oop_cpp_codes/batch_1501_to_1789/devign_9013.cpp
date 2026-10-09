/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_9013
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1c02e2a17104fe7fc11893125864dc0daf1e6d5b
 */

static int l2_load(BlockDriverState *bs, uint64_t l2_offset,

    uint64_t **l2_table)

{

    BDRVQcowState *s = bs->opaque;

    int min_index;

    int ret;



    /* seek if the table for the given offset is in the cache */



    *l2_table = seek_l2_table(s, l2_offset);

    if (*l2_table != NULL) {

        return 0;

    }



    /* not found: load a new entry in the least used one */



    min_index = l2_cache_new_entry(bs);

    *l2_table = s->l2_cache + (min_index << s->l2_bits);



    BLKDBG_EVENT(bs->file, BLKDBG_L2_LOAD);

    ret = bdrv_pread(bs->file, l2_offset, *l2_table,

        s->l2_size * sizeof(uint64_t));

    if (ret < 0) {


        return ret;

    }



    s->l2_cache_offsets[min_index] = l2_offset;

    s->l2_cache_counts[min_index] = 1;



    return 0;

}
