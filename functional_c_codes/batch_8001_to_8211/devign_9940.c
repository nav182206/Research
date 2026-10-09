/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9940
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=630530a6529bc3da9ab8aead7053dc753cb9ac77
 */

static int vmdk_is_allocated(BlockDriverState *bs, int64_t sector_num, 

                             int nb_sectors, int *pnum)

{

    BDRVVmdkState *s = bs->opaque;

    int index_in_cluster, n;

    uint64_t cluster_offset;



    cluster_offset = get_cluster_offset(bs, sector_num << 9, 0);

    index_in_cluster = sector_num % s->cluster_sectors;

    n = s->cluster_sectors - index_in_cluster;

    if (n > nb_sectors)

        n = nb_sectors;

    *pnum = n;

    return (cluster_offset != 0);

}
