/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2318
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7439475e69f333541c3647f6b9eb5b5af073cb64
 */

int ff_listen_bind(int fd, const struct sockaddr *addr,

                   socklen_t addrlen, int timeout, URLContext *h)

{

    int ret;

    int reuse = 1;

    struct pollfd lp = { fd, POLLIN, 0 };

    if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse))) {

        av_log(NULL, AV_LOG_WARNING, "setsockopt(SO_REUSEADDR) failed\n");

    }

    ret = bind(fd, addr, addrlen);

    if (ret)

        return ff_neterrno();



    ret = listen(fd, 1);

    if (ret)

        return ff_neterrno();



    ret = ff_poll_interrupt(&lp, 1, timeout, &h->interrupt_callback);

    if (ret < 0)

        return ret;



    ret = accept(fd, NULL, NULL);

    if (ret < 0)

        return ff_neterrno();



    closesocket(fd);



    ff_socket_nonblock(ret, 1);

    return ret;

}
