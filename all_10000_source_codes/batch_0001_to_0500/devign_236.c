/* 
 * Benchmark Sample ID : devign_236
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d0cc2fbfa607678866475383c508be84818ceb64
 */

int event_notifier_get_fd(EventNotifier *e)

{

    return e->fd;

}
