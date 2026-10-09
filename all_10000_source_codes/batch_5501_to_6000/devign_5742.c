/* 
 * Benchmark Sample ID : devign_5742
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=12d4536f7d911b6d87a766ad7300482ea663cea2
 */

static void qemu_tcg_init_cpu_signals(void)

{

#ifdef CONFIG_IOTHREAD

    sigset_t set;

    struct sigaction sigact;



    memset(&sigact, 0, sizeof(sigact));

    sigact.sa_handler = cpu_signal;

    sigaction(SIG_IPI, &sigact, NULL);



    sigemptyset(&set);

    sigaddset(&set, SIG_IPI);

    pthread_sigmask(SIG_UNBLOCK, &set, NULL);

#endif

}
