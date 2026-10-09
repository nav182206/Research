/* 
 * Benchmark Sample ID : devign_1555
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b6d36def6d9e9fd187327182d0abafc9b7085d8f
 */

static int count_contiguous_free_clusters(uint64_t nb_clusters, uint64_t *l2_table)

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
