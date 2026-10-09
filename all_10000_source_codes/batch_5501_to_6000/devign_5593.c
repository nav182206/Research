/* 
 * Benchmark Sample ID : devign_5593
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a99dfb45f26bface6830ee5465e57bcdbc53c6c8
 */

static int count_contiguous_free_clusters(int nb_clusters, uint64_t *l2_table)

{

    int i;



    for (i = 0; i < nb_clusters; i++) {

        int type = qcow2_get_cluster_type(be64_to_cpu(l2_table[i]));



        if (type != QCOW2_CLUSTER_UNALLOCATED) {

            break;

        }

    }



    return i;

}
