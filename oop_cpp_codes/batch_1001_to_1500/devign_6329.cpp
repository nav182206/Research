/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_6329
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0e5d6327f3abb8d582cbc2e444a23ef0dc6a64c7
 */

qio_channel_socket_accept(QIOChannelSocket *ioc,

                          Error **errp)

{

    QIOChannelSocket *cioc;



    cioc = QIO_CHANNEL_SOCKET(object_new(TYPE_QIO_CHANNEL_SOCKET));

    cioc->fd = -1;

    cioc->remoteAddrLen = sizeof(ioc->remoteAddr);

    cioc->localAddrLen = sizeof(ioc->localAddr);



#ifdef WIN32

    QIO_CHANNEL(cioc)->event = CreateEvent(NULL, FALSE, FALSE, NULL);

#endif





 retry:

    trace_qio_channel_socket_accept(ioc);

    cioc->fd = qemu_accept(ioc->fd, (struct sockaddr *)&cioc->remoteAddr,

                           &cioc->remoteAddrLen);

    if (cioc->fd < 0) {

        trace_qio_channel_socket_accept_fail(ioc);

        if (errno == EINTR) {

            goto retry;

        }

        goto error;

    }



    if (getsockname(cioc->fd, (struct sockaddr *)&cioc->localAddr,

                    &cioc->localAddrLen) < 0) {

        error_setg_errno(errp, errno,

                         "Unable to query local socket address");

        goto error;

    }



#ifndef WIN32

    if (cioc->localAddr.ss_family == AF_UNIX) {

        QIOChannel *ioc_local = QIO_CHANNEL(cioc);

        qio_channel_set_feature(ioc_local, QIO_CHANNEL_FEATURE_FD_PASS);

    }

#endif /* WIN32 */



    trace_qio_channel_socket_accept_complete(ioc, cioc, cioc->fd);

    return cioc;



 error:

    object_unref(OBJECT(cioc));

    return NULL;

}
