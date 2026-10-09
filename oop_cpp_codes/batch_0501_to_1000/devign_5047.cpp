/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_5047
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8fcffa9853473ab148d36858f15c5531161a1824
 */

int qcow2_refcount_init(BlockDriverState *bs)

{

    BDRVQcowState *s = bs->opaque;

    unsigned int refcount_table_size2, i;

    int ret;



    assert(s->refcount_table_size <= INT_MAX / sizeof(uint64_t));

    refcount_table_size2 = s->refcount_table_size * sizeof(uint64_t);

    s->refcount_table = g_try_malloc(refcount_table_size2);



    if (s->refcount_table_size > 0) {

        if (s->refcount_table == NULL) {

            goto fail;

        }

        BLKDBG_EVENT(bs->file, BLKDBG_REFTABLE_LOAD);

        ret = bdrv_pread(bs->file, s->refcount_table_offset,

                         s->refcount_table, refcount_table_size2);

        if (ret != refcount_table_size2)

            goto fail;

        for(i = 0; i < s->refcount_table_size; i++)

            be64_to_cpus(&s->refcount_table[i]);

    }

    return 0;

 fail:

    return -ENOMEM;

}
