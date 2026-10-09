/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2711
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d32fcad366e5f45d33dab2ee4de0e5729439680b
 */

static ssize_t nc_sendv_compat(NetClientState *nc, const struct iovec *iov,

                               int iovcnt)

{

    uint8_t buffer[4096];

    size_t offset;



    offset = iov_to_buf(iov, iovcnt, 0, buffer, sizeof(buffer));



    return nc->info->receive(nc, buffer, offset);

}
