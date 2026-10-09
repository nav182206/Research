/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_9509
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7439475e69f333541c3647f6b9eb5b5af073cb64
 */

int ff_listen_connect(int fd, const struct sockaddr *addr,

                      socklen_t addrlen, int timeout, URLContext *h,

                      int will_try_next)

{

    struct pollfd p = {fd, POLLOUT, 0};

    int ret;

    socklen_t optlen;



    ff_socket_nonblock(fd, 1);



    while ((ret = connect(fd, addr, addrlen))) {

        ret = ff_neterrno();

        switch (ret) {

        case AVERROR(EINTR):

            if (ff_check_interrupt(&h->interrupt_callback))

                return AVERROR_EXIT;

            continue;

        case AVERROR(EINPROGRESS):

        case AVERROR(EAGAIN):

            ret = ff_poll_interrupt(&p, 1, timeout, &h->interrupt_callback);

            if (ret < 0)

                return ret;

            optlen = sizeof(ret);

            if (getsockopt (fd, SOL_SOCKET, SO_ERROR, &ret, &optlen))

                ret = AVUNERROR(ff_neterrno());

            if (ret != 0) {

                char errbuf[100];

                ret = AVERROR(ret);

                av_strerror(ret, errbuf, sizeof(errbuf));

                if (will_try_next)

                    av_log(h, AV_LOG_WARNING,

                           "Connection to %s failed (%s), trying next address\n",

                           h->filename, errbuf);

                else

                    av_log(h, AV_LOG_ERROR, "Connection to %s failed: %s\n",

                           h->filename, errbuf);

            }

        default:

            return ret;

        }

    }

    return ret;

}
