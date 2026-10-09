/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8827
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e1123a3b40a1a9a625a29c8ed4debb7e206ea690
 */

static void iscsi_allocationmap_clear(IscsiLun *iscsilun, int64_t sector_num,

                                      int nb_sectors)

{

    int64_t cluster_num, nb_clusters;

    if (iscsilun->allocationmap == NULL) {

        return;

    }

    cluster_num = DIV_ROUND_UP(sector_num, iscsilun->cluster_sectors);

    nb_clusters = (sector_num + nb_sectors) / iscsilun->cluster_sectors

                  - cluster_num;

    if (nb_clusters > 0) {

        bitmap_clear(iscsilun->allocationmap, cluster_num, nb_clusters);

    }

}
