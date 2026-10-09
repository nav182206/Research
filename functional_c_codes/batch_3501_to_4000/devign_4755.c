/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4755
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bd269ebc82fbaa5fe7ce5bc7c1770ac8acecd884
 */

SocketAddressLegacy *socket_local_address(int fd, Error **errp)

{

    struct sockaddr_storage ss;

    socklen_t sslen = sizeof(ss);



    if (getsockname(fd, (struct sockaddr *)&ss, &sslen) < 0) {

        error_setg_errno(errp, errno, "%s",

                         "Unable to query local socket address");

        return NULL;

    }



    return socket_sockaddr_to_address(&ss, sslen, errp);

}
