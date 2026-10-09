/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3339
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2f9606b3736c3be4dbd606c46525c7b770ced119
 */

static char *vnc_socket_local_addr(const char *format, int fd) {

    struct sockaddr_storage sa;

    socklen_t salen;



    salen = sizeof(sa);

    if (getsockname(fd, (struct sockaddr*)&sa, &salen) < 0)

        return NULL;



    return addr_to_string(format, &sa, salen);

}
