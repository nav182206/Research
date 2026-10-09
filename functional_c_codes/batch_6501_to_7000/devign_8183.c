/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8183
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=fdd26fca3ce66863e547560fbde1a444fc5d71b7
 */

void qtest_quit(QTestState *s)

{

    int status;



    pid_t pid = qtest_qemu_pid(s);

    if (pid != -1) {

        kill(pid, SIGTERM);

        waitpid(pid, &status, 0);

    }






    unlink(s->pid_file);

    unlink(s->socket_path);

    unlink(s->qmp_socket_path);

    g_free(s->pid_file);

    g_free(s->socket_path);

    g_free(s->qmp_socket_path);


}
