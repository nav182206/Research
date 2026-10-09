/* 
 * Benchmark Sample ID : devign_9682
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=233aa5c2d1cf4655ffe335025a68cf5454f87dad
 */

int inet_connect_opts(QemuOpts *opts, bool block, bool *in_progress,

                      Error **errp)

{

    struct addrinfo *res, *e;

    int sock = -1;



    res = inet_parse_connect_opts(opts, errp);

    if (!res) {

        return -1;

    }



    if (in_progress) {

        *in_progress = false;

    }



    for (e = res; e != NULL; e = e->ai_next) {

        sock = inet_connect_addr(e, block, in_progress);

        if (sock >= 0) {

            break;

        }

    }

    if (sock < 0) {

        error_set(errp, QERR_SOCKET_CONNECT_FAILED);

    }

    freeaddrinfo(res);

    return sock;

}
