/* 
 * Benchmark Sample ID : devign_2966
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c9087c2a6068b23207517f7d7ff796e68290358b
 */

void signal_init(void)

{

    struct sigaction act;

    int i;



    /* set all host signal handlers. ALL signals are blocked during

       the handlers to serialize them. */

    sigfillset(&act.sa_mask);

    act.sa_flags = SA_SIGINFO;

    act.sa_sigaction = host_signal_handler;

    for(i = 1; i < NSIG; i++) {

	sigaction(i, &act, NULL);

    }

    

    memset(sigact_table, 0, sizeof(sigact_table));



    first_free = &sigqueue_table[0];

    for(i = 0; i < MAX_SIGQUEUE_SIZE - 1; i++) 

        sigqueue_table[i].next = &sigqueue_table[i + 1];

    sigqueue_table[MAX_SIGQUEUE_SIZE - 1].next = NULL;

}
