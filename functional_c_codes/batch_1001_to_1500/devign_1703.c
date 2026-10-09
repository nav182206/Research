/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1703
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=537b41f5013e1951fa15e8f18855b18d76124ce4
 */

int unix_socket_outgoing(const char *path)

{

    Error *local_err = NULL;

    int fd = unix_connect(path, &local_err);



    if (local_err != NULL) {

        qerror_report_err(local_err);

        error_free(local_err);

    }

    return fd;

}
