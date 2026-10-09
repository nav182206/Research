/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7707
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=96165b9eb4207a34a87c46df731d3cc42c052e13
 */

static int gdbserver_open(int port)

{

    struct sockaddr_in sockaddr;

    int fd, ret;



    fd = socket(PF_INET, SOCK_STREAM, 0);

    if (fd < 0) {

        perror("socket");

        return -1;

    }

#ifndef _WIN32

    fcntl(fd, F_SETFD, FD_CLOEXEC);

#endif



    socket_set_fast_reuse(fd);



    sockaddr.sin_family = AF_INET;

    sockaddr.sin_port = htons(port);

    sockaddr.sin_addr.s_addr = 0;

    ret = bind(fd, (struct sockaddr *)&sockaddr, sizeof(sockaddr));

    if (ret < 0) {

        perror("bind");

        close(fd);

        return -1;

    }

    ret = listen(fd, 0);

    if (ret < 0) {

        perror("listen");

        close(fd);

        return -1;

    }

    return fd;

}
