/* 
 * Benchmark Sample ID : devign_5127
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9732baf67850dac57dfc7dc8980bf408889a8973
 */

static void test_server_free(TestServer *server)

{

    int i;



    qemu_chr_delete(server->chr);



    for (i = 0; i < server->fds_num; i++) {

        close(server->fds[i]);

    }



    if (server->log_fd != -1) {

        close(server->log_fd);

    }



    unlink(server->socket_path);

    g_free(server->socket_path);





    g_free(server->chr_name);

    g_free(server);

}
