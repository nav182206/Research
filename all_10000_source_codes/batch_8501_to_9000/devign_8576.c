/* 
 * Benchmark Sample ID : devign_8576
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=db3bf8696358e105903b00432cad0aa50d3c0cb6
 */

static GThread *trace_thread_create(GThreadFunc fn)

{

    GThread *thread;

#ifndef _WIN32

    sigset_t set, oldset;



    sigfillset(&set);

    pthread_sigmask(SIG_SETMASK, &set, &oldset);

#endif

    thread = g_thread_create(writeout_thread, NULL, FALSE, NULL);

#ifndef _WIN32

    pthread_sigmask(SIG_SETMASK, &oldset, NULL);

#endif



    return thread;

}
