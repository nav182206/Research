/* 
 * Benchmark Sample ID : devign_4904
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=dfd100f242370886bb6732f70f1f7cbd8eb9fedc
 */

int qio_channel_socket_listen_sync(QIOChannelSocket *ioc,

                                   SocketAddress *addr,

                                   Error **errp)

{

    int fd;



    trace_qio_channel_socket_listen_sync(ioc, addr);

    fd = socket_listen(addr, errp);

    if (fd < 0) {

        trace_qio_channel_socket_listen_fail(ioc);

        return -1;

    }



    trace_qio_channel_socket_listen_complete(ioc, fd);

    if (qio_channel_socket_set_fd(ioc, fd, errp) < 0) {

        close(fd);

        return -1;

    }

    qio_channel_set_feature(QIO_CHANNEL(ioc), QIO_CHANNEL_FEATURE_LISTEN);



    return 0;

}
