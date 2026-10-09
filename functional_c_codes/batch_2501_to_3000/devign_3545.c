/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3545
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f140e3000371e67ff4e00df3213e2d576d9c91be
 */

int nbd_client_co_preadv(BlockDriverState *bs, uint64_t offset,

                         uint64_t bytes, QEMUIOVector *qiov, int flags)

{

    NBDRequest request = {

        .type = NBD_CMD_READ,

        .from = offset,

        .len = bytes,

    };



    assert(bytes <= NBD_MAX_BUFFER_SIZE);

    assert(!flags);



    return nbd_co_request(bs, &request, qiov);

}
