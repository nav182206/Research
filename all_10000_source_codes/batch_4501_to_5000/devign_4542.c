/* 
 * Benchmark Sample ID : devign_4542
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=68a9398261ca38979bbc2b7c89ed5bb044ccc9e6
 */

static void qemu_thread_set_name(QemuThread *thread, const char *name)

{

#ifdef CONFIG_PTHREAD_SETNAME_NP

    pthread_setname_np(thread->thread, name);

#endif

}
