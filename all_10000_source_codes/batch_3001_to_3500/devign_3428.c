/* 
 * Benchmark Sample ID : devign_3428
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f53a829bb9ef14be800556cbc02d8b20fc1050a7
 */

int nbd_client_session_co_readv(NbdClientSession *client, int64_t sector_num,

    int nb_sectors, QEMUIOVector *qiov)

{

    int offset = 0;

    int ret;

    while (nb_sectors > NBD_MAX_SECTORS) {

        ret = nbd_co_readv_1(client, sector_num,

                             NBD_MAX_SECTORS, qiov, offset);

        if (ret < 0) {

            return ret;

        }

        offset += NBD_MAX_SECTORS * 512;

        sector_num += NBD_MAX_SECTORS;

        nb_sectors -= NBD_MAX_SECTORS;

    }

    return nbd_co_readv_1(client, sector_num, nb_sectors, qiov, offset);

}
