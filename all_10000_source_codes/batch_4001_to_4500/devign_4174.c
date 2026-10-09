/* 
 * Benchmark Sample ID : devign_4174
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f5e717f3c735af5c941b458d42615c97028aa916
 */

static int socket_open_listen(struct sockaddr_in *my_addr)

{

    int server_fd, tmp;



    server_fd = socket(AF_INET,SOCK_STREAM,0);

    if (server_fd < 0) {

        perror ("socket");

        return -1;

    }



    tmp = 1;

    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &tmp, sizeof(tmp));




    if (bind (server_fd, (struct sockaddr *) my_addr, sizeof (*my_addr)) < 0) {

        char bindmsg[32];

        snprintf(bindmsg, sizeof(bindmsg), "bind(port %d)", ntohs(my_addr->sin_port));

        perror (bindmsg);

        closesocket(server_fd);

        return -1;

    }



    if (listen (server_fd, 5) < 0) {

        perror ("listen");

        closesocket(server_fd);

        return -1;

    }

    ff_socket_nonblock(server_fd, 1);



    return server_fd;

}
