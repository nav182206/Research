/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9264
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=47f9f15831faa549504ab9b035aaea44a02e5f95
 */

static ssize_t nc_sendv_compat(NetClientState *nc, const struct iovec *iov,

                               int iovcnt, unsigned flags)

{

    uint8_t *buf = NULL;

    uint8_t *buffer;

    size_t offset;

    ssize_t ret;



    if (iovcnt == 1) {

        buffer = iov[0].iov_base;

        offset = iov[0].iov_len;

    } else {

        buf = g_new(uint8_t, NET_BUFSIZE);

        buffer = buf;

        offset = iov_to_buf(iov, iovcnt, 0, buf, NET_BUFSIZE);

    }



    if (flags & QEMU_NET_PACKET_FLAG_RAW && nc->info->receive_raw) {

        ret = nc->info->receive_raw(nc, buffer, offset);

    } else {

        ret = nc->info->receive(nc, buffer, offset);

    }



    g_free(buf);

    return ret;

}
