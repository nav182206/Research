/* 
 * Benchmark Sample ID : devign_4158
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9dc44aa5829eb3131a01378a738dee28a382bbc1
 */

static void *do_touch_pages(void *arg)

{

    MemsetThread *memset_args = (MemsetThread *)arg;

    char *addr = memset_args->addr;

    uint64_t numpages = memset_args->numpages;

    uint64_t hpagesize = memset_args->hpagesize;

    sigset_t set, oldset;

    int i = 0;



    /* unblock SIGBUS */

    sigemptyset(&set);

    sigaddset(&set, SIGBUS);

    pthread_sigmask(SIG_UNBLOCK, &set, &oldset);



    if (sigsetjmp(memset_args->env, 1)) {

        memset_thread_failed = true;

    } else {

        for (i = 0; i < numpages; i++) {

            memset(addr, 0, 1);

            addr += hpagesize;

        }

    }

    pthread_sigmask(SIG_SETMASK, &oldset, NULL);

    return NULL;

}
