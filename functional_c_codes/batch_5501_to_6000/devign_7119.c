/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7119
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9be385980d37e8f4fd33f605f5fb1c3d144170a8
 */

int block_signals(void)

{

    TaskState *ts = (TaskState *)thread_cpu->opaque;

    sigset_t set;

    int pending;



    /* It's OK to block everything including SIGSEGV, because we won't

     * run any further guest code before unblocking signals in

     * process_pending_signals().

     */

    sigfillset(&set);

    sigprocmask(SIG_SETMASK, &set, 0);



    pending = atomic_xchg(&ts->signal_pending, 1);



    return pending;

}
