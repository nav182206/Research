/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_4141
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=630530a6529bc3da9ab8aead7053dc753cb9ac77
 */

static int vmdk_write(BlockDriverState *bs, int64_t sector_num, 

                     const uint8_t *buf, int nb_sectors)

{

    BDRVVmdkState *s = bs->opaque;

    int index_in_cluster, n;

    uint64_t cluster_offset;

    static int cid_update = 0;



    while (nb_sectors > 0) {

        index_in_cluster = sector_num & (s->cluster_sectors - 1);

        n = s->cluster_sectors - index_in_cluster;

        if (n > nb_sectors)

            n = nb_sectors;

        cluster_offset = get_cluster_offset(bs, sector_num << 9, 1);

        if (!cluster_offset)

            return -1;

        if (bdrv_pwrite(s->hd, cluster_offset + index_in_cluster * 512, buf, n * 512) != n * 512)

            return -1;

        nb_sectors -= n;

        sector_num += n;

        buf += n * 512;



        // update CID on the first write every time the virtual disk is opened

        if (!cid_update) {

            vmdk_write_cid(bs, time(NULL));

            cid_update++;

        }

    }

    return 0;

}
