/* 
 * Benchmark Sample ID : devign_367
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7860a380ac2a9fd09a6e8f31fd9db5318fc91285
 */

static void nbd_accept(void *opaque)

{

    int server_fd = (uintptr_t) opaque;

    struct sockaddr_in addr;

    socklen_t addr_len = sizeof(addr);



    int fd = accept(server_fd, (struct sockaddr *)&addr, &addr_len);

    nbd_started = true;

    if (fd >= 0 && nbd_client_new(exp, fd, nbd_client_closed)) {

        nb_fds++;

    }

}
