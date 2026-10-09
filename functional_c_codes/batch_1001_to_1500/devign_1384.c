/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1384
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ebba2b3e2a551ce638d17332761431ba748f178f
 */

static int udp_write(URLContext *h, const uint8_t *buf, int size)

{

    UDPContext *s = h->priv_data;

    int ret;



    for(;;) {

        if (!s->is_connected) {

            ret = sendto (s->udp_fd, buf, size, 0,

                          (struct sockaddr *) &s->dest_addr,

                          s->dest_addr_len);

        } else

            ret = send(s->udp_fd, buf, size, 0);

        if (ret < 0) {

            if (ff_neterrno() != AVERROR(EINTR) &&

                ff_neterrno() != AVERROR(EAGAIN))

                return ff_neterrno();

        } else {

            break;

        }

    }

    return size;

}
