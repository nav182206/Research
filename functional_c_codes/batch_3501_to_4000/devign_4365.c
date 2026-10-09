/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4365
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=de82815db1c89da058b7fb941dab137d6d9ab738
 */

static void qcow2_close(BlockDriverState *bs)

{

    BDRVQcowState *s = bs->opaque;

    g_free(s->l1_table);

    /* else pre-write overlap checks in cache_destroy may crash */

    s->l1_table = NULL;



    if (!(bs->open_flags & BDRV_O_INCOMING)) {

        qcow2_cache_flush(bs, s->l2_table_cache);

        qcow2_cache_flush(bs, s->refcount_block_cache);



        qcow2_mark_clean(bs);

    }



    qcow2_cache_destroy(bs, s->l2_table_cache);

    qcow2_cache_destroy(bs, s->refcount_block_cache);



    g_free(s->unknown_header_fields);

    cleanup_unknown_header_ext(bs);



    g_free(s->cluster_cache);

    qemu_vfree(s->cluster_data);

    qcow2_refcount_close(bs);

    qcow2_free_snapshots(bs);

}
