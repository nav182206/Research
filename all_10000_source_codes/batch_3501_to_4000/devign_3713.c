/* 
 * Benchmark Sample ID : devign_3713
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=77e8b9ca64e85d3d309f322410964b7852ec091e
 */

int tcp_socket_outgoing_opts(QemuOpts *opts)

{

    Error *local_err = NULL;

    int fd = inet_connect_opts(opts, &local_err, NULL, NULL);

    if (local_err != NULL) {

        qerror_report_err(local_err);

        error_free(local_err);

    }



    return fd;

}
