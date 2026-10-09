/* 
 * Benchmark Sample ID : devign_670
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b3c0bfb6f949d8f1c97f390f951c0bab3e703810
 */

static void vmdk_free_extents(BlockDriverState *bs)

{

    int i;

    BDRVVmdkState *s = bs->opaque;



    for (i = 0; i < s->num_extents; i++) {

        g_free(s->extents[i].l1_table);

        g_free(s->extents[i].l2_cache);

        g_free(s->extents[i].l1_backup_table);

    }

    g_free(s->extents);

}
