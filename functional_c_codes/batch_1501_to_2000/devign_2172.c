/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2172
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bd269ebc82fbaa5fe7ce5bc7c1770ac8acecd884
 */

int qio_channel_socket_connect_sync(QIOChannelSocket *ioc,

                                    SocketAddressLegacy *addr,

                                    Error **errp)

{

    int fd;



    trace_qio_channel_socket_connect_sync(ioc, addr);

    fd = socket_connect(addr, NULL, NULL, errp);

    if (fd < 0) {

        trace_qio_channel_socket_connect_fail(ioc);

        return -1;

    }



    trace_qio_channel_socket_connect_complete(ioc, fd);

    if (qio_channel_socket_set_fd(ioc, fd, errp) < 0) {

        close(fd);

        return -1;

    }



    return 0;

}
