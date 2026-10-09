/* 
 * Benchmark Sample ID : devign_9633
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e976c6a1e40ad74d616a186d3b48b0ad8f5eb970
 */

static int qcow_write(BlockDriverState *bs, int64_t sector_num,

                     const uint8_t *buf, int nb_sectors)

{

    BDRVQcowState *s = bs->opaque;

    int ret, index_in_cluster, n;

    uint64_t cluster_offset;

    int n_end;



    while (nb_sectors > 0) {

        index_in_cluster = sector_num & (s->cluster_sectors - 1);

        n_end = index_in_cluster + nb_sectors;

        if (s->crypt_method &&

            n_end > QCOW_MAX_CRYPT_CLUSTERS * s->cluster_sectors)

            n_end = QCOW_MAX_CRYPT_CLUSTERS * s->cluster_sectors;

        cluster_offset = alloc_cluster_offset(bs, sector_num << 9,

                                              index_in_cluster,

                                              n_end, &n);

        if (!cluster_offset)

            return -1;

        if (s->crypt_method) {

            encrypt_sectors(s, sector_num, s->cluster_data, buf, n, 1,

                            &s->aes_encrypt_key);

            ret = bdrv_pwrite(s->hd, cluster_offset + index_in_cluster * 512,

                              s->cluster_data, n * 512);

        } else {

            ret = bdrv_pwrite(s->hd, cluster_offset + index_in_cluster * 512, buf, n * 512);

        }

        if (ret != n * 512)

            return -1;

        nb_sectors -= n;

        sector_num += n;

        buf += n * 512;

    }

    s->cluster_cache_offset = -1; /* disable compressed cache */

    return 0;

}
