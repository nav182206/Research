/* 
 * Benchmark Sample ID : devign_7758
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b7680cb6078bd7294a3dd86473d3f2fdee991dd0
 */

void qemu_thread_self(QemuThread *thread)

{

    thread->thread = pthread_self();

}
