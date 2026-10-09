/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6711
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9d9474726274d0e1c420f055849a0e3058cad0e4
 */

int unix_connect_opts(QemuOpts *opts)

{

    struct sockaddr_un un;

    const char *path = qemu_opt_get(opts, "path");

    int sock;



    if (NULL == path) {

        fprintf(stderr, "unix connect: no path specified\n");

        return -1;

    }



    sock = qemu_socket(PF_UNIX, SOCK_STREAM, 0);

    if (sock < 0) {

        perror("socket(unix)");

        return -1;

    }



    memset(&un, 0, sizeof(un));

    un.sun_family = AF_UNIX;

    snprintf(un.sun_path, sizeof(un.sun_path), "%s", path);

    if (connect(sock, (struct sockaddr*) &un, sizeof(un)) < 0) {

        fprintf(stderr, "connect(unix:%s): %s\n", path, strerror(errno));


	return -1;

    }



    if (sockets_debug)

        fprintf(stderr, "connect(unix:%s): OK\n", path);

    return sock;

}
