/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4337
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=537b41f5013e1951fa15e8f18855b18d76124ce4
 */

int tcp_socket_incoming(const char *address, uint16_t port)

{

    char address_and_port[128];

    Error *local_err = NULL;



    combine_addr(address_and_port, 128, address, port);

    int fd = inet_listen(address_and_port, NULL, 0, SOCK_STREAM, 0, &local_err);



    if (local_err != NULL) {

        qerror_report_err(local_err);

        error_free(local_err);

    }

    return fd;

}
