/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3278
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=dc8764f06155a7b3e635e02281b747a9e292127e
 */

static gboolean register_signal_handlers(void)

{

    struct sigaction sigact, sigact_chld;

    int ret;



    memset(&sigact, 0, sizeof(struct sigaction));

    sigact.sa_handler = quit_handler;



    ret = sigaction(SIGINT, &sigact, NULL);

    if (ret == -1) {

        g_error("error configuring signal handler: %s", strerror(errno));

        return false;

    }

    ret = sigaction(SIGTERM, &sigact, NULL);

    if (ret == -1) {

        g_error("error configuring signal handler: %s", strerror(errno));

        return false;

    }



    memset(&sigact_chld, 0, sizeof(struct sigaction));

    sigact_chld.sa_handler = child_handler;

    sigact_chld.sa_flags = SA_NOCLDSTOP;

    ret = sigaction(SIGCHLD, &sigact_chld, NULL);

    if (ret == -1) {

        g_error("error configuring signal handler: %s", strerror(errno));

    }



    return true;

}
