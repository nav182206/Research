/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_4795
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=bb572aefbdac290363bfa5ca0e810ccce0a14ed6
 */

static int64_t alloc_clusters_noref(BlockDriverState *bs, int64_t size)

{

    BDRVQcowState *s = bs->opaque;

    int i, nb_clusters, refcount;



    nb_clusters = size_to_clusters(s, size);

retry:

    for(i = 0; i < nb_clusters; i++) {

        int64_t next_cluster_index = s->free_cluster_index++;

        refcount = get_refcount(bs, next_cluster_index);



        if (refcount < 0) {

            return refcount;

        } else if (refcount != 0) {

            goto retry;

        }

    }

#ifdef DEBUG_ALLOC2

    fprintf(stderr, "alloc_clusters: size=%" PRId64 " -> %" PRId64 "\n",

            size,

            (s->free_cluster_index - nb_clusters) << s->cluster_bits);

#endif

    return (s->free_cluster_index - nb_clusters) << s->cluster_bits;

}
