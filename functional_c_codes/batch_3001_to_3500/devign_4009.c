/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4009
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=02a08fef079469c005d48fe2d181f0e0eb5752ae
 */

int inet_connect(const char *str, bool block, Error **errp)

{

    QemuOpts *opts;

    int sock = -1;



    opts = qemu_opts_create(&dummy_opts, NULL, 0, NULL);

    if (inet_parse(opts, str) == 0) {

        if (block) {

            qemu_opt_set(opts, "block", "on");

        }

        sock = inet_connect_opts(opts, errp);

    } else {

        error_set(errp, QERR_SOCKET_CREATE_FAILED);

    }

    qemu_opts_del(opts);

    return sock;

}
