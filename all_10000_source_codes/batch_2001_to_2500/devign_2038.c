/* 
 * Benchmark Sample ID : devign_2038
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d85f4222b4681da7ebf8a90b26e085a68fa2c55a
 */

static void qcow_close(BlockDriverState *bs)

{

    BDRVQcowState *s = bs->opaque;



    qcrypto_cipher_free(s->cipher);

    s->cipher = NULL;

    g_free(s->l1_table);

    qemu_vfree(s->l2_cache);

    g_free(s->cluster_cache);

    g_free(s->cluster_data);



    migrate_del_blocker(s->migration_blocker);

    error_free(s->migration_blocker);

}
