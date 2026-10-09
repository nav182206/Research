/* 
 * Benchmark Sample ID : devign_951
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e97fc193e1c65deb51643d5251e98affe07c59ca
 */

static void inc_refcounts(BlockDriverState *bs,

                          uint16_t *refcount_table,

                          int refcount_table_size,

                          int64_t offset, int64_t size)

{

    BDRVQcowState *s = bs->opaque;

    int64_t start, last, cluster_offset;

    int k;



    if (size <= 0)

        return;



    start = offset & ~(s->cluster_size - 1);

    last = (offset + size - 1) & ~(s->cluster_size - 1);

    for(cluster_offset = start; cluster_offset <= last;

        cluster_offset += s->cluster_size) {

        k = cluster_offset >> s->cluster_bits;

        if (k < 0 || k >= refcount_table_size) {

            fprintf(stderr, "ERROR: invalid cluster offset=0x%" PRIx64 "\n",

                cluster_offset);

        } else {

            if (++refcount_table[k] == 0) {

                fprintf(stderr, "ERROR: overflow cluster offset=0x%" PRIx64

                    "\n", cluster_offset);

            }

        }

    }

}
