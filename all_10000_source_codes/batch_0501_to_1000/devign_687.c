/* 
 * Benchmark Sample ID : devign_687
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=233aa5c2d1cf4655ffe335025a68cf5454f87dad
 */

int inet_connect(const char *str, Error **errp)

{

    QemuOpts *opts;

    int sock = -1;



    opts = qemu_opts_create(&dummy_opts, NULL, 0, NULL);

    if (inet_parse(opts, str) == 0) {

        sock = inet_connect_opts(opts, true, NULL, errp);

    } else {

        error_set(errp, QERR_SOCKET_CREATE_FAILED);

    }

    qemu_opts_del(opts);

    return sock;

}
